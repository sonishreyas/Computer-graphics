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

	void translate()				// to translate the given fig.
	{
		double tx,ty;
		cout<<":: ENTER TRANSLATION FACTORS ::"<<endl;
		cout<<"Tx = ";
		cin>>tx;
		cout<<"Ty = ";
		cin>>ty;
		double trans[3][3] = { {1,0,0} , {0,1,0} , {tx,ty,1} };
		this->mat_mul( coor, trans);
	}

	void scaling()					// to scale the given fig.
	{
		double sx,sy;
		cout<<":: ENTER SCALING FACTORS ::"<<endl;
		cout<<"Sx = ";
		cin>>sx;
		cout<<"Sy = ";
		cin>>sy;
		double scale[3][3] = { {sx,0,0} , {0,sy,0} , {0,0,1} };
		this->mat_mul( coor, scale);
	}
	
	void rotate()					// to rotate the given fig.
	{
		double theta;
		double pi = 3.14;
		cout<<":: ANGLE OF ROTATION ::"<<endl;
		cout<<"ANGLE = ";
		cin>>theta;
		theta = (pi * theta) / 180;
		double rotate[3][3] = { {cos(theta),sin(theta),0} , {-sin(theta),cos(theta),0} , {0,0,1} };
		this->mat_mul( coor, rotate);
	}
		
	void shearing()				// to shear the given fig.
	{
		double shx,shy;
		cout<<":: ENTER SHEARING FACTORS ::"<<endl;
		cout<<"Shx = ";
		cin>>shx;
		cout<<"Shy = ";
		cin>>shy;
		double shear[3][3] = { {1,shy,0} , {shx,1,0} , {0,0,1} };
		this->mat_mul(coor,shear);
	}
	void reflection()				// to reflect the given fig.
	{
		double xref[3][3] = { {1,0,0} , {0,-1,0} , {0,0,1} };
		double yref[3][3] = { {-1,0,0} , {0,1,0} , {0,0,1} };
		double oref[3][3] = { {-1,0,0} , {0,-1,0} , {0,0,1} };
		double eref[3][3] = { {0,1,0} , {1,0,0} , {0,0,1} };
		double neref[3][3] = { {0,-1,0} , {-1,0,0} , {0,0,1} };
		int c;
		cout<<"1. ALONG X-AXIS \n2.ALONG Y-AXIS \n3. ALONG ORIGIN.\n4. ALONG X = Y\n5. ALONG Y = -X\n\n ENTER YOUR CHOICE :: ";
		cin>>c;
		switch(c)
		{
			case 1	:	this->mat_mul(coor, xref);
						break;
			case 2	:	this->mat_mul(coor, yref);
						break;
			case 3	:	this->mat_mul(coor, oref);
						break;
			case 4	:	this->mat_mul(coor, eref);
						break;
			case 5	:	this->mat_mul(coor, neref);
						break;						
			default :	cout<<"## INVALID ##"<<endl;
		}
	}

	void mat_mul(double a[][3],double b[3][3])	// matrix multiplication which takes 2 arguments 1. Co-ordinates matrix, and 2. any of the process matrix
	{	
		for( int i = 0 ; i < noc ; i++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				res[i][j] = 0;
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
	
		
};

int main()
{	
	int gd = DETECT , gm;
	initgraph( &gd , &gm , NULL);
	transformation obj;
	obj.getcoor();
	int ch;
	char ch1;
	do{
		cout<<"|:|:| TRANSFORMATION |:|:| \n 1.NEW CO-ORDINATES. \n 2.TRANSLATION. \n 3.ROTATION. \n 4.SHEARING. \n 5.REFLECTION. \n 6.SCALING.\n\n ENTER YOUR CHOICE :: ";
		cin>>ch;
		switch(ch)
		{
			case 1	:	obj.getcoor();
						cin.ignore();
						break;
			case 2	:	obj.translate();
						cin.ignore();
						break;
			case 3	:	obj.rotate();
						cin.ignore();
						break;
			case 4	:	obj.shearing();
						cin.ignore();
						break;
			case 5	:	obj.reflection();
						cin.ignore();
						break;
			case 6	:	obj.scaling();
						cin.ignore();
						break;
			default	:	cout<<"INVALID"<<endl;
		
		}
		cout<<"DO YOU WANT TO CONTINUE (Y/N) :: ";
		cin>>ch1;
		
	}while(ch1 == 'y' || ch1 == 'Y' );								
	delay(5000);
	closegraph();
	return 0;
}
