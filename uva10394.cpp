// UVa 10394 - Twin Primes
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

// Uppermost limit
ll topMost = 20000005;

// Sieve segment size
ll segment = sqrt(topMost);

// Primes for sieving
vector<ll> primes;

// Final List of primes
vector<ll> finalPrime;

// List of twin primes
vector<pair<ll,ll> > twins;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // This problem needs to generate segmented sieve for primes generation
    // This implementation is not the fastest

    // Let's first define the size of the segment
        // If we want to find till n, the best size is of max(sqrt(n), L1_Cache) of the system

    // For simplicity sake, we are keeping 100001

    // We need primes till sqrt(n) to sieve all the numbers till n

    // i.e. at every iteration, find the primes till sqrt(upperLimit)

    vector<bool> sieve(segment, true);
    vector<bool> isPrime((ll)sqrt(topMost) + 5, true);

    ll lowerLimit = 0;
    ll foundPrimesTill = 3;
    ll marker = 3;
    ll simple = 3;

    // Push 2 as prime so we can loop on only odd numbers
    primes.push_back(2);
    finalPrime.push_back(2);

    for(;lowerLimit <= topMost;lowerLimit += segment){

        ll upperLimit = lowerLimit + segment - 1;
        upperLimit = min(upperLimit, topMost);

        fill(sieve.begin(), sieve.end(), true);

        // Simple sieve for primes
        for(; foundPrimesTill * foundPrimesTill <= upperLimit; foundPrimesTill += 2){
            if(isPrime[foundPrimesTill])
                for(ll j = foundPrimesTill * foundPrimesTill;j <= sqrt(topMost) + 4; j += foundPrimesTill){
                    isPrime[j] = false;
                }
        }

        // Add primes to the list
        for(; simple * simple <= upperLimit; simple += 2)
            if(isPrime[simple])
                primes.push_back(simple);

        // Now sieve the current segment
        for(ll i = 0;i < primes.size();++i){

            // If the starting point is lower than the current prime
            if(lowerLimit < primes[i]){
                if(upperLimit < 2 * primes[i]){
                    continue;
                }
                else{
                    ll mark = 2 * primes[i];
                    for(ll k = mark;k <= upperLimit;k += primes[i])
                        if(k - lowerLimit >= 0)
                            sieve[k - lowerLimit] = false;
                }
            }
            else{
                ll mark = (lowerLimit/primes[i]) * primes[i];
                if(mark < lowerLimit)
                    mark += primes[i];
                for(ll k = mark;k <= upperLimit;k += primes[i])
                    if(k - lowerLimit >= 0)
                        sieve[k - lowerLimit] = false;
            }
        }

        // Pick out primes from the segment
        ll previousSize = finalPrime.size();
        for(;marker <= upperLimit;marker++){
            if(marker - lowerLimit >= 0)
                if(sieve[marker - lowerLimit])
                    finalPrime.push_back(marker);
        }

        // Pick out twin primes
        ll newSize = finalPrime.size();
        for(ll w = previousSize - 1;w < newSize - 1;++w)
            if(finalPrime[w] + 2 == finalPrime[w + 1])
                twins.push_back(make_pair(finalPrime[w], finalPrime[w + 1]));
    }

    ll q;
    while(!cin.eof()){
        cin >> q;
        q--;
        if(cin.eof())
            break;
        printf("(%lld, %lld)\n", twins[q].first, twins[q].second);
    }

    return 0;
}
