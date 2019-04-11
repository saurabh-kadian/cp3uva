// UVa 11157 - Dynamic Frog
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll solve(vector<pair<ll, char> > rocks){
    ll minMaxJump = LLONG_MIN;
    ll leftBigRock = 0;
    for(ll i = 1;i < rocks.size();++i){
        if(rocks[i].second == 'B'){

            if((i - leftBigRock) % 2 == 0){
                // contains odd S
                for(ll j = leftBigRock + 2; j <= i;){
                    minMaxJump = max(minMaxJump, rocks[j].first - rocks[j-2].first);
                    j += 2;
                }

                // first jump is only one
                minMaxJump = max(minMaxJump, rocks[leftBigRock + 1].first - rocks[leftBigRock].first);
                for(ll j = leftBigRock + 3;j < i;){
                    minMaxJump = max(minMaxJump, rocks[j].first - rocks[j-2].first);
                    j = min(j + 2, i);
                }
                minMaxJump = max(minMaxJump, rocks[i].first - rocks[i-1].first);
            }
            else{
                // contains even S
                for(ll j = leftBigRock + 2; j < i;){
                    minMaxJump = max(minMaxJump, rocks[j].first - rocks[j-2].first);
                    j += 2;
                }

                minMaxJump = max(minMaxJump, rocks[leftBigRock + 1].first - rocks[leftBigRock].first);
                for(ll j = leftBigRock + 3;j <= i;){
                    minMaxJump = max(minMaxJump, rocks[j].first - rocks[j-2].first);
                    j += 2;
                }
                minMaxJump = max(minMaxJump, rocks[i].first - rocks[i-1].first);
            }

            leftBigRock = i;
        }
    }
    return minMaxJump;
}

int main(){
    ll testCases;
    cin >> testCases;
    for(ll testCase = 1;testCase <= testCases;++testCase){
        ll count, distance;
        cin >> count >> distance;
        vector<pair<ll, char> > rocks(count);
        for(ll i = 0;i < count;++i){
            char bs, hyphen;
            ll far;
            cin >> bs >> hyphen >> far;
            rocks[i] = make_pair(far, bs);
        }
        rocks.insert(rocks.begin(), make_pair(0, 'B'));
        rocks.insert(rocks.end(), make_pair(distance, 'B'));

        ll answer = solve(rocks);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}
