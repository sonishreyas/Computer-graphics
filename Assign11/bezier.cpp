#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class besian
{
	double n,x[10],y[10];
	double X,Y,B,C,A,D;
	public:
	
	besian()
	{
		n = 0;
		x[10] = 0;
		y[10] = 0;
	}
	
	void get()
	{
		cout<<"ENTER TOTAL NUMBER OF CO-ORDINATES :: ";
		cin>>n;
		cout<<":::: Co-ordinates::::"<<endl;
		for(int i = 0 ; i < n ; i++)
		{
			cout<<"x["<<i<<"] = ";
			cin>>x[i];
			cout<<"y["<<i<<"] = ";
			cin>>y[i];
		}
	}
	
	float fact(float a)
	{
		float fact = 1.0;
		if( a == 0)
		{
			return 1;
		}
		else
		{
			while(a>0)
			{
				fact *= a;
				a--;
			}
			return fact;
		}
	}
	
	/*float pow(float a, int m)
	{
		float num = 1;
		for(int i = 0 ; i<m; i++)
		{
			 num *= a;
		}
		return num;
	} */
	
	void curve()
	{
		get();
		float u = 0;
		while( u <= 1)
		{
			X = 0;
			Y = 0;
			for(int i = 0 ; i < n ; i++)
			{
				C = ((fact(n-1))/((fact(n-1-i))*(fact(i))));
				A = pow(u,i);
				D =	pow((1-u),(n-1-i));
				B = A*D*C;
				X += x[i] * B;
				Y += y[i] * B;
			}
			putpixel(X,Y,3);
			u += .002;
		}
	}
};

int main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	besian b1;
	b1.curve();
	delay(5000);
	closegraph();
	return 0;
}
