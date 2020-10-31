// UVa 11340 - Newspaper
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
        map<char, double> charToCents;
        double answer = 0;
        ll chars;
        cin >> chars;
        while(chars--){
            char x;
            ll w;
            cin >> x >> w;
            charToCents[x] = (double)w/(double)100;
        }
        ll lines;
        cin >> lines;
        string bogus;
        getline(cin, bogus);
        while(lines--){
            string str;
            getline(cin, str);
            // cout << str << endl;
            for(ll i = 0;i < str.length();++i)
                answer += charToCents[str[i]];
        }
        printf("%0.2lf$\n", answer);
    }
    return 0;
}
