use <../external/rack_and_pinion.scad>
use <../mcad/lego_compatibility.scad>

include <settings.scad>

module my_pinion() {
	// a simple pinion and translation / rotation to make it mesh the rack
	translate([0,-11 ,0])rotate([0,0,360/wheel_tooth_count/2]) pinion(tooth_width,wheel_tooth_count,tooth_height,5);
}

my_pinion();
