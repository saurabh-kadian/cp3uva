// UVa 11517 - Exact Change
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void bottomUpSimple(vector<ll>& deno, ll &change){
    ll maxE = (*max_element(deno.begin(), deno.end()));
    ll rightIndex = change + maxE + 2;
    ll dp[rightIndex];
    for(int i = 0;i < rightIndex;++i)
        dp[i] = INT_MAX;

    dp[0] = 0;

    // // Works for sample cases, don't know why it gives wrong answer
    // for(int j = 0;j < deno.size();++j)
    //     for(int i = rightIndex;i >= 0;--i)                          // Reverse because if 0 + c is true then 0 + c + c is also true
    //         if(i - deno[j] >= 0 && dp[i - deno[j]] < INT_MAX)       // Because we are checking from previous values we need to loop in
    //             dp[i] = min(dp[i], dp[i - deno[j]] + 1);            // other direction

    // And this works ... 
    for(int j = 0;j < deno.size();++j)
        for(int i = rightIndex - maxE - 1; i >= 0;--i)
            dp[i + deno[j]] = min(dp[i + deno[j]], dp[i] + 1);

    for(int i = change;i < rightIndex;++i){
        if(dp[i] < INT_MAX){
            cout << i << " " << dp[i] << endl;
            break;
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll change;
        cin >> change;
        ll coins;
        cin >> coins;
        vector<ll> deno(coins);
        for(ll i = 0;i < coins;++i)
            cin >> deno[i];
        bottomUpSimple(deno, change);
    }

    return 0;
}
