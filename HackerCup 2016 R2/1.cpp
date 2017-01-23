#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileio freopen("input.in","r",stdin);freopen("output.out","w",stdout);
const long long MOD=1e9+7;

int main()
{
	fastio
	fileio
	string a,b;
	int n;
	int t;
	int l[100009],r[100009],ul[100009],ur[100009],j;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cin>>n;
		cin>>a;
		cin>>b;
		ul[0]=1;
		ur[b.length()-1]=1;
		for(int i=1;i<=b.length();i++)
		{
			ul[i]=ul[i-1];
			if(b[i]!=b[i-1])
				ul[i]++;

			j=n-i-1;
			ur[j]=ur[j+1];
			if(b[j]!=b[j+1])
				ur[j]++;

		}
		int lm=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
				lm=i;
			if(lm==-1)
				l[i]=0;
			else
				l[i]=ul[lm];
		}
		lm=-1;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]!=b[i])
				lm=i;
			if(lm==-1)
				r[i]=0;
			else
				r[i]=ur[lm];
		}
		int ans=r[0];
		for(int i=1;i<n;i++)
		{
			ans=min(ans,max(l[i-1],r[i]));
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;

		
	}
	return 0;
}