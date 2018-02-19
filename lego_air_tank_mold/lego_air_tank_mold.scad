//
// Lego Tank
//Things/LEGO
include <../Things/LEGO/anybeam.scad>
//http://www.brickgun.com/Dimensions/images/BrickGun%20LEGO_Brick_Dimensions.jpg
ldu=0.4; // *base size of ldraw units(We will scale eveything that way in the end

sphere_outer_radius = 40 * ldu;
sphere_inner_radius = (sphere_outer_radius -2);
$fn=200;

extra_down=2;

module piece(draw_inner =1,draw_only_inner=0) {
    translate([0,0,AB_BEAM_HEIGHT/2])
    union() {
        translate([0,0,sphere_outer_radius +AB_BEAM_HEIGHT /2  - extra_down])
        difference(){
            //outter shpere
            if (draw_only_inner == 0){
                sphere(r=sphere_outer_radius);
            }
            //innner shpere
            if (draw_inner == 1){
              sphere(r=sphere_inner_radius);
            }
        }
        if (draw_only_inner ==0){
            translate([-AB_HOLE_SPACING,0,0])
            rotate([90,0,0])            
            anybeam(["O_O"]);
        }
    }
}

border_width=3;

module part_1() {
    difference() {
    translate([-sphere_outer_radius - border_width,0,0])
    cube([sphere_outer_radius * 2 + ( 2* border_width),sphere_outer_radius + border_width,sphere_outer_radius *2 + AB_BEAM_HEIGHT -extra_down + 2* border_width ]);
    translate([0,0,border_width])
    piece(draw_inner=0);
    }
}

module part_2() {
    
    intersection() {
    translate([0,0,border_width])
    piece(draw_inner=1,draw_only_inner=1);
    translate([-sphere_outer_radius - border_width,0,0])
    cube([sphere_outer_radius * 2 + ( 2* border_width),sphere_outer_radius + border_width,sphere_outer_radius *2 + AB_BEAM_HEIGHT -extra_down + 2* border_width ]);

    }
    translate([-sphere_outer_radius - border_width,-border_width,0])
    cube([sphere_outer_radius * 2 + ( 2* border_width), border_width,sphere_outer_radius *2 + AB_BEAM_HEIGHT -extra_down + 2* border_width ]);

}


piece(draw_inner=1);
//cube();
//part_1();


//translate([sphere_outer_radius  * 2+ border_width,border_width,0])
//rotate([0,0,0])
//translate([0,-20,0])
//part_2();