#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileio freopen("input.in","r",stdin);freopen("output.out","w",stdout);
const long long MOD=1e9+7;

int main()
{
	fastio
	fileio
	long long t,n,m,k;
	cin>>t;
	long long ans;
	for(int tt=1;tt<=t;tt++)
	{
		cin>>n>>m>>k;
		if(!(n>k && m>k))
			ans=-1;
		else if(!(max(n,m)>((long long)2*(k+(long long)1))))
			ans=-1;
		else
			ans=(long long)ceil((double)min(n,m)/(double)k);

		if(k==1)
			ans=min(ans,(long long)5);
		else
			ans=min(ans,(long long)4);

		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	
	return 0;
}