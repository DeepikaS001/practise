
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
int a; 
int count[30]={0};
ofstream fout;
int partitioning (int array[], int low, int high) 
{ 
    int pivot = array[high];   
    int i = (low - 1); 
  	int temp,t1;
    for (int j = low; j <= high- 1; j++) 
    {  	
        if (array[j] <= pivot) 
        { 
            i++;   
           temp= array[i] ;
		   array[i]=array[j]; 
		   array[j]=temp;
        } 
    }
    	t1=array[high];
        for(int n=high;n>i+1;n--)
        {
        	array[n]=array[n-1];
		}
		array[i+1]=t1;
		count[i+1]=1;	
 return (i + 1); 
} 
void quickSorting(int array[], int low, int high) 
{  int i;
    if (low <= high) 
    {
        int pi = partitioning(array, low, high); 
 
      for( i=0;i<a-1;i++)
      {
      	if(count[i]!=1) 
		  {fout<<array[i]<<",";
		  }
      	else {
      		fout<<"("<<array[i]<<"),";
        }
	  }
	  if(count[i]!=1) 
	  {
	  fout<<array[i];
	  }
      else
	  {
	  fout<<"("<<array[i]<<")";
	  }
	  fout<<endl;
      quickSorting(array, low, pi - 1); 
      quickSorting(array, pi + 1, high);   
    }   
} 
int main(int argc,char** argv)
 { 
    ifstream fin;
    string str;
    int array[100];
    int j;
	a=0; 
    fin.open(argv[1]); 
    fout.open(argv[2]); 
    if(!fin)
	{
		exit(1);
	}
	 if(!fout)
	{
		exit(1);
	}
  	
	while(fin>>array[a]) {
  		getline(fin, str ,' ');
			a++;
		}
	for(  j=0;j<a-1;j++)
    { 	 fout<<array[j]<<","; 
	}
 	 fout<<array[j]<<endl;
  	
  	
 	 quickSorting(array,0,a-1);	
	
	    
	for(j=0;j<a-1;j++)
   	{
   	 fout<<array[j]<<","; 
    }
	fout<<array[j];
    fin.close();
    fout.close();
 	return 0;
} 
 
