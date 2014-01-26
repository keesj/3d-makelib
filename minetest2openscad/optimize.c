#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define XSIZE 1000
#define YSIZE 1000
#define ZSIZE 200
int xyz[XSIZE][YSIZE][ZSIZE];

/**
 * This program read the output of the modified minetestmapper found in this same directory
 * minetestmapper.py output a cvs list of lightstone_red_off minetest stones.
 **/
int main(int argc,char **argv)
{
	memset(&xyz,0,sizeof(xyz));
	 int x,y,z,r;
	 while ( (r = fscanf(stdin, "%d,%d,%d", &x,&y,&z)) == 3 ) {	
		assert(x < XSIZE);
		assert(y < YSIZE);
		assert(z < ZSIZE);
		xyz[x][y][z] = 1;
	 }
	/* now optimize */
	//printf("translate([%d,%d,%d]) cube([1,1,1]);\n",x,y,z);
	for (x=0 ; x < XSIZE ; x++){
		for (y=0 ; y < YSIZE ; y++){
			for (z=0 ; z < ZSIZE ; z++){
				if (xyz[x][y][z] == 1){
					int f,count;
					count =0;
					for (f =z ;  f < ZSIZE ; f++){
						if (xyz[x][y][f] ==1){
							count++;
						} else {
							//printf("making xyz -> %d,%d,%d %d\n",x,y,z,count);
							xyz[x][y][z] = count;
							int g;
							for (g =z+1 ;  g < z + count ; g++){
								xyz[x][y][g] =0;
							}
						}
					}
				}
			
			}
		}
	}
	printf("union () { \n");
	for (x=0 ; x < XSIZE ; x++){
		for (y=0 ; y < YSIZE ; y++){
			for (z=0 ; z < ZSIZE ; z++){
				if (xyz[x][y][z] > 0){
					printf("translate([%d,%d,%d]) cube([1,1,%d]);\n",x,y,z,xyz[x][y][z]);
				}
			}
		}
	}
	printf("}\n");
	return 0;
}
