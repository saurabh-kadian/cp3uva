// UVa 374 - Big Mod
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll powerMod(ll b, ll p, ll m){
    if(p == 1)
        return b%m;
    else if(p == 2)
        return (b%m * b%m) % m;
    if(p%2 == 0){
         ll half = powerMod(b, p/2, m);
         return (half%m * half%m) % m;
    }
    return (powerMod(b, p-1, m)%m * b%m)%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll b,p,m;
    while(!cin.eof()){
        cin >> b;
        if(cin.eof())
            break;
        cin >> p >> m;
        if(p == 0)
            cout << 1 % m << endl;
        else
            cout << powerMod(b, p, m) % m << endl;
    }

    return 0;
}
