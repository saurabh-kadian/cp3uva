// UVa 10306 - e-Coins
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll makeGlobal = 0;
map<pair<ll, pair<ll,ll> >, ll > save;

ll solve(vector<pair<ll,ll> >& coinsCONvIT, ll index, ll conv, ll eval){
    if(index == coinsCONvIT.size()){
        // cout << index << " " << conv << " " << eval << endl;
        if(powl(conv, 2) + powl(eval, 2) == makeGlobal)
            return 0;
        else
            return INT_MAX;
    }
    
    if(save.find(make_pair(index, make_pair(conv, eval))) != save.end())
        return save[make_pair(index, make_pair(conv, eval))];

    ll answer = min((ll)INT_MAX, solve(coinsCONvIT, index + 1, conv, eval));
    for(int i = 1; powl(conv + i * coinsCONvIT[index].first, 2) + powl(eval + i * coinsCONvIT[index].second, 2) <= makeGlobal; ++i)
        answer = min(answer, i + solve(coinsCONvIT, index + 1, conv + i * coinsCONvIT[index].first, eval + i * coinsCONvIT[index].second));
    return save[make_pair(index, make_pair(conv, eval))] = answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        save.clear();
        ll n,s;
        cin >> n >> s;
        vector<pair<ll,ll> > coinsCONvIT(n);
        s = s * s;
        makeGlobal = s;
        for(int i = 0;i < n;++i)
            cin >> coinsCONvIT[i].first >> coinsCONvIT[i].second;
        ll answer = solve(coinsCONvIT, 0, 0, 0);
        if(answer >= INT_MAX)
            cout << "not possible" << endl;
        else
            cout << answer << endl;
    }

    return 0;
}
