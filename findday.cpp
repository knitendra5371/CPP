#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d,m,y,day;
	    cin>>d>>m>>y;
     	int j,f,h,fh;
	    j=d;
	    switch(m-1)
	    {
			case 11: j+=30;
			case 10: j+=31;
			case  9: j+=30;
			case  8: j+=31;
			case  7: j+=31;
			case  6: j+=30;
			case  5: j+=31;
			case  4: j+=30;
			case  3: j+=31;
			case  2: j+=28;
			case  1: j+=31;
		}
		if(y%4==0 && y%100!=0 || y%400==0)
			if(m>2)
				j++;
		f=(y-1)/4;
		h=(y-1)/100;
		fh=(y-1)/400;
		day=(y+j+fh-h+f)%7;
		switch(day)
		{
			case 0: cout<<"Saturday\n"; break;
			case 1: cout<<"Sunday\n"; break;
			case 2: cout<<"Monday\n"; break;
			case 3: cout<<"Tuesday\n"; break;
			case 4: cout<<"Wednesday\n"; break;
			case 5: cout<<"Thursday\n"; break;
			case 6: cout<<"Friday\n"; break;
		}
	}
	return 0;
}
