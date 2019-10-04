
#include<stdlib.h>
#include<iostream>
#include<sstream>
using namespace std;
int main(int argc,char* argv[])
{
	std::string str=argv[1];
	stringstream s(str);
	int i=0,a[20],b,max_no=0,min_no=0;
	while(s>>a[i])
	{
		getline(s,str,' ');
		i++;
	}
	

	b=atoi(argv[2]);
	if(b==1)
	{
		max_no=a[0];
		for(int j=1;j<i;j++)
		{
			if(a[j]>max_no)
				max_no=a[j];
		}
		cout<<max_no;
	}
	if(b==2)
	{
		min_no=a[0];
		for(int j=1;j<i;j++)
		{
			if(a[j]<min_no)
				min_no=a[j];
		}
		cout<<min_no;
	}
    return 0;
}
