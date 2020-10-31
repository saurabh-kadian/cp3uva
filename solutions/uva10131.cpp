// UVa 10131 - Is Bigger Smarter?
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=len-1;i>=0;--i)cout<<v[i]<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void solve(vector<pair<pair<ll,ll>, ll> > weightIQ){
    vector<ll> indices(weightIQ.size(), -1);
    vector<ll> values(weightIQ.size(), 1);
    int globalMax = 0;
    for(int i = 1;i < indices.size();++i){
        int maxim = 1;
        for(int j = i-1;j >= 0;--j){
            if(weightIQ[i].first.first == weightIQ[j].first.first && weightIQ[i].first.second == weightIQ[j].first.second)
                continue;
            if(weightIQ[i].first.second < weightIQ[j].first.second && maxim <= values[j] + 1){
                values[i] = values[j] + 1;
                maxim = values[j] + 1;
                indices[i] = j;
            }
        }
        globalMax = max(globalMax, maxim);
    }

    cout << globalMax << endl;
    ll indexChain = weightIQ.size()-1;
    for(int i = weightIQ.size()-1;i >= 0;--i){
        if(globalMax == values[i]){
            indexChain = i;
            break;
        }
    }
    vector<ll> finalAnswer;
    while(indexChain != -1){
        finalAnswer.push_back(weightIQ[indexChain].second);
        indexChain = indices[indexChain];
    }
    debug(finalAnswer, finalAnswer.size());
    return ;
}

int main(){

    vector<pair<pair<ll,ll>, ll> > weightIQ;
    ll globe = 1;

    // input
    while(!cin.eof()){
        ll w,s;
        cin >> w >> s;
        weightIQ.push_back(make_pair(make_pair(w, s), globe));
        globe++;
    }

    sort(weightIQ.begin(), weightIQ.end());

    // solution
    solve(weightIQ);

    return 0;
}
