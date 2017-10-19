#include<bits/stdc++.h>

using namespace std;

long long ans[1<<20] = {1LL};

void solve()
{
	int s[21]={};
	int n, m, N;
	scanf("%d%d",&n,&m);
	N = 1 << n;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		s[x]|=1<<(y-1);
	}
	for(int i = 1; i < N; i++)
	{
		int p = __builtin_popcount(i);
		ans[i] = 0;
		for(int j = 1; j < N; j <<=1)
			if((j & i) && !(j & s[p]))
				ans[i]+=ans[i^j];
	}
	printf("%lld\n",ans[N-1]);
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
		solve();
	return 0;
}

