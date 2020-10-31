// UVa 10189 - Minesweeper
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int mines(vector<vector<bool> >& convolute){
    if(convolute[1][1] == true)
        return -1;
    int mine = 0;
    for(int i = 0;i < 3;++i)
        for(int j = 0;j < 3;++j)
            mine += (convolute[i][j] ? 1 : 0);
    return mine;
}

int main(){
    vector<vector<bool> > convolute(3, vector<bool>(3, false));
    ll field = 1;
    ll n,m;
    cin >> n >> m;
    while(n != 0 && m != 0){
        vector<vector<bool> > grid(n + 2, vector<bool>(m+2, false));
        vector<string> input(n);
        for(int i = 0;i < n;++i)
            cin >> input[i];
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                char x = input[i-1][j-1];
                if(x == '*')
                    grid[i][j] = true;
                else
                    grid[i][j] = false;
            }
        }
        vector<vector<int> > finalGrid(n, vector<int>(m, '.'));
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                convolute[0][0] = grid[i-1][j-1];
                convolute[0][1] = grid[i-1][j];
                convolute[0][2] = grid[i-1][j+1];
                convolute[1][0] = grid[i][j-1];
                convolute[1][1] = grid[i][j];
                convolute[1][2] = grid[i][j+1];
                convolute[2][0] = grid[i+1][j-1];
                convolute[2][1] = grid[i+1][j];
                convolute[2][2] = grid[i+1][j+1];
                finalGrid[i-1][j-1] = mines(convolute);
                fill(convolute.begin(), convolute.end(), vector<bool>(3, false));
            }
        }
        cout << "Field #" << field << ":" << endl;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(finalGrid[i][j] == -1)
                    cout << "*";
                else
                    cout << finalGrid[i][j];
            }
            cout << endl;
        }
        field++;
        cin >> n >> m;
        if(n !=0 && m != 0)
            cout << endl;
    }
    return 0;
}
