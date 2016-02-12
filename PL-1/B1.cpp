#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Lines
{
	protected:
		int x1, y1, x2, y2;
	public:
		Lines(int a, int b, int c, int d)
		{
			x1 = a;
			y1 = b;
			x2 = c;
			y2 = d;
		}
		void FlatLine();
		void DottedLine();
		void ThickLine();
};

int maxabs(int m, int n)
{
	m = (m>=0)?m:-m;
	n = (n>=0)?n:-n;
	return (m>n)?m:n;
}

float roundoff(float bad)
{
	return floor(bad+0.5);
}

void Lines::FlatLine()
{
	float dx = x2-x1;
	float dy = y2-y1;
	int length = maxabs(dx,dy);
	dx /= length;
	dy /= length;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	for (int i = 0; i < length; i++)
	{
		putpixel(int(x), int(y), WHITE);
		x += dx;
		y += dy;
	}
}

void Lines::DottedLine()
{
	float dx = x2-x1;
	float dy = y2-y1;
	int length = (int)maxabs(dx,dy);
	dx /= length;
	dy /= length;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	for (int i = 0, j = 1; i < length; i++, j++)
	{
		if(j == 3)
			j = 0;
		else
			putpixel(int(x), int(y), WHITE);
		x += dx;
		y += dy;
	}
}

void Lines::ThickLine()
{
	int thick;
	system("clear");
	cout<<"Enter width of line: ";
	cin>>thick;
	thick--;
	int dx = x2-x1;
	int dy = y2-y1;
	int length = maxabs(dx,dy);
	int type = ( length == dx)? 1 : 0;
	float width = thick*sqrt(dx*dx + dy*dy)/2;
	if (type)
		width /= maxabs(dx,0);
	else
		width /= maxabs(dy,0);
	thick = roundoff(width);
	int save[] = {x1,y1,x2,y2};
	for (int i = 0; i < thick+1; i++)
		if(type)
		{
			x1 = save[0] - i;
			x2 = save[2] - i;
			FlatLine();
			x1 = save[0] + i;
			x2 = save[2] + i;
			FlatLine();

		}
		else
		{
			y1 = save[1] - i;
			y2 = save[3] - i;
			FlatLine();
			y1 = save[1] + i;
			y2 = save[3] + i;
			FlatLine();

		}
}

int main()
{
	int gm, gd = DETECT, a, b, c, d;
	string dump;
	initgraph(&gd, &gm, NULL);
	delay(1000);
	system("clear");
	cout<<"\nEnter the coordinates of a line: \n";
	cout<<"Point 1:";
	while(1)
	{
		cout<<"Min X: 0\nMax X: "<<getmaxx()<<"\n\tx > ";
		cin>>a;
		if (a<0||a>getmaxx());
		else break;
	}
	while(1)
	{
		cout<<"Min Y: 0\nMax Y: "<<getmaxy()<<"\n\ty > ";
		cin>>b;
		if (b<0||b>getmaxy());
		else break;
	}
	cout<<"Point 2:";
	while(1)
	{
		cout<<"Min X: 0\nMax X: "<<getmaxx()<<"\n\tx > ";
		cin>>c;
		if (c<0||c>getmaxx());
		else break;
	}
	while(1)
	{
		cout<<"Min Y: 0\nMax Y: "<<getmaxy()<<"\n\ty > ";
		cin>>d;
		if (d<0||d>getmaxx());
		else break;
	}
	Lines t(a,b,c,d);
	while(1)
	{
		cout<<"\nEnter line type: \n1)Flat Line\n2)Dotted Line\n3)Thick Line\n\t > ";
		cin>>a;
		if (a>3||a<1);
		else break;
	}
	switch(a)
	{
		case 1:
			t.FlatLine();
			break;
		case 2:
			t.DottedLine();
			break;
		case 3:
			t.ThickLine();
			break;
	}
	getline(cin,dump);
	getch();
	closegraph();
	return 0;
}
