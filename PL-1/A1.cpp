//Max X = 639, Max Y = 439

#include <graphics.h>

using namespace std;

class Architecture
{
	protected:
		int top, left, right, bottom;
		int margin;
		enum direction {NORTH = 20, EAST, WEST, SOUTH};
	public:
		void init()
		{
			margin = 10;
			top = left = 3*margin;
			right = getmaxx() - 3*margin;
			bottom = getmaxy() - 3*margin;
		}
		void outline()		//The out of unit part.
		{
			arc(55+left , top , 90, 270, 20);
			moveto(55+left, top-20);
			linerel(80,0);
			moveto(55+left, top+20);		//Memory Interface
			linerel(80,0);
			arc(55+left+80, top, 270, 90, 20);

			setlinestyle(DASHED_LINE,0,1);
			line(left, top+36, left, bottom);
			line(left, bottom, right, bottom);
			line(right, bottom, right, top+36);	//Outer box
			line(left, top+36, left+89, top+36);
			line(left+102, top+36, right, top+36);
			moveto(left,(top+bottom)/2+20);
			linerel(89,0);
			moverel(12,0);
			linerel(200,0);
			linerel(0,-40);				//Divider line
			lineto(right,top+(bottom-top)/2-20);
			setlinestyle(SOLID_LINE,0,1);
		}
		void BIU()
		{
			moveto(left+63, top+65);
			linerel(65,0);
			linerel(20, 45);
			linerel(-25,0);
			linerel(-7,-16);		//Adder
			linerel(-40,0);
			linerel(-7,+16);
			linerel(-25,0);
			lineto(left+63, top+65);

							//Segment Registers
			box(left+40, top+140, 110, 75, 5, 0);

							//Connecting bus
			int x1 = left+55;
			int y1 = top+140;
			moveto(x1-4,y1);
			linerel(0,-22);
			linerel(-3,0);
			moveto(x1+4,y1);
			linerel(0,-22);
			linerel(+3,0);
			lineto(x1,y1-29);
			lineto(x1-7,y1-22);
			x1 = left+135;
			moveto(x1-5,y1);
			linerel(0,-29);
			moveto(x1+5,y1);
			linerel(0,-29);
							//Instruction Stream Byte Queue
			box(right-120, top+75, 60, 100, 6, 0);

							//C-Bus
			x1 = left + 63 + 32;
			y1 = top + 65;
			moveto(x1-5,y1);
			linerel(0,-32);
			linerel(-7,0);
			x1 = getx();
			y1 = gety();
			moveto(left+100,top+65);
			linerel(0,-9);
			moverel(0,-12);
			int x2 = getx();
			int y2 = gety()+6;
			linerel(0,-11);
			linerel(+7,0);
			lineto(left+95,top+21);
			lineto(x1,y1);
			moveto(x2,y2-6);
			lineto(right-84,y2-6);
			linerel(0,21);
			linerel(4,0);
			x1 = getx();
			y1 = gety();
			moveto(x2,y2+6);
			linerel(120,0);
			moverel(12,0);
			x2 = getx()-6;
			lineto(right-96, y2+6);
			linerel(0,9);
			linerel(-4,0);
			lineto(right-90,top+75);
			lineto(x1,y1);
			y2+=6;
			moveto(x2+6,y2);
			lineto(x2+6,top+130);
			linerel(-82,0);
			linerel(0,4);
			x1 = getx();
			y1 = gety();
			moveto(x2-6,y2);
			lineto(x2-6,top+120);
			linerel(-70,0);
			linerel(0,-6);
			lineto(left+140,top+124);
			lineto(x1,y1);
		}

		void EU()
		{
			box(left+30, bottom-70-60,130,60,4,2);
			box(left+30,bottom-70,130,60,4,1);
			int x1 = left+95;
			int y1 = bottom-130;
			moveto(x1-5,y1-10);
			linerel(0,-12);
			linerel(-5,0);
			lineto(x1,y1-32);
			lineto(x1+10,y1-22);
			linerel(-5,0);
			linerel(0,+12);
			linerel(5,0);
			lineto(x1,y1);
			lineto(x1-10,y1-10);
			linerel(5,0);


		}

		void box(int posx, int posy, int width, int height, int rows, int cols)
		{
			int dx = (rows>0)?height/rows:1;		//Relative coordinates of small box
			int dy = (cols>0)?width/cols:1;			//dx is x coordinate, dy is y coordinate
			for (int i = 1; i <= rows; i++)
			{
				//Firstly, draw a row.
				rectangle(posx, posy, posx+width, posy + i*dx);

				//Then draw each column in the row.
				for (int j = 1; j < cols; j++)
					line(posx+j*dy, posy, posx+j*dy, posy+i*dx);
			}
		}
		void arrow(int posx, int posy, int tlen, int hlen, int direction)
		{
			hlen /= 2;
			tlen /= 2;
			int spread = hlen-tlen;
			switch(direction)
			{
				case NORTH:
					/*base = posy;
					top = posy - tlen;*/
					moveto(posx+tlen, posy);
					moverel(spread,0);
					moverel(-hlen, -hlen);
					moverel(-hlen, +hlen);
					moverel(spread, 0);
					moveto(posx, posy);
					break;
				case SOUTH:
					/*base = posy;
					top = posy + tlen;*/
					moveto(posx+tlen, posy);
					moverel(spread, 0);
					moverel(-hlen, +hlen);
					moverel(-hlen, -hlen);
					moverel(spread, 0);
					moveto(posx, posy);
					break;
				case EAST:
					/*base = posx;
					top = posx + tlen;*/
					moveto(posx, posy+tlen);
					moverel(0, spread);
					moverel(+hlen, -hlen);
					moverel(-hlen, -hlen);
					moverel(0, spread);
					moveto(posx, posy);
					break;
				case WEST:
					/*base = posx;
					top = posx - tlen;*/
					moveto(posx, posy+tlen);
					moverel(0, spread);
					moverel(-hlen, -hlen);
					moverel(+hlen, -hlen);
					moverel(0, spread);
					moveto(posx, posy);
					break;
			}
			if (base > top)
			{
				;
			}
		}
};

class Usage: protected Architecture
{
	;
};

int main()
{
	Architecture pic;
	int gm, gd = DETECT;
	initgraph(&gd, &gm, NULL);

	pic.init();
	pic.outline();
	pic.BIU();
	pic.EU();

	getch();

	closegraph();
	return 0;
}
