$fn=150;

module head() {
	color("red")
	difference() {
		cylinder(h = 20, r=26);
		cylinder(h = 20, r=22);
	}
}

//head();

union() {
	difference() {
		union() {
				translate([0,0,-14]) 
				difference() {
					cylinder(h = 20, r=28);
					cylinder(h = 20, r=26.5);
				}
				difference(){
					cylinder(h = 15, r1 = 20,r2 = 40);
					translate([0,0,2])
					cylinder(h = 15, r1 = 20,r2 = 40);
				}
		}
	cylinder(h = 40, r=22);
	}
}