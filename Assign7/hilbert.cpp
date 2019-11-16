#include<iostream>
#include<graphics.h>
using namespace std;

class hilbert
{
	float h;												// length of a line segment;
	
public:

	float x,y;												// starting co-ordinates
	
	hilbert(); 												// a constructor to initialize starting point of the curve;
	void move( int );										// a function to  decide where to move (up/down/left/right);
	void hilbertcurve(int , int , int , int , int);			// a hilbert function which is called recurrsively
	
};

hilbert :: hilbert()
{
	cout<<"|:|:| ENTER STARTING CO-ORDINATES |:|:|"<<endl;
	cout<<"X = ";
	cin>>x;
	cout<<"Y = ";
	cin>>y;
	h = 10;
}

void hilbert :: move(int j)
{
	delay(100);
	switch(j)
	{	
		case 1 : 	y -= h;									// move up
					break;
					
		case 2 :	x += h;									// move right
					break;
					
		case 3 :	y += h;									// move down
					break;
					
		case 4 :	x -= h;									// move left
					break;
	}
	lineto(x,y);
} 

void hilbert :: hilbertcurve( int r, int d , int l , int u , int degree)
{
	if( degree > 0)
	{
		hilbertcurve( d , r , u , l , degree-1);
		move(r);
		
		hilbertcurve( r , d , l , u , degree-1);
		move(d);
		
		hilbertcurve( r , d , l , u , degree-1);
		move(l);
		
		hilbertcurve( u , l , d , r , degree-1);
	}
}
 
int main()
{
	int gd = DETECT , gm;
	initgraph(&gd,&gm,NULL);
	hilbert h;
	int degree;
	int u = 4, r = 1, d = 2 , l = 3;
	cout<<"ENTER DEGREE OF CURVE :: ";
	cin>>degree;
	
	moveto(h.x, h.y);
	h.hilbertcurve(r,d,l,u,degree);
	delay(5000);
	closegraph();
	return 0;
}





