//
// shapedemo: testbed for OpenVG APIs
// Anthony Starks (ajstarks@gmail.com)
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

static VGImage img=NULL;
static VGImage main_icons[6]={NULL};
VGfloat x=0;
VGfloat y=0;


void imagetable(int w, int h) {
	int imgw = w, imgh = h;
	int i;

	VGfloat icon_x;
	VGfloat icon_y;

	VGfloat left = 50.0;
	VGfloat bot = h - imgh - 50.0;
	VGfloat gutter = 50.0;
	
	//x = (w-imgw)/2;
	//y = (h-imgh)/2;
	Start(w, h);
	Background(0, 0, 0);

	img = createImageFromJpeg("bg.jpg");
	vgSetPixels(x, y, img, 0, 0, imgw, imgh);
	//vgDestroyImage(img);

	for(i=0;i<6;i++)
	{
		icon_x=400+(i%3)*400;
		icon_y=600-(400*(i/3));

		main_icons[i] = createImageFromJpeg("bk.jpg");
		vgSetPixels(icon_x, icon_y, main_icons[i], 0, 0, 300, 300);
		printf("icon_x=%f\n",icon_x);
		printf("icon_y=%f\n",icon_y);

	}
	//usleep(1000000);

	//usleep(1000000);

	//usleep(1000000);

	//Fill(255, 255, 255, 0.3);
	//Rect(x, y, imgw, 32);
	//Fill(0, 0, 0, 1);
	//TextMid(x + (imgw / 2), y + 10, "MQ.jpg", SansTypeface, 16);

	/*x += imgw + gutter;
	if (x > w) {
	x = left;
	y -= imgh + gutter;
	}

	y = h * 0.1;
	Fill(128, 128, 128, 1);
	TextMid(w / 2, 100, "System Loading....", SansTypeface, 48);*/
	End();
}

void mq_init_system_ui(int w, int h)
{

	const int logo_w = 600, logo_h = 300;
	int logo_x,logo_y;

	VGfloat left = 50.0;
	VGfloat bot = h - logo_h - 50.0;
	VGfloat gutter = 50.0;

	logo_x = (w-logo_w)/2;
	logo_y = (h-logo_h)/2;

	Start(w, h);
	Background(0, 0, 0);

	VGImage init_logo = createImageFromJpeg("MQ.jpg");
	vgSetPixels(logo_x, logo_y, init_logo, 0, 0, logo_w, logo_h);
	vgDestroyImage(init_logo);

	logo_x += logo_w + gutter;
	if (logo_x > w) 
	{
		logo_x = left;
		logo_y -= logo_h + gutter;
	}

	logo_y = h * 0.1;
	Fill(128, 128, 128, 1);
	TextMid(w / 2, 100, "System Loading....", SansTypeface, 48);
	End();

}


void waituntil(int endchar) {
    int key;

    for (;;) {
        key = getchar();
		
		printf("0x%x\n",key);
        if (key == endchar || key == '\n') {
			y-=100;
			Start(1920, 1080);
			vgSetPixels(x, y, img, 0, 0, 600, 300);
			End();
            //break;
        }
		usleep(1000000);
    }
}
int main(int argc, char **argv) {
	int w, h, n;
	char *progname = argv[0];
	saveterm();
	init(&w, &h);
	rawterm();
	mq_init_system_ui(w,h);
	for(n=0;n<100;n++){printf("test\n");};
	imagetable(w, h);
	waituntil(0x1b);
	restoreterm();
	finish();
	return 0;
}
