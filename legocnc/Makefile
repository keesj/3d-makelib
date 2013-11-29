all: motor_holder.stl mypinion.stl myrack.stl
	
%.stl:%.scad
	openscad -o $@ $<
MCAD:
	git submodule init
	git submodule update
clean:
	rm -rf *.stl
