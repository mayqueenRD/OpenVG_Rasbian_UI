INCLUDEFLAGS=-I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads -I..
LIBFLAGS=-L/opt/vc/lib -lGLESv2 -lEGL -lbcm_host -lpthread  -ljpeg

all: shapedemo

libshapes.o:
	cd .. ; make libshapes.o

oglinit.o:
	cd .. ; make oglinit.o

shapedemo:	shapedemo.c libshapes.o oglinit.o
	gcc -Wall $(INCLUDEFLAGS) $(LIBFLAGS) -o shapedemo shapedemo.c ../libshapes.o ../oglinit.o

test:	shapedemo
	./shapedemo demo 5

clean:
	rm ./shapedemo
	rm ../*.o
	rm ../font2openvg
