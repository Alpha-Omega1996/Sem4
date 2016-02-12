#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
	private:
		int x;
		int y;
		int colour;
		int bkcolour;
	public:
		Point()
		{
			x = y = colour = 0;
		}
		void setpix(int a, int b)
		{
			x = a;
			y = b;
		}
		void setcol(int col, int bkcol)
		{
			colour = col;
			bkcolour = bkcol;
		}
		void init()
		{
			int gm, gd = DETECT;
			initgraph(&gd,&gm,NULL);
			setbkcolor(bkcolour);
		}
		void disp()
		{
			putpixel(x,y,colour);
			getch();
			closegraph();
		}
};

int main()
{
	Point run;
	int temp1, temp2;
	cout<<"Enter the x co-ordinate:";
	cin>>temp1;
	cout<<"Enter the y co-ordinate:";
	cin>>temp2;
	if (temp1 > 0 && temp2 > 0)
		run.setpix(temp1,temp2);
	cout<<"Enter the colour:";
	cin>>temp1;
	if (temp1 > 0)
		if(temp1 < 8)
			run.setcol(temp1, 7-temp1);
		else if (temp1 < 16)
			run.setcol(temp1, 23-temp1);
	;
	run.init();
	run.disp();
	return 0;
}
			

