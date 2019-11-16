#include<iostream>
#include<graphics.h>
using namespace std;

class dashdot
{
	double x1,y1,x2,y2;
	double dx,dy,x,y,steps,xinc,yinc;
	
public:

	dashdot()
	{
		cin>>x1>>y1>>x2>>y2;
		dx = x2 - x1;
		dy = y2 - y1;
		x = x1;
		y = y1;
		if(abs(dx) > abs(dy))
			steps = dx;
		else
			steps = dy;
		xinc = dx/steps;
		yinc = dy/steps;
	}
	
	void dot()
	{
		putpixel(x,y,2);
		for(int i = 0 ; i < steps ; i++)
		{
			if(i%5 == 0)
			{
				putpixel(x,y,2);	
				x += xinc;
				y += yinc;				
			}
			else
			{
				x += xinc;
				y += yinc;
			}
		}
	}
	
	void dash()
	{
		putpixel(x,y,2);
		for(int i = 0 ; i < steps  ; i++)
		{
			int d = 0;
			if(i%5 == 0)
			{
				while(d<5)
				{
					x += xinc;
					y += yinc;
					putpixel(x,y,2);
					d++;
				}
			}
			else
			{
				x += xinc;
				y += yinc;
			}
		}
	}
	
	void dashdotted()
	{
		putpixel(x,y,2);
		for(int i = 0 ; i < steps ; i++)
		{
			int d = 0;
			if(i%10 == 0)
			{
				while(d<5)
				{
					x += xinc;
					y += yinc;
					putpixel(x,y,2);
					d++;
				}
			}
			else if( i % 5 == 0 && i%10 != 0)
			{
				putpixel(x,y,2);
				x += xinc;
				y += yinc;
			}
			else
			{
				x += xinc;
				y += yinc;
			}
		}	
	}
	
	void thick()
	{
		for(int i = 0 ; i < steps ; i++)
		{
				putpixel(x,y,2);
				putpixel(x,y+0.5,2);
				putpixel(x,y-0.5,2);	
				x += xinc;
				y += yinc;				
		}
	}
		
};

int main()
{
	int gd = DETECT , gm;
	initgraph(&gd,&gm,NULL);
	dashdot obj;
	obj.dash();
	//obj.thick();
	delay(5000);
	closegraph();
	return 0;
}
			 
