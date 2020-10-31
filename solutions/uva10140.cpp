// UVa 10140 - Prime Distance
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll topMost = 2200000000;
ll segment = sqrt(topMost);
vector<ll> primes;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll foundPrimesTill = 3;
    ll simple = 3;
    vector<bool> isPrime((ll)sqrt(topMost) + 5, true);
    primes.push_back(2);

    // Simple sieve for primes
    for(; foundPrimesTill * foundPrimesTill <= topMost; foundPrimesTill += 2){
        if(isPrime[foundPrimesTill])
            for(ll j = foundPrimesTill * foundPrimesTill;j <= sqrt(topMost) + 4; j += foundPrimesTill){
                isPrime[j] = false;
            }
    }

    // Add primes to the list
    for(; simple * simple <= topMost; simple += 2)
        if(isPrime[simple])
            primes.push_back(simple);

    ll l,u;
    while(!cin.eof()){
        cin >> l;
        if(cin.eof())
            break;
        cin >> u;
        l--;
        vector<bool> sieve(u - l + 1, true);

        // Now sieve the current segment
        for(ll i = 0;i < primes.size();++i){

            // If the starting point is lower than the current prime
            if(l < primes[i]){
                if(u < 2 * primes[i]){
                    continue;
                }
                else{
                    ll mark = 2 * primes[i];
                    for(ll k = mark;k <= u;k += primes[i])
                        if(k - l >= 0)
                            sieve[k - l] = false;
                }
            }
            else{
                ll mark = (l/primes[i]) * primes[i];
                if(mark < l)
                    mark += primes[i];
                for(ll k = mark;k <= u;k += primes[i])
                    if(k - l >= 0)
                        sieve[k - l] = false;
            }
        }

        // Pick out primes from the segment
        vector<ll> finalPrime;
        ll maxDist = -1;
        ll minDist = LLONG_MAX;
        pair<ll,ll> maxPair(0, 0);
        pair<ll,ll> minPair(0, 0);
        for(ll marker = l;marker <= u;marker++){
            if(sieve[marker - l] && marker != 1 && marker != 0){
                finalPrime.push_back(marker);
                if(finalPrime.size() > 1){
                    if(finalPrime[finalPrime.size() - 1] - finalPrime[finalPrime.size() - 2] > maxDist)
                        maxDist = finalPrime[finalPrime.size() - 1] - finalPrime[finalPrime.size() - 2],
                            maxPair.first = finalPrime[finalPrime.size() - 2],
                            maxPair.second = finalPrime[finalPrime.size() - 1];
                    if(finalPrime[finalPrime.size() - 1] - finalPrime[finalPrime.size() - 2] < minDist)
                        minDist = finalPrime[finalPrime.size() - 1] - finalPrime[finalPrime.size() - 2],
                            minPair.first = finalPrime[finalPrime.size() - 2],
                            minPair.second = finalPrime[finalPrime.size() - 1];
                }
            }
        }

        if(maxDist == -1)
            cout << "There are no adjacent primes." << endl;
        else
            cout << minPair.first << "," << minPair.second << " are closest, " << maxPair.first << "," << maxPair.second << " are most distant." << endl;

    }

    return 0;
}
