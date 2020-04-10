#include<bits/stdc++.h>

using namespace std;

/*To find the minimum number of scalar multiplications (for the sake of simplicity represented as multiplication henceforth) in a chain of matrices represented by their dimensions*/

/*
The matrices will be represented by their dimensions in an array
The dimensions of the matrix will be p[i-1] x p[i]
For the sake of simplicity, we will add an extra row and column to m[][] and thus not use the 0th row and 0th column
Here m[i][j] will represent the minimum number of multiplications required to compute the product A[i]*A[i+1].....*A[j] where A[] is the matrix and dimension of A[i] will be p[i-1] x p[i]
*/


/*
The below function returns the minimum number of multiplications required to multiply the chain of matrices represented by the dimensions given in p[]
*/

int MatrixChainMultiply(int p[],int n)
{
	int m[n][n];
	
	int i,j,k,L,q;
	
	/*
	L - length of the chain to be multiplied in the iteration i.e. number of matrices being multiplied
	q - the cost/multiplication 
	*/
	
	/*When multiplying only one matrix the cost is 0 i.e. m[i][i]=0*/
	for(i = 1; i < n; i++)
	{
		m[i][i] = 0;
	}
	
	for(L = 2; L < n; L++)
	{
		for(i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j]=INT_MAX;
			for(k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
				}
			}
		}
	}
	
	return m[1][n-1];
	
}

int main()
{
	int n;
	cout<<"Enter the number of matrices to be multiplied"<<endl;
	cin>>n;
	int p[n];
	cout<<"Enter the array dimensions in order"<<endl;
	int s;
	for(s = 0; s < n; s++)
	{
		cin>>p[s];
	}
	cout<<"The minimum number of multiplications required for the given chain of matrices is "<<MatrixChainMultiply(p,n)<<endl;
	return 0;
}
