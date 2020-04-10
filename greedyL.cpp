/*Same as coin_change_greedy.cpp but not accepts a value of number of denominations greater than l
a while loop is added which only ends while no. of denominations is less than l*/
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,l,x;
    printf("enter l");
    scanf("%d",&l);
	printf("enter no. of denominations in currency");
	scanf("%d",&n);
    //below is the loop to maintain constraint
    while(l<n)
    {
        printf("no. of denominations should be less than or eqal to l\nenter no. of denominations again");
        scanf("%d",&n);
    }
  int a[n],b[100];
	printf("enter denomination values without duplicates");
	for(i=0;i<n;i++)
      		scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
         {
           if(a[j+1]>a[j])
             {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
             }
         }

    for(i=0;i<n;i++)
     		printf("%d ",a[i]);

     printf("\nenter value x for which you need change\n");
     scanf("%d",&x);

    for(i=0;i<100;i++)
      	b[i]=0;

      i=0;
      j=0;
     while(x>=a[n-1])
     {
     	if(x>=a[j])
     		{
     			x=x-a[j];
     			b[i]=a[j];
     			i++;
            }
        else
         j++;
     }
     if(x==0)
     {
     	for(i=0;i<100;i++)
     		if(b[i]!=0)
      	   printf("%d ",b[i]);
     }
     else
     {
     	printf("\nchange doesn't exist\n");
     }
	return 0;
}
/*This algorithm fails for many cases. Eg: Denominations:9,6,5,1 value:11 Expected answer:6,5
But answer we get is 9,1,1.
To avoid this we need to backtrack, but if we backtrack it no longer becomes greedy algorithm*/
