#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int max(int a, int b);
int lcs(char *X, char *Y, int m , int n)
{
	if(m==0||n==0)
	return 0;

	int L[m+1][n+1];
	for(int i=0;i<=m;i++)
	{

		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
			L[i][j]=0;

			else if(X[i-1]==Y[j-1]) L[i][j]=L[i-1][j-1]+1;
			else 
			{
				L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	int index=L[m][n];
	char lcs[index+1];
	lcs[index]='\0';
	int a=m;int b=n;
	while(a>0 && b>0)
	{
		if(X[a-1]==Y[b-1])
		{
			lcs[index-1]=X[a-1];
			a--;b--;index--;
		}
		else if(L[a][b-1]>L[a-1][b])
		b--;
		else 
		a--;
	}
	cout<<lcs;

}


int max( int a, int b)
{
	return (a>b)?a:b;
}

main()
{
	char X[]= "abcd";
	char Y[]= "aebcf";
	int m= strlen(X);
	int n=strlen(Y);
	lcs(X,Y,m,n);


}
