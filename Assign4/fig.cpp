#include<iostream>
#include<graphics.h>
using namespace std;
#define Ox (getmaxx()/2)
#define Oy (getmaxy()/2)

class pattern
{
	float x,y,l,b,x1,y1;			// starting point (x,y) : l = length : b = breadth :

public:

	pattern()
	{
		cout<<":: ENTER CO-ORDINATES ::"<<endl;
		cout<<"x = ";
		cin>>x;
		cout<<"y = ";
		cin>>y;
		cout<<"LENGTH  = ";
		cin>>l;
		cout<<"BREADTH  = ";
		cin>>b;	
		//x1 & y1 coordinate according to new origin
		x1 = x + Ox;
		y1 = y + Oy;	
	}
	
	void linex(float x1,float y1,float x2,float y2)
	{
		float dx,dy,x,y,steps,xinc,yinc;
		x = x1;
		y = y1;
		dx = x2 - x1;
		dy = y2 - y1;
		if(abs(dx) >= abs(dy))
			steps = abs(dx);
	 	else 
	 		steps = abs(dy);
 		xinc = dx/steps;
 		yinc = dy/steps;
 		putpixel(x,y,2);
 		while(steps > 0)
 		{
 			x += xinc;
 			y += yinc;
 			putpixel(x,y,2);
 			steps--;
		}
	}	
	 	
	// DRAW FIGURE
	
	void fig()
	{
	
		line(Ox , 0 , Ox ,2*Oy);
		line(0,Oy,2*Ox,Oy);
		
		// DRAW RECTANGLE
		
		this->linex(x1 , y1 , x1+l , y1);
		this->linex(x1+l , y1 , x1+l , y1+b);
		this->linex(x1+l , y1+b , x1 , y1+b);
		this->linex(x1 , y1+b , x1 , y1);		  
		
		// DRAW RHOMBUS
		
		float x[4],y[4],x2[4],y2[4];
		x[0] = ( 2*x1 + l)/2;
		y[0] = y1;
		x[1] = x1 + l;
		y[1] = (2*y1 + b)/2; 
		x[2] = x[0];
		y[2] = y1 + b;
		x[3] = x1;
		y[3] = y[1];
		
		this->linex(x[0],y[0],x[1],y[1]);
		this->linex(x[1],y[1],x[2],y[2]);
		this->linex(x[2],y[2],x[3],y[3]);
		this->linex(x[3],y[3],x[0],y[0]);
		
		// DRAW SMALL RECTANGLE
		for(int i = 0 ; i < 4 ; i++)
		{
			int j = (i+1) % 4;
			x2[i] = (x[i] + x[j])/2;
			y2[i] = (y[i] + y[j])/2;
		} 
		this->linex(x2[0],y2[0],x2[1],y2[1]);
		this->linex(x2[1],y2[1],x2[2],y2[2]);
		this->linex(x2[2],y2[2],x2[3],y2[3]);
		this->linex(x2[3],y2[3],x2[0],y2[0]);
	}
};

int main()
{
	int gd = DETECT , gm;
	initgraph(&gd,&gm,NULL);
	pattern obj;
	obj.fig();
	delay(5000);
	closegraph();
	return 0;
}
