// UVa 156 - Ananagrams
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

    map<string, ll> answer;
    map<string, string> mapper;
    string input;
    cin >> input;
    while(input != "#"){
        string temp = input;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        sort(temp.begin(), temp.end());
        mapper[temp] = input;
        answer[temp]++;
        cin >> input;
    }

    set<string> ans;

    for(map<string, ll>::iterator it = answer.begin(); it != answer.end();++it)
        if(it->second == 1)
            ans.insert(mapper[it->first]);

    for(set<string>::iterator it = ans.begin();it != ans.end();++it)
        cout << *it << endl;

    return 0;
}
