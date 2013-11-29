use <../external/lego_compatibility.scad> 

include <settings.scad>

//sizes taken from the stepper28BYJ datasheet
//just 3 circles where the hole are supposed to be
//we move them around a bit to
module stepper_holder(){
        for(i=[-2:4]){
                translate([0,8 +i,0]) circle(r=4.5);// the hole for the gear(not used in this design
                translate([17.5,i,0]) circle(r=2.4);//left hole for the nut
                translate([-17.5,i,0]) circle(r=2.4);//right hole for the nut
                translate([0,i,0]) circle(r=14);//size of the inner circle
        }
}

module stepper_mount() {
        linear_extrude(height=3) translate ([0,8,0]) rotate([0,0,180]) difference() {
                union() {
                        circle(r=25); // Create the outer circle
                        translate([17.5,2,0]) circle(r=10);//add some rounding here for the hole
                        translate([-17.5,2,0]) circle(r=10);//add some rounding ro the right hole
                }

                //make it hollow by eating "creating a tooth"
                translate([-28/2,-28,0]) square([28,28]);
                translate([-30,-27 - 10,0]) square([60,28]);//remove unneeded parts

                stepper_holder();
        }

}

union() {
	difference() {
		rotate([90,0,0]) stepper_mount();
		translate([-25,-25,-10 - 12]) cube([50,50,10]);
	}
	translate([-15,0,-3 - 11]) cube([30,tooth_height +1,3]);
	difference() {
		translate([-15,9.5,-3 - 15]) cube([30,3,13]);
		translate([0,6,0]) rotate([-90,0,0]) cylinder(r=12,h=10);
	}
	translate([-16,-22,-18]) block(4,4,2/3,reinforcement=false,solid_bottom=false,flat_top=true);
}


