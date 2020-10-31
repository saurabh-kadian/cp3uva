// UVa 10721 - Bar Codes

#include<bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

map<string, ll> save;

ll solve(ll i, ll x, ll s, ll& n, ll& k, ll& m){
    if(i == n + 1){
        if(x == k && s <= m){
            return 1;
        } else {
            return 0;
        }
    }
    if(i > n){
        return 0;
    }
    if(x > k){
        return 0;
    }
    if(s > m){
        return 0;
    }
    stringstream ss;
    ss << i << "-" << x << "-" << s;
    string str = ss.str();
    if(save.find(str) != save.end()){
        return save[str];
    }
    return save[str] = solve(i + 1, x, s + 1, n, k, m) + solve(i + 1, x + 1, 1, n, k, m);
}

int main(){
    ll n,k,m;
    cin >> n >> k >> m;
    while(!cin.eof()){
        save.clear();
        cout << solve(2, 1, 1, n, k, m) << endl;
        cin >> n >> k >> m;
    }
    return 0;
}
