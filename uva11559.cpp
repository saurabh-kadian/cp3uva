// UVa 11559 - Event Planning
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<int> vll;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	int n,b,h,w;
	while(scanf("%ld %ld %ld %ld",&n,&b,&h,&w) != EOF){
		// cin >> n >> b >> h >> w;
		int minToLive = INT_MAX;
		while(h--){
			int cost;
			scanf("%d", &cost);
			// cin >> cost;
			int week = w;
			while(week--){
				int x;
				scanf("%d", &x);
				// cin >> x;
				if(x >= n && cost*n <= b)
					minToLive = min(minToLive, cost*n);
			}
		}
		if(minToLive == INT_MAX)
			printf("stay home\n");
		else
			printf("%d\n", minToLive);
	}
	return 0;
}
