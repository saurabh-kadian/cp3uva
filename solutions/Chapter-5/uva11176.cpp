// UVa 11176 - Winning Streak
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <cstdlib>
// #include <cstdio>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void bottomUpDp(ll len, double p){
    double dp[len + 2][len + 2];
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i <= len;++i)
        dp[0][i] = 1;

    // Now this dp is in i games win upto j games
    // if j >= i, then probability is 1
    for(int i = 1;i <= len;++i){
        for(int j = 0;j <= len;++j){
            dp[i][j] = dp[i-1][j];
            if(j == i-1)                // This means that there is only j == i case excluded i.e. all win case
                dp[i][j] -= pow(p, i);      // Wins upto i - 1, i.e. wins = 0, 1, 2, ....... , i - 1
            else if(j < i - 1 && i - j - 2 >= 0)
                dp[i][j] -= dp[i - j - 2][j] * (1-p) * pow(p, j+1);
        }
    }

    double answer = 0.0;
    // Exact ways to win j games in i is dp[i][j] - dp[i][j-1]
    for(int i = 0;i <= len;++i)
        answer += (dp[len][i] - dp[len][i-1]) * i;
    printf("%0.6lf\n", answer);
    return ;
}

void bottomUp(ll len, ll maxStreak, double p){
    // ending in a loss  - 0
    // ending in a win   - 1
    double dp[len + 2][maxStreak + 4][2];
    for(ll i = 0;i < len + 2;++i){
        for(ll j = 0;j < maxStreak + 4; ++j){
            for(ll k = 0;k < 2;++k){
                dp[i][j][k] = INT_MAX;
            }
        }
    }
    for(ll i = 1;i < len + 2;++i){
        for(ll j = 0;j < maxStreak + 4;++j){
            if(i == 1){
                if(j == 0)
                    dp[i][j][0] = 1 - p;
                else if(j == 1)
                    dp[i][j][0] = 1 - p, dp[i][j][1] = p;
                continue;
            }
            if(j > i)
                continue;
            if(j == 0)
                dp[i][j][0] = pow(1 - p, i);
            else
                dp[i][j][0] = (dp[i-1][j-1][0] + dp[i-1][j-1][1]) * (1 - p),
                    dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j-1][1] - dp[i - j + 1][j-1][1]) * p;
        }
    }

    for(int i = 0;i < len + 2;++i)
        for(int j = 0;j <= i;++j)
            for(ll k = 0;k < 2;++k)
                cout << "(" << i << ", " << j << ", " << k << ") -> " << dp[i][j][k] * (double)j << endl;
    return;
}


map<pair<ll , pair<ll, bool> >, double > save;

double solver(ll len, ll maxStreakLeft, bool maxStreakAchieved, ll &maxStreak, double &p){
    if(maxStreakLeft == 0){
        maxStreakAchieved = true;
        if(len == 0)
            return 1;
        else if(len == 1)
            return (1 - p);
        else
            return save[make_pair(len, make_pair(maxStreakLeft, maxStreakAchieved))] =
                            solver(len - 1, maxStreak, true, maxStreak, p) * (1 - p);
    }
    if(len == 0){
        if(maxStreakAchieved)
            return 1;
        else
            return 0;
    }

    if(save.find(make_pair(len, make_pair(maxStreakLeft, maxStreakAchieved))) != save.end()){
        // cout << "CALLED" << endl;
        return save[make_pair(len, make_pair(maxStreakLeft, maxStreakAchieved))];
    }

    double answer = solver(len - 1, maxStreakLeft - 1, maxStreakAchieved, maxStreak, p) * p
                        + solver(len - 1, maxStreak, maxStreakAchieved, maxStreak, p) * (1 - p);
    // cout << len << " : " << maxStreakLeft << " : " << maxStreakAchieved << " : " << maxStreak << " : " << p << endl;
    // cout << answer << endl;
    return save[make_pair(len, make_pair(maxStreakLeft, maxStreakAchieved))] = answer;
}

double solve(ll len, double &p, ll lastStreak, ll maxStreak){
    if(len == 0)
        return maxStreak;

    if(save.find(make_pair(len, make_pair(lastStreak, maxStreak))) != save.end())
        return save[make_pair(len, make_pair(lastStreak, maxStreak))];

    double answer = 0;
    if(lastStreak + 1 > maxStreak)
        answer = solve(len - 1, p, 0, maxStreak) * (1 - p) +
                    solve(len - 1, p, lastStreak + 1, lastStreak + 1) * p;
    else
        answer = solve(len - 1, p, 0, maxStreak) * (1-p) +
                        solve(len - 1, p, lastStreak + 1, maxStreak) * p;
    return save[make_pair(len, make_pair(lastStreak, maxStreak))] = answer;
}

double solveFor(ll n, double p){
    // mark for n = 1 as base case
    double win = p;
    double loss = 1.0 - p;

    vector<vector<double> > arr(n + 5, vector<double>(n + 5, 0));
    arr[1][0] = 0;
    arr[1][1] = p;

    for(int i = 2;i < n + 3;++i){
        for(int j = 0;j <= i;++j){
            if(j == 0)
                arr[i][j] = 0;
            else if(j == 1)
                arr[i][j] = (arr[i-1][j] * loss) + pow(loss, i - 1) * win;
            else if(j == i)
                arr[i][j] = (arr[i-1][j-1] * win);
            else
                arr[i][j] = ((arr[i-1][j-1] * (double)j * win) / (double)(j-1)) + (arr[i-1][j] * loss);
            cout << i << "," << j << ": " << arr[i][j] << endl;
        }
    }

    cout << arr[0][0] << endl;
    cout << arr[1][0] << " " << arr[1][1] << endl;

    double sum = 0;
    for(int i = 0;i <= n;++i)
        sum += arr[n][i];

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    double p;
    cin >> n >> p;
    while(n != 0){
        // save.clear();
        // cout << solveFor(n, p) << endl;
        // cout << solve(n, p, 0, 0) << endl;
        // double answer = 0;
        // for(ll i = 1;i <= n;++i){
        //     save.clear();
        //     bottomUp(n, i, p);
        //     double temp = solver(n, i, false, i, p) * i;
        //     // for(auto it = save.begin(); it != save.end();++it)
        //     //     cout << it->first.first << ":" << it->first.second.first << ":" << it->first.second.second << " -> " << it->second << endl;
        //     cout << i << " : "<< temp << endl;
        //     // answer += temp;
        //     break;
        // }
        // // cout << answer << endl;
        // printf("%0.6lf\n", answer);
        bottomUpDp(n, p);
        cin >> n >> p;
    }
    return 0;
}
