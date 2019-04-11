// UVa 11498 - Division of Nlogonia
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
	ll k;
	cin >> k;
	while(k){
		ll centerX, centerY;
		cin >> centerX >> centerY;
		while(k--){
			ll x,y;
			cin >> x >> y;
			if(x > centerX){
				if(y > centerY){
					cout << "NE" << endl;
				}
				else if(y < centerY){
					cout << "SE" << endl;
				}
				else{
					cout << "divisa" << endl;
				}
			}
			else if(x < centerX){
				if(y > centerY){
					cout << "NO" << endl;
				}
				else if(y < centerY){
					cout << "SO" << endl;
				}
				else{
					cout << "divisa" << endl;
				}
			}
			else{
				cout << "divisa" << endl;
			}
		}
		cin >> k;
	}
	return 0;
}
