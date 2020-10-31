// UVa 10337 - Flight planner
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

vector<vector<ll> > windIndex;
map<pair<ll, ll>, ll> save;

ll call_recursion(ll current_altitude, ll step, ll& const_row_entries){
    // Base
    if(step == const_row_entries && current_altitude == 0)
        return 0;
    else if(step == const_row_entries)
        return 1e6;
    // Memoization
    if(save.find(make_pair(current_altitude, step)) != save.end())
        return save[make_pair(current_altitude, step)];
    // Recursion
        ll answer = LLONG_MAX;
        // Go up
        if(current_altitude < 9)
            answer = min(answer, call_recursion(current_altitude + 1, step + 1, const_row_entries) - windIndex[current_altitude][step] + 60);
        // Go down
        if(current_altitude > 0)
            answer = min(answer, call_recursion(current_altitude - 1, step + 1, const_row_entries) - windIndex[current_altitude][step] + 20); 
        // Hold
        answer = min(answer, call_recursion(current_altitude, step + 1, const_row_entries) - windIndex[current_altitude][step] + 30);
        return save[make_pair(current_altitude, step)] = answer;
}

int main(){

    ll t;
    cin >> t;
    while(t--){
        ll answer = 0;
        ll x;
        cin >> x;
        ll row_entires = x/100;
        ll init_alt = 0;
        windIndex.clear();
        save.clear();
        windIndex = vector<vector<ll> >(10, vector<ll>(row_entires, 0));
        for(int i = 9;i >=0;--i){
            for(int j = 0;j < row_entires;++j){
                cin >> windIndex[i][j];
            }
        }

        answer = call_recursion(0, 0, row_entires);
        cout << answer << endl << endl;
    }

    return 0;
}



/*
sample input: 
=============
2
400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1
1000
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
7 7 7 7 7 7 7 7 7 7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9
 * 
 sample output:
 ==============
 120
 354
 * 
 */