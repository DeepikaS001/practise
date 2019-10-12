#include <iostream>
#include <unistd.h>
#include <cstdlib>

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
    cout<<"\nFrame sent:\n\t";
    for(int i=1;i<m && f[i]!=-1;i++)
        {
            cout<<f[i];
            f[i]=-1;
        }
    cout<<"\nSequence Number:\n\t"<<f[0];
    c=false;
    if(s==0)
        {s=1;
        return;}
    if(s==1)
        {s=2;
        return;}
    if(s==2)
        {s=3;
        return;}
    if(s==3)
        {s=0;
        return;}
}


void rcv(int f[],int m,int s[],int &e)
{
    int fl=-1;
    for(int i=1;i<m;i++)
    {   if(f[i]==s[i])
            fl=1;
        else
        {
            cout<<"\nERROR!!! The frame has an error.";
            e=1;
            break;
        }
    }
    if(fl==1)
        cout<<"\nThe frame has been received successfully.\n";
}


void ack(int ac,int s,bool &c)
{
    if(ac==s)
    cout<<"\nThe acknowledgment has been received! :) "<<ac;
    if(ac!=s)
    cout<<"\nThe wrong acknowledgment has been received! :) "<<ac;
    c=true;
}

void sack(int f[],int &a,int e)
{
    if(e==1)
    {
            a=f[0];
            return;
    }
    if(e==0)
    {
            if(f[0]!=3)
            {a=f[0]+1;return;}
            else if(f[0]==3)
        {a=0;return;}
    }
}

int main()
{
    int n,fs,sqn=0,ctr=0,ac=0;
    int e=0;
    bool cs;
    cout<<"\n\tGO BACK N PROTOCOL: Sliding Window =3 \n";
    cout<<"\nInput the number of data bits to be sent:\n\t ";
    cin>>n;
    fs=4;
    int d[n],fr[fs+1];
    cout << "\nInput the data to be sent: \n\t";
    for(int i=0;i<n;i++)
    cin>>d[i];
    int x;
    if(n%fs==0)
        x=n/fs;
    else{
        x=n/fs+1;
    }
    int k,s=0;
    for(int i=0,k=0;(x!=ctr);i++)
    {
        make(fr,fs+1,d,n,sqn,ctr);
        send(fr,fs+1,n,cs,sqn);
        usleep(1500);
        rcv(fr,fs+1,fr,e);
        s=rand()%3;
        sack(fr,ac,e);
        ctr++;
        if(k<s && (x-ctr)>=s)
        { if(s==0)
            break;
            k++;
            continue;
        }
        ack(ac,sqn,cs);
        k=0;
    }
    return 0;
}
