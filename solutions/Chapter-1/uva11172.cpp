// UVa 11172 - Relational Operator
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		cout << (a > b ? '>' : (a < b ? '<' : '=')) << endl;
	}
	return 0;
}
