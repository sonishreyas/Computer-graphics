#include<iostream>
#include<graphics.h>
using namespace std;
class opol
{
	double getmat[10][3];
	int noc;
	double resmat[10][3];
	public:
	
	opol()
	{
		getmat[10][3] = {0};
		noc = 0;
		resmat[10][3] = {0};
	}
	
	void get()
	{
		cout<<"ENTER NUMBER OF COORDINATES :: ";
		cin>>noc;
		for( int i = 0 ; i < noc ; i++)
		{
			cout<<"ENTER X["<<i<<"] :: ";
			cin>>getmat[i][0];
			cout<<"ENTER Y["<<i<<"] :: ";
			cin>>getmat[i][1];
			getmat[i][2] = 1;
		}
		draw(getmat);
	}
	
	void mat_mul(double m1[][3] , double m2[3][3])
	{
		cleardevice();
		for(int i = 0 ; i < noc ; i++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				resmat[i][j] = 0;
				for( int k = 0 ; k < 3 ; k++)
				{
					resmat[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
		draw(resmat);
	}
	void draw(double dr[][3])
	{
		cleardevice();
		double x = getmaxx() / 2;
		double y = getmaxy() / 2;
		line( x , 0 , x , 2*y );
		line( 0 , y , 2*x , y );
		for( int i = 0 ; i < noc - 1 ; i++)
		{
			line( dr[i][0] + x , dr[i][1] + y , dr[i+1][0] + x , dr[i+1][1] + y );
		}
		line( dr[noc - 1][0] + x , dr[noc - 1][1] + y , dr[0][0] + x , dr[0][1] + y );
	}
	
	void operator +()		//scaling
	{
		cout<<"ENTER X SCALING FACTOR :: ";
		double sx;
		cin>>sx;
		cout<<"ENTER Y SCALING FACTOR :: ";
		double sy;
		cin>>sy;
		double scale[3][3] = { { sx , 0 , 0 } , { 0 , sy , 0 } , { 0 , 0 , 1 } };
		mat_mul( getmat , scale );
	}
	
	void operator ~()		//rotation
	{
		cout<<"ENTER ANGLE FOR ROTATION :: ";
		double angle;
		cin>>angle;
		angle = (3.14 / 180 ) * angle;
		double rot[3][3] = { { cos(angle) , sin(angle) , 0 } , { -1*sin(angle) , cos(angle) , 0 } , { 0 , 0 , 1 } };
		mat_mul( getmat , rot );
	}
	
	void operator -()		//translation
	{
		cout<<"ENTER X TRANSLATION FACTOR :: ";
		double tx;
		cin>>tx;
		cout<<"ENTER Y TRANSLATION FACTOR :: ";
		double ty;
		cin>>ty;
		double trans[3][3] = { { 1 , 0 , 0 } , { 0 , 1 , 0 } , { tx , ty , 1 } };
		mat_mul( getmat , trans );
	}
	
};
int main()
{
	opol o;
	int c;
	int gd = DETECT , gm;
	initgraph( &gd , &gm , NULL );
	char ch;
	do
	{
		cout<<"1. TO ENTER NEW COOR\n2. TO SCALE\n3. TO TRANSLATE\n4. TO ROTATE\n5. TO EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE :: ";
		cin>>c;
		switch(c)
		{
			case 1 :o.get();
					break;
			case 2 : +o;
					break;
			case 3 : -o;
					break;
			case 4 : ~o;
					break;
			case 5 : return 0;
			
			default: cout<<"WRONG CHOICE "<<endl;
						break;
		}
		cout<<"DO YOU WANT TO CONTINUE ( Y / N ) :: ";
		cin>>ch;
	}while( ch == 'Y' || ch == 'y' );
	delay(5000);
	closegraph();
	return 0;
} 
	
	
	
	
	
	
	
	
