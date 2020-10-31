// UVa 11566 - Let’s Yum Cha!

#include <bits/stdc++.h>
#include <map>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef double db;
typedef long long li;
typedef vector<db> vdb;

// Gives TLE
// map<pair<db, pair<db, db> >, db > save;
db dp[1005][105][25] = {0};

li solveTopDown(li money, li index, li totalDimsum, vector<li>& priceDimsum, vector<li>& preference){
   // base case
       if(money < 0 || totalDimsum < 0)
           return INT_MIN;
       if(index == priceDimsum.size())
           return 0;
   // memoization
       if(dp[money][index][totalDimsum] != 0)
           return dp[money][index][totalDimsum];
       // if(save.find(make_pair(money, make_pair(index, totalDimsum))) != save.end())
       //     return save[make_pair(money, make_pair(index, totalDimsum))];

   // recurrence
       li value = max(solveTopDown(money, index + 1, totalDimsum, priceDimsum, preference),
                       max(solveTopDown(money - priceDimsum[index], index + 1, totalDimsum - 1, priceDimsum, preference) + preference[index],
                           solveTopDown(money - priceDimsum[index] * 2, index + 1, totalDimsum - 2, priceDimsum, preference) + preference[index] * 2));
       return dp[money][index][totalDimsum] = value;
       // return save[make_pair(money, make_pair(index, totalDimsum))] = value;
}

int main(){
     // friends, maxPay, teaPrice, dimsums
     db N, x, T, K;
     cin >> N >> x >> T >> K;

     while(!(N == 0 && x == 0 && T == 0 && K == 0)){
       // Clear memo
       // save.clear();
       fill(&dp[0][0][0], &dp[1005][0][0], 0);

       // Add myself to the list of people
       N++;

       // input dimsums
       vector<li> preference(K), priceDimsum(K);
       for(int i = 0;i < K;++i){
         cin >> priceDimsum[i];
         li temp, total = 0;
         for(int j = 0;j < N;++j){
           cin >> temp;
           total += temp;
         }
         preference[i] = total;
       }

       // Process 10% service tax as 10% decrease in money
       db money = floor((x * N)/(1.1) + 1e-6) - T * N;

       // solution
       db answer = solveTopDown(money, 0, 2 * N, priceDimsum, preference);
       printf("%0.2f\n", (double)answer/(double)N);

       cin >> N >> x >> T >> K;

    }


   return 0;
}
