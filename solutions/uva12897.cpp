// UVa 12897 - Decoding Baby Boos
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
    ll t;
    cin >> t;
    while(t--){
        map<char, char> mapping;
        string str;
        cin >> str;
        ll n;
        cin >> n;
        while(n--){
            char a,b;
            cin >> a >> b;
            if(mapping.find(b) == mapping.end())
                mapping[b] = a;
            for(map<char, char>::iterator it = mapping.begin();it != mapping.end();++it)
                if(it->second == b)
                    it->second = a;
        }
        for(int i = 0;i < str.length();++i)
            if(mapping.find(str[i]) != mapping.end())
                str[i] = mapping[str[i]];
        cout << str << endl;
    }
    return 0;
}
