#include<iostream>
#include<graphics.h>
using namespace std;
#define sin 0.86602540

void koch(double x1,double y1,double x2,double y2,double m)
{
	double xx,yy,x[5],y[5],lx,ly,offx=50,offy=300;
	lx=(x2-x1)/3;
	ly=(y2-y1)/3;
	x[0]=x1;        //store point p0
	y[0]=y1;
	x[4]=x2;        //store point p4
	y[4]=y2;
	x[1]=x[0]+lx;   //store point p1
	y[1]=y[0]+ly;
	x[3]=x[0]+2*lx; //store point p3
	y[3]=y[0]+2*ly;

	xx=x[3]-x[1];
	yy=y[3]-y[1];

	x[2] = xx*(0.5) + yy *( sin);
	y[2] = -xx*(sin) + yy * 0.5;

	x[2] += x[1];
	y[2] += y[1];
	
	if( m > 0)
	{
		koch(x[0],y[0],x[1],y[1],m-1);
		koch(x[1],y[1],x[2],y[2],m-1);
		koch(x[2],y[2],x[3],y[3],m-1);
		koch(x[3],y[3],x[4],y[4],m-1);
	}
	else
	{
		line(offx+x[0] ,offy+y[0] ,offx + x[1], offy + y[1]);
		//delay(1000);
		line(offx+x[1] ,offy+y[1] ,offx + x[2], offy + y[2]);
		line(offx+x[2] ,offy+y[2] ,offx + x[3], offy + y[3]);
		line(offx+x[3] ,offy+y[3] ,offx + x[4], offy + y[4]);
	}
}


int main()
{
	int gd = DETECT, gm;
	initgraph(&gd , &gm , NULL);
	double x1,y1,x2,y2,n; 
	cout<<"ENTER CO-ORDINATES::"<<endl;
	cin>>x1>>y1>>x2>>y2;
	cout<<"N = ";
	cin>>n;
	koch(x1,y1,x2,y2,n);
	delay(5000);
	closegraph();
	return 0;
}
	
	
