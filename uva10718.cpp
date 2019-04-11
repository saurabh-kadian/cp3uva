// UVa 10718 - Bit Mask
// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <cstdio>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef unsigned int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,l,u;
    while(!cin.eof()){
        cin >> n;
        if(cin.eof())
            break;
        cin >> l >> u;
        ll maxval = n|l;
        ll maxFor = l;
        bitset<32> forN(n), forM(0);

        // Moving from MSB to LSB
        // If N == 1 we can set bit to 0 and see if it can be between L and U if possible move ahead
        // Check if it can be more than L
        // If N == 0 we can set bit to 1 and see if it can be between L and U if possible move ahead
        // Check if it can be less than U

        for(int i = 31;i >= 0;--i){
            if(forN[i] == 1){
                forM[i] = 0;
                for(int j = i - 1;j >= 0;--j)
                    forM[j] = 1;
                if(forM.to_ulong() < l)
                    forM[i] = 1;
                for(int j = i - 1;j >= 0;--j)
                    forM[j] = 0;
            }
            else{
                forM[i] = 1;
                if(forM.to_ulong() > u)
                    forM[i] = 0;
            }
        }

        cout << forM.to_ulong() << endl;

    }

    return 0;
}
