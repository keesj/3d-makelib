This is a hackish set of scripts used to convert a minetest[1] model to an
openscad[2] drawing for printing. Minetestmapper.py found in this directory is
a version of minetest-mapper[3] that is modified to output a comma separated
list of coordinates of a certain type of stone. The output of minetestmapper.py
is passed to "optimize" to convert it to colunms and an openscad model (sorry
my python skills are not optimized yet).

What stones to use?

It happend I had the mesecons[4] mod installed and the type of block used are
the lightstone_red_off. The mod was installed doing cd ~/.mintest/mods and git
clone https://github.com/Jeija/minetest-mod-mesecons.git . After that I enabled
the mod in the configure screen


How to draw:

just run minetest with the mesecons mod installed and draw using
lightstone_red. Keet it to a single drawing per world you create. I am also fairely
new to minetest but to be able to be more productive I suggest doing the following
-Enable fly mode to be able to fly around your model "/grant singleplayer fly" or 
 "/grant playername fly" in multimode
-Enable creative mode
-Disable day/night "/set -n time_speed 0" to disable time
-Set the time to midday "/time 12000" 
-Some kids talked about minetest worldedit (to allow to create areas 
filled with stone but I did not research this area yet).


How to convert:
First run make to compile the c file. After that, stop your minetest game and run

#1 create a cvs list of points
./minetestmapper.py -i ~/.minetest/worlds/myworld | tee out.in
#2 optimize and convert to an openscad drawing
cat out.in | ./optimize > drawing.scad
#3 open in openscad and convert it to and stl file or do it command line
openscad -o drawing.stl drawing.scad
#4 print


[1] - minetest
[2] - openscad
[3] - minetest mapper a tool part of minetest to create png maps of a world 
	https://github.com/minetest/minetest.git util/minetestmapper.py
[4] - mesecons mod http://mesecons.net/ 

