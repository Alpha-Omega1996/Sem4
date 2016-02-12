#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

#define DIST(a,b,c,d) sqrt( (a-c)*(a-c) + (b-d)*(b-d) )

class Line
{
	protected:
		int x1;
		int y1;
		int x2;
		int y2;
	public:
		Line()
		{
			x1 = y1 = x2 = y2 = 0;
		}
		
};


class Circle: protected Line
{
	private:
		int r;
		void calc()
		{
			r = DIST(x1,y1,x2,y2);
		}
	public:
		Circle()
		{
			Line();
			r = 0;
		}
		void init()
		{
			int gm, gd = DETECT;
			initgraph(&gd,&gm,NULL);
		}
		void setVal();
		void disp()
		{
			setbkcolor(0);
			line(x1,y1,x2,y2);
			circle(x1,y1,r);
			getch();
			closegraph();
		}	
};

void Circle::setVal()
{
	while (1)
	{
		cout<<"\nEnter coordinates of a line: \n";
		while(1)
		{
			cout<<"\n\tPoint 1: ";
			cout<<"\n\t x :\n\t > ";
			cin>>x1;
			cout<<"\t y :\n\t > ";
			cin>>y1;
			if (x1 > 0 && y1 > 0)
				break;
			else
				cout<<"\nNegative Coordinates are not allowed.\n";
		}
		
		while(1)
		{
			cout<<"\n\tPoint 2: ";
			cout<<"\n\t x :\n\t > ";
			cin>>x2;
			cout<<"\t y :\n\t > ";
			cin>>y2;
			if (x2 > 0 && y2 > 0)
				break;
			else
				cout<<"\nNegative Coordinates are not allowed.\n";
		}
		calc();
		if (x1 > r && y1 > r)
			break;
		else
			cout<<"\nCircle is too big to fit or it's centre is too close to Origin (Point 1 is Centre)\n";
	}
}
int main()
{
	Circle run;
	run.setVal();
	run.init();
	run.disp();
	return 0;
}
			

