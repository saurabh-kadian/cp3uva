// UVa 146 - ID Codes
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    while(str != "#"){
        string copy = str;
        next_permutation(str.begin(), str.end());
        sort(copy.begin(), copy.end());
        if(copy == str)
            cout << "No Successor" << endl;
        else
            cout << str << endl;
        cin >> str;
    }

    return 0;
}
