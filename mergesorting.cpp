
#include <iostream> 
#include<sstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
void mergesorting(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
	
		mergesorting(a, low, mid);
		mergesorting(a, mid+1, high);
		//after partitioning
 		merge(a, low, high, mid);
	}
}
 
int main(int argc,char* argv[])
{
	std::string str=argv[2];
    stringstream ss(str);
    int arr[100],i=0;
    while(ss>>arr[i]) {
      getline(ss,str,' ');
      i++;
     }
    int op=atoi(argv[1]);
	
	
	mergesorting(arr, 0, op-1);
	//sorted array is
	for(int j = 0; j < op; j++)
        cout<<arr[j]<<" ";
 
	return 0;
}
