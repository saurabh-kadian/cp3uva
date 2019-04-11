// UVa 272 - TeX Quotes
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
    bool first = true;
    char ch;
    ch = cin.get();
    while(ch != EOF){
        if(ch == '\"'){
            if(first)
                first = false, cout << "``";
            else
                first = true, cout << "''";
        }
        else
            cout << ch;
        ch = cin.get();
    }
    return 0;
}
