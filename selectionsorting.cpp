
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;
int selectionsort(int a[], int n, int mypos[])
{   int pos=mypos[1];
	int min;
    for(int i=0; i<n-1; i++)
    {   min=i;
        for(int j=i+1;j<n;j++)
        {   if(a[j]<a[min])
           {    min=j;
              }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    //find the element at position pos
    int temp= a[pos-1]; 
	return temp;
}
int main(int argc, char** argv)
{	ifstream fin;
    ofstream fout;
    string mystr1,mystr2;
    int myarr1[100],myarr2[2];
    int i=0,j=0; 
    fin.open(argv[1]); 
    fout.open(argv[2]); 
    if(!fin)
	{	exit(1);
	}
	if(!fout)
	{	exit(1);
	}
	while(fin>>myarr1[i]) {
  		getline(fin, mystr1 ,' ');
			i++;
		} 
	fin.clear();
	fin.seekg(0, ios::beg);
	while(fin>>myarr2[j])
	  {
	  getline(fin, mystr2, '\n');
	  j++;
	  }
	  
	  

	
 	int value=selectionsort(myarr1, i,myarr2);
 	
 	
 	fout<<value;
 
 	fin.close();
 	fout.close();
 	
	return 0;
}

