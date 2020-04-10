/*Same as 1_dpcoin.cpp but not accepts a value of number of denominations greater than l
a while loop is added which only ends while no. of denominations is less than l*/
#include<bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return(a<b?a:b);
}

int* min_dp(int a[],int n,int val)
{
    int arr[val+1]={0},res[val+1][n]={0};

     for(int j=val;j>=0;j--)
        {
            for(int i=0;i<n;i++)
                res[i][j]=0;
        }  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=val;j++)
        {
            if(!(a[i]>j))
            {
                int tmp;

                tmp=min(arr[j-a[i]]==0 && j-a[i]!=0 ? 0 : arr[j-a[i]]+1,arr[j]);
                if(tmp!=arr[j])
                {
                    for(int k=0;k<n;k++)
                    {
                        res[j][k]=res[j-a[i]][k];
                        if(k==i)
                            res[j][k]++;
                    }
                }

                arr[j]=tmp;
            }

        }
             
    }
    cout<<"\nRESULT:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" : "<<res[val][i]<<"\n";
}

int main()
{   int n,l;
    cout<<"enter l";
    cin>>l;
    cout<<"please enter the number of denominations";
    cin>>n;

    //below is the loop to maintain constraint
    while(l<n)
    {
        printf("no. of denominations should be less than or eqal to l\nenter no. of denominations again");
        scanf("%d",&n);
    }
    
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

    min_dp(a,n,val);
}
