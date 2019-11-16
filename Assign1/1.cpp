#include<graphics.h>
#include<iostream>
using namespace std;
#include<math.h>
#define sign(x)((x>0)?1:((x<0)?-1:0))
class pixel1
{
	public:
		float x1,y1,x2,y2;
		void insert()
		{
			cout<<" :: ENTER CO-ORDINATES :: "<<endl;
			cout<<"x1 = ";
			cin>>x1;
			cout<<"y1 = ";
			cin>>y1;
			cout<<"x2 = ";
			cin>>x2;
			cout<<"y2 = ";
			cin>>y2;
		}
};

class line1 : public pixel1
{
		float dx,dy,steps,xinc,yinc,x,y;
	public:
		void line2()
		{
			dx = x2 - x1;
			dy = y2 - y1;
			if(abs(dx) >= abs(dy))
				steps = abs(dx);
			else
				steps = abs(dy);
			xinc = dx/steps;
			yinc = dy/steps;
			x = x1;
			y = y1;			
			while(steps >= 0)
			{
				putpixel(x,y,4);
				x = x + xinc;
				y = y + yinc;
				steps = steps-1;
			}
		} 
		void line2(int s1,int s2)
		{
			x = x1;
			y = y1;
			dx = abs(x2 - x1);
			dy = abs(y2 - y1);
			int swap = 0;
			int temp;
			if(dy > dx)
			{
				temp = dx;
				dx = dy;
				dy = temp;
				swap = 1;
			}
			int D = 2*dy - dx;
			for(int i = 0 ; i < dx ; i++)
			{
				putpixel(x,y,2);
				while(D >= 0)
				{
					D = D - 2*dx;
					if(swap == 1)
						x += s1;
					else
						y += s2;
				}
				D = D + 2*dy;
				if(swap == 1)
					y += s2;
				else
					x += s1;	
			}
		}		
};


int main()
{
	int  gd = DETECT, gm;
  	initgraph(&gd, &gm, NULL);
  	line1 l1;
  	int s1,s2;
  	l1.insert();
  	int c;
  	char ch;
  	do{
  		cout<<"|_-_|LINE ALGORITHMS|_-_|"<<endl;
  		cout<<"1. ENTER NEW CO-ORDINATES."<<endl;
  		cout<<"2. DDA LINE ALGORITHM."<<endl;
  		cout<<"3. BRESENHAMS LINE ALGORITHMS."<<endl;
  		cout<<endl<<"ENTER YOUR CHOICE :: ";
  		cin>>c;
  		switch(c)
  		{
  			case 1 : l1.insert();
  					 break;
  			case 2 : l1.line2();
  					 break;
  			case 3 : s1 = sign(l1.x2 - l1.x1);
					 s2 = sign(l1.y2 - l1.y1);
					 l1.line2(s1,s2);
					 break;
			default: cout<<"(|-|)WRONG CHOICE(|+|)"<<endl;
		}
		cout<<endl<<"CONTINUE (Y/N)? => ";
		cin>>ch;
		}while(ch == 'y' || ch == 'Y');
		
		delay(5000);
		closegraph();
  	return 0;
}
					
