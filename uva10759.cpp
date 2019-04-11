// UVa 10759 - Dice Throwing
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

map<pair<ll,ll>, ll> save;

ll solve(ll x, ll n){
    if(n == 0 && x <= 0)
        return 1;
    else if(n == 0)
        return INT_MIN;

    if(save.find(make_pair(x, n)) != save.end())
        return save[make_pair(x, n)];

    ll answer = 0;
    for(int i = 1;i < 7;++i){
        ll w = solve(x - i, n - 1);
        if(w > 0)
            answer += w;
    }
    return save[make_pair(x, n)] = answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,x;
    cin >> n >> x;
    while(n != 0 || x != 0){
        save.clear();
        ll solveForWays = solve(x, n);

        ll denoPow2 = n;
        ll denoPow3 = n;

        while(solveForWays%2 == 0 && denoPow2 > 0)
            denoPow2--, solveForWays /= 2;
        while(solveForWays%3 == 0 && denoPow3 > 0)
            denoPow3--, solveForWays /= 3;

        if(solveForWays == powl(2, denoPow2) * powl(3, denoPow3))
            cout << 1 << endl;
        else if(solveForWays == 0)
            cout << 0 << endl;
        else
            cout << solveForWays << "/" << (ll)(powl(2, denoPow2) * powl(3, denoPow3)) << endl;

        cin >> n >> x;
    }

    return 0;
}
