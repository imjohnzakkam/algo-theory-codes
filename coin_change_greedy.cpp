#include<bits/stdc++.h>

using namespace std;

int* min_greedy(int a[],int n,int val)
{

    int *result=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        result[i]=0;

    int ct=n-1;
    while(ct>-1)
    {
        if(val-a[ct]>=0)
        {
            val-=a[ct];
            result[ct]++;
        }
        else
        {
            ct--;
        }
    }
    if(val==0)
        return(result);
    else
        return NULL;
    
}

int main()
{
    cout<<"please enter the number of denominations";
    int n;
    cin>>n;

    int a[n];
    cout<<"please enter the value of the denominations";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    cout<<"please enter the value for which you require change";
    int val;
    cin>>val;
    int*result=min_greedy(a,n,val);
    if(result==NULL)
    {
        cout<<"no way possible";
        exit(0);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" : "<<result[i]<<'\n';
}