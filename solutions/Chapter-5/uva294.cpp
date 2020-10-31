// UVa 294 - Divisors
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

vector<ll> primes;

void makePrimes(ll n){
    bool visit[n];
    fill(visit, visit + n, true);
    for(ll i = 2;i*i <= n;++i){
        if(visit[i]){
            for(ll j = i*i;j <= n;j += i){
                visit[j] = false;
            }
        }
    }
    for(ll i = 2;i <= n;++i)
        if(visit[i])
            primes.push_back(i);
}

ll count(ll n){
    ll answer = 1;
    for(int i = 0;i < primes.size();++i){
        if(n == 1)
            break;
        ll counter = 0;
        while(n % primes[i] == 0)
            n /= primes[i], counter++;
        answer *= (counter + 1);
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    makePrimes(1e6 + 5);

    ll t;
    cin >> t;
    while(t--){
        ll lower, upper;
        cin >> lower >> upper;
        ll max = 1;
        ll number = lower;
        for(ll i = lower; i <= upper;++i){
            ll counter = count(i);
            if(counter > max)
                max = counter, number = i;
        }
        cout << "Between " << lower << " and " << upper << ", " << number << " has a maximum of " << max << " divisors." << endl;
    }

    return 0;
}
