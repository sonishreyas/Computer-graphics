#include<iostream>
#include<graphics.h>
using namespace std;

class transformation
{
	public:	
	double coor[10][3];				// array of co-ordinates ex: [ x y 1 ] : where, 3rd column is always 1 and x and y are user defined
	int noc;						// number of co-ordinates
	double res[10][3];				// resultant matrix of new co-ordinates after any of the operations
	
	transformation()				// constructor to initialise coor[][] array and number of coordinates 
	{
		coor[10][3] = {0};
		res [10][3] = {0};
		noc = 0;
	}
	
	void getcoor()					// to input number of co-ordinates and co-ordinates and call draw function to draw the original figure
	{
		cout<<"ENTER NUMBER OF COORDINATES :: ";
		cin>>noc;
		cout<<"|:|:| ENTER COORDINATES |:|:|"<<endl;
		for( int i = 0 ; i < noc ; i++ )
		{
			cout<<"X ["<<i<<"] = ";
			cin>>coor[i][0];
			cout<<"Y ["<<i<<"] = ";
			cin>>coor[i][1];
			coor[i][2] = 1;
		}
		this->drawfig(coor);
	}
	
	void mat_mul(double a[][3],double b[3][3])	// matrix multiplication which takes 2 arguments 1. Co-ordinates matrix, and 2. any of the process matrix
	{	
		for( int i = 0 ; i < noc ; i++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				for(int k = 0 ; k < 3 ; k++)
				{
					res[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		
		this->drawfig(res);
	}  
	void drawfig(double res[][3])			// Main polygon is drawn in this
	{
		cleardevice();
		double x = getmaxx() / 2;
		double y = getmaxy() / 2;
		line(x , 0 , x , 2*y);
		line(0 , y , 2*x , y);
		int i = 0;
		while( i < noc-1)
		{
			line(res[i][0]+x,y+res[i][1],res[i+1][0]+x,y+res[i+1][1]);
			i++;
		}	
		line(res[noc-1][0] + x,res[noc-1][1]+y,res[0][0]+x,res[0][1]+y);	
		delay(5000);
	}
	
	
	void trt()
	{
		this->getcoor();
		double x,y;
		cout<<":: ENTER POINT ABOUT WHICH GIVEN FIG. IS TO BE ROTATED ::"<<endl;
		cout<<"X = ";
		cin>>x;
		cout<<"Y = ";
		cin>>y;
		double pi = 3.14;
		double theta;
		cout<<"THETA = ";
		cin>>theta;
		theta = ( pi * theta)/180 ;
		double trtmat[3][3]  = {{cos(theta),sin(theta),0},{-sin(theta),cos(theta),0},{((-x*cos(theta))+(y*sin(theta))+x),((-x*sin(theta))-(y*cos(theta))+y),1}};
		this->mat_mul(coor,trtmat);
	}
};

int main()
{	
	int gd = DETECT , gm;
	initgraph( &gd , &gm , NULL);
	transformation obj;
	obj.trt();	
	delay(5000);
	closegraph();
	return 0;
}

