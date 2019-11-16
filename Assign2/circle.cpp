#include<iostream>
#include<graphics.h>
using namespace std;
#define Ox (getmaxx()/2)		//to shift x co-ordinate of origin to center of the screen
#define Oy (getmaxy()/2)		//to shift y co-ordinate of origin to center of the screen

class circlealgo
{
	double dp;					// Decision parameter
	double x,y,r;				// (x0,y0)->initial co-ordinate & r->radius
	double xc,yc;				// center of circle
	double S;					// Decision parameter for bresenham's algo
public:
	
	circlealgo()
	{
		cout<<"ENTER RADIUS OF CIRCLE :: ";
		cin>>r;
		cout<<": CENTER OF THE CIRCLE :"<<endl;
		cout<<"Xc = ";
		cin>>xc;
		cout<<"Yc = ";
		cin>>yc;
		x = 0;
		y = r;
		dp = 1 - r;				//initial dp for midpoint;
		S = 3 - 2*r;			// initial S for bresenham's
	}
	
	void midpoint()
	{
		putpixel(x,y,3);
		while(x <= y)
		{
			if( dp < 0 )
			{
				dp += 2*x + 1;
				x++;
			}
			else
			{
				dp += 2*(x-y) + 1;
				x++;
				y--;
			}
			this->drawcircle(x,y);
		}
	}
	
	void bresenhamcircle()
	{
		while(x < y)
		{
			if( S < 0 )
			{
				S += 4*x + 6;
				x++;
			}
			else
			{
				S += 4*(x-y) + 10;
				x++;
				y--;
			}
			this->drawcircle(x,y);
		}
	}
				
	void drawcircle(double x,double y)
	{
		line(Ox,0,Ox,2*Oy);
		line(0,Oy,2*Ox,Oy);
		putpixel(xc+x+Ox,yc+y+Oy,3);
		putpixel(xc+x+Ox,yc-y+Oy,3);
		putpixel(xc-x+Ox,yc+y+Oy,3);
		putpixel(xc-x+Ox,yc-y+Oy,3);
		putpixel(xc+y+Ox,yc+x+Oy,3);
		putpixel(xc+y+Ox,yc-x+Oy,3);
		putpixel(xc-y+Ox,yc+x+Oy,3);
		putpixel(xc-y+Ox,yc-x+Oy,3);	
	}
	
};

int main()
{
	int gd = DETECT,gm;
	initgraph ( &gd,&gm,NULL);
	circlealgo obj,obj1;
	obj.midpoint();
	obj1.bresenhamcircle();
	delay(5000);
	closegraph();
	return 0;
}
