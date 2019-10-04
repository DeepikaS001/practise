#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int len, index=-1, find;
    cin>>len;
    
    vector<int> arr(len, 0);
    for(int i=0; i<len; i++)
    {
        cin>>arr[i];
    }
    cin>>find;
    for(int i=0; i<len; i++)
    {
        if(arr[i]==find)
        {
            index=i;
            break;
        }
    }
    cout<<index;
    return 0;
}
