#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

#define SIGN(x) ( (x > 0) ? 1 : ( (x < 0) ? -1 : 0 ) )
#define ABSD(x,y)	( (x-y > 0) ? x-y : y-x )
#define swap(x,y) do{ int temp = x; x = y; y = temp; }while(0)
#define INT(x) (int)( floor(0.5+x) ) 

class Point
{
	protected:
		int x1;
		int y1;
		int colour;
		int bkcolour;
	public:
		Point()
		{
			x1 = y1 = colour = 0;
		}
		void setpix(int a, int b)
		{
			x1 = a;
			y1 = b;
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
			putpixel(x1,y1,colour);
		}
		void close()
		{
			getch();
			closegraph();
		}
};


class Line:private Point
{
		int x2;
		int y2;
		void dda();
		void bresenham();
	public:
		Line()
		{
			Point();
			x2 = y2 = 0;
		}
		void line();
};

void Line::dda()
{
	float dx = x2-x1;
	float dy = y2-y1;
	int length = (ABSD(dx,0) > ABSD(dy,0)) ? ABSD(dx,0) : ABSD(dy,0);
	dx /= (float)length;
	dy /= (float)length;
	float x = x1 + 0.5*SIGN(dx), y = y1 + 0.5*SIGN(dy);
	for (int i = 0 ; i < length ; i++)
	{
		putpixel(INT(x),INT(y),colour);
		x += dx;
		y += dy;
	}
}

void Line::bresenham()
{
	int dx = ABSD(x2,x1);
	int dy = ABSD(y2,y1);
	int interchange = 0;
	if (dy > dx && (interchange = 1) )
		swap(dy,dx);
	
	int e = 2*dy - dx;
	int x = x1;
	int y = y1;
	for(int i = 0; i < dx ; i++)
	{
		putpixel(x,y,colour);
		while (e > 0 || e == 0)
		{
			if (interchange)
				x += SIGN(x2-x1);
			else
				y += SIGN(y2-y1);
			e -= 2*dx;
		}
		if (e < 0)
		{
			if (interchange)
				y += SIGN(y2-y1);
			else
				x += SIGN(x2-x1);
			e += 2*dy;
		}
	}
}

void Line::line()									//Overloaded libgraph's (Turbo C's) line drawing technique
{
	int ch = 0;
	cout<<"\nEnter starting Point:";
	while (1)
	{
		cout<<"\n\t> x : ";
		cin>>x1;
		if (x1 >= 0)
			break;
		else
			cout<<"\nNegative Value not allowed.\n";
	}
	while (1)
	{
		cout<<"\n\t> y : ";
		cin>>y1;
		if (y1 >= 0)
			break;
		else
			cout<<"\nNegative Value not allowed.\n";
	}
	cout<<"Enter ending Point:";
	while (1)
	{
		cout<<"\n\t> x : ";
		cin>>x2;
		if (x2 >= 0)
			break;
		else
			cout<<"\nNegative Value not allowed.\n";
	}
	while (1)
	{
		cout<<"\n\t> y : ";
		cin>>y2;
		if (y2 >= 0)
			break;
		else
			cout<<"\nNegative Value not allowed.\n";
	}
	while(1)
	{
		while(1)
		{
			cout<<"\nEnter the method of drawing the line: \n\t1)Direct Digital Analyser.\n\t2)Bresenham's Algorithm.\n\t> ";
			cin>>ch;
			if(ch == 1)
				break;
			else if (ch == 2)
				break;
			else
				cout<<"\nPlease Select a Valid option.\n";
		}
		int gm, gd = DETECT;
		initgraph(&gd, &gd, NULL);
		switch(ch)
		{
			case 1:
				setcol(RED,BLACK);
				init();
				dda();
				cin.ignore();
				close();
				break;
			case 2:
				setcol(CYAN,BLACK);
				init();
				bresenham();
				cin.ignore();
				close();
				break;
		}
		system("clear");
		cout<<"Try another algorithm? (0/1) : ";
		cin>>ch;
		if (!ch)
			break;
	}
}

int main()
{
	Line run;
	run.line();
	return 0;
}
