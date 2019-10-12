#include <iostream>
#include <unistd.h>

using namespace std;

void make(int f[],int m,int dt[],int n,int s,int c)
{
	f[0]=s;
	if(m-1<=n)
	{
        for(int i=1,j=(i-1)+(m-1)*c;i<m && j<n;i++,j++)
            {f[i]=dt[j];}
    }
    else if(m-1>n)
    {
        for(int i=1;i<m;i++)
        {
            if((i-1)<n)
                f[i]=dt[i-1];
            else
                f[i]=-1;
        }
    }
}


void send(int f[],int m,int n,bool &c,int &s)
{
    cout<<"\nFrame Sent:\t";
    for(int i=1;i<m && f[i]!=-1;i++)
        {cout<<f[i];f[i]=-1;}
    cout<<"\nSequence Number:\t"<<f[0];
    c=false;
    if(s==0)
        {   s=1;
            return; }
    else if(s==1)
        {   s=0;
            return; }
}


void ack(int ac,int s,bool &c)
{
    if(ac==s)
    cout<<"\nAcknowledgment Received:\t"<<ac;
    if(ac!=s)
    cout<<"\nWrong Acknowledgment Received:\t"<<ac;
    c=true;
}


void sack(int f[],int &a)
{
    if(f[0]==a && a==0)
    {
        a=1;
        return;
    }
    if(f[0]==a && a==1)
    {
        a=0;
        return;
    }
}


int main()
{
    int n,fs,sqn=0,ctr=0,ac=0;
    bool cs;
    cout<<"\n\tSTOP AND WAIT PROTOCOL\n";
    cout<<"\nInput the number of data bits to be sent:\t";
    cin>>n;
    fs=4;
    int d[n],fr[fs+1];
    cout << "\nInput the data to be sent:\n\t";
    for(int i=0;i<n;i++)
    {      cin>>d[i];
        cout<<"\t"; }
    int x;
    if(n%fs==0)
        x=n/fs;
    else{
        x=n/fs+1;
    }
    for(int i=0;(x!=ctr);i++)
        {
            make(fr,fs+1,d,n,sqn,ctr);
            send(fr,fs+1,n,cs,sqn);
            usleep(1500);
            sack(fr,ac);
            ack(ac,sqn,cs);
            ctr++;
        }
    return 0;
}
