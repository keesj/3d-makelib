use <../external/rack_and_pinion.scad>
use <../mcad/lego_compatibility.scad>

include <settings.scad>

module my_rack(){
	//CP (mm/tooth), width (mm), thickness(of base) (mm), # teeth
	rack(tooth_width,rack_tooth_count,tooth_height,3);
translate([27 * 2,1.5,0]) rotate([90,0,0]) block(2,2,1,reinforcement=false,solid_bottom=false,flat_top=true);
}

my_rack();
