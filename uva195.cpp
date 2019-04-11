// UVa 195 - Anagram
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

bool comp(char a, char b){
    if(tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        string test;
        cin >> test;
        sort(test.begin(), test.end(), comp);
        do{
            cout << test << endl;
        }while(next_permutation(test.begin(), test.end(), comp));
    }

    return 0;
}
