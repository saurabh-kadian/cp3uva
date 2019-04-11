// UVa 531 - Compromise
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll dp[105][105] = {0};
vector<string> answer, firstPolit, secondPolit;

pair<ll, ll> LCS(vector<string>& firstPolit, vector<string>& secondPolit){

    for(ll i = 1;i <= firstPolit.size();++i){
        for(ll j = 1;j <= secondPolit.size();++j){
                if(firstPolit[i - 1] == secondPolit[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return make_pair(firstPolit.size(), secondPolit.size());
}

void makeSentence(ll i, ll j, vector<string>& first, vector<string>& second){
    if(i == 0 || j == 0)
        return;
    if(first[i - 1] == second[j - 1]){
        makeSentence(i - 1,j - 1, first, second);
        answer.push_back(first[i - 1]);
    }
    else if(dp[i - 1][j] > dp[i][j - 1])
        makeSentence(i - 1, j, first, second);
    else
        makeSentence(i, j - 1, first, second);
}

int main(){
    string temp;
    while (cin >> temp) {
        memset(dp, 0, sizeof(dp));
        firstPolit.clear();
        secondPolit.clear();
        answer.clear();

        firstPolit.push_back(temp);
        while (cin >> temp && temp != "#")
            firstPolit.push_back(temp);
        while (cin >> temp && temp != "#")
            secondPolit.push_back(temp);

        pair<ll,ll> rowCol = LCS(firstPolit, secondPolit);
        makeSentence(rowCol.first, rowCol.second, firstPolit, secondPolit);
        if(answer.size() > 0){
            for (ll i = 0; i < answer.size() - 1; i++)
                cout << answer[i] << " ";
            cout << answer[answer.size()-1] << endl;
        }
    }
    return 0;
}
