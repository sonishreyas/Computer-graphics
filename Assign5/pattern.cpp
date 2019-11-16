#include<iostream>
#include<graphics.h>
using namespace std;
#define Ox (getmaxx()/2)
#define Oy (getmaxy()/2)
class figure
{
	double cx,cy,ix,iy,a,b,c,ir;
public:

	figure()
	{
		cx = cy = ix = iy = b = a = c = ir = 0;
	}
	
	void ddaline(double x1,double y1,double x2,double y2)
	{
		double x,y,dx,dy,steps,xinc,yinc;
		x = x1;
		y = y1;
		dx = x2 - x1;
		dy = y2 - y1;
		if(abs(dx) > abs(dy))
			steps = abs(dx);
		else
			steps = abs(dy);
			
		xinc = dx / steps;
		yinc = dy / steps;
		putpixel(x+Ox,y+Oy,4);
		while(steps > 0)
		{
			x += xinc;
			y += yinc;
			putpixel(x+Ox,y+Oy,4);
			steps--;
		}
	}
	
	void bresenhamcircle(double xc,double yc , double rad)
	{
		double x1,y1,S;
		x1 = 0;
		y1 = rad;		
		S = 3 - 2*rad;
		putpixel(xc+Ox,yc+Ox,1);
		while(x1 < y1)
		{
			if(S<0)
			{
				S += 4*x1 + 6;
				x1++;
			}
			else
			{
				S += 4*(x1-y1) + 10;
				x1++;
				y1--;
			}
		this->drawcircle(x1,y1,xc,yc);
		}
	}
	
	void drawcircle(double x,double y,double xc,double yc)
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
	
	// FUNCTION TO CALCULATE DISTANCE
	
	double dist(double x1 , double y1, double x2,double y2)
	{
		double d;
		d = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
		return d;
	}

	// FUNCTION TO CALCULATE CIRCUMCENTER
	
	void findcircumcenter(double a[3][2])
	{
		double m1,m2,mx,my,mx1,my1;					//SLOPES
		m1 = (a[1][0] - a[2][0])/(a[2][1] - a[1][1]);
		m2 = (a[0][0] - a[2][0])/(a[2][1] - a[0][1]);
		//mid point of sides
		
		mx = (a[2][0] + a[1][0])/2;
		my = (a[2][1] + a[1][1])/2;
		
		mx1 = (a[2][0] + a[0][0])/2;
		my1 = (a[2][1] + a[0][1])/2;
		
		//using system of equation to find circumcenter
		
		cx = (my1 + m1*mx - my - m2 * mx1)/(m1-m2);
		cy = my + m1*cx - m1*mx;
		
	}
	
	// FUNCTION TO CALCULATE INCENTER
	
	void incenter(double d[3][2])
	{
		
		double m1,m2,mx,my,mx1,my1;
		
		mx = ((a * d[2][0]) + (c * d[1][0]))/(a+c); 
		my = ((a * d[2][1]) + (c * d[1][1]))/(a+c); 
		 
		mx1 = ((a * d[2][0]) + (b * d[0][0]))/(a+b);
		my1 = ((a * d[2][1]) + (b * d[0][1]))/(a+b);
		
		m1 = (my - d[0][1])/(mx - d[0][0]);
		m2 = (my1 - d[1][1])/(mx1 - d[1][0]);
		
		ix = (my1 + m1*mx - my - m2 * mx1)/(m1-m2);
		iy = my + m1*ix - m1*mx;
	
	}
	
	// FUNCTION TO CALCULATE INRADIUS
	
	void inradius(double d[3][2])
	{
		double m;
		m = (d[2][1] - d[0][1])/(d[2][0] - d[0][0]);
		ir = abs((iy - (m * ix) + (m * d[2][0]) - d[2][1])/(sqrt( 1 + pow(m,2)))); 
	}
	
	// MAIN FUNCTION TO DRAW THE MAIN FIGURE
	
	void drawfig()
	{
		double cor[3][2];
		
		cout<<"ENTER THE Co-ordinates of triangle::"<<endl;
		for( int i = 0 ; i < 3 ; i++)
		{
			cout<<"X ["<<i<<"] = ";
			cin>>cor[i][0];
			cout<<"Y ["<<i<<"] = ";
			cin>>cor[i][1];
		}
		
		// CIRCUMCENTER CENTER
		
		this->findcircumcenter(cor);
		 
		//DRAW TRIANGLE
		
		this->ddaline(cor[0][0],cor[0][1],cor[1][0],cor[1][1]);
		this->ddaline(cor[1][0],cor[1][1],cor[2][0],cor[2][1]);
	 	this->ddaline(cor[2][0],cor[2][1],cor[0][0],cor[0][1]);
		
		// FINDING LENGTH OF EACH SIDE OF A TRIANGLE
		
		a = this->dist(cor[0][0],cor[0][1],cor[1][0],cor[1][1]);
		b = this->dist(cor[1][0],cor[1][1],cor[2][0],cor[2][1]);
		c = this->dist(cor[2][0],cor[2][1],cor[0][0],cor[0][1]);
		
		// RADIUS OF CIRCUM CIRCLE
		
		double cr = (a*b*c)/(sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
		
		// DRAW CIRCUMCIRCLE
		
		this->bresenhamcircle(cx,cy,cr);
		
		// FIND INCENTER AND INRADIUS
		
		this->incenter(cor);
		this->inradius(cor);
		
		// DRAW INCIRCLE
		
		this->bresenhamcircle(ix,iy,ir);

	}
};


int main()
{
	int gd = DETECT , gm;
	initgraph(&gd,&gm,NULL);
	figure obj;
	obj.drawfig();
	delay(7000);
	closegraph();
	return 0;
}
