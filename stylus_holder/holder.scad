holder_height=30;
holder_radius=30;
holder_inner_radius=holder_radius-8;
wall_thikness=2;
holder_top_radius=8.5;
holder_top_inner_radius= holder_top_radius-wall_thikness;
$fn=360;

difference() {
    cylinder(holder_height,holder_radius,holder_top_radius);
    
    translate([0,0,wall_thikness])
    cylinder(holder_height,holder_inner_radius ,holder_top_inner_radius);
}
