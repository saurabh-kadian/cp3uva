// UVa 11906 - Knight in War Grid
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<(i==len-1?"":" ");cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int>> coordWithParentCoord;
typedef pair<int, int> coord;

bool isValid(coord newCoord, int row, int col, vector<vector<int>>& jumpTo){
    if(newCoord.first < 0 || newCoord.first >= row || newCoord.second < 0 || newCoord.second >= col || jumpTo[newCoord.first][newCoord.second] == -2)
        return false;
    return true;
}

void dfs(coord node, int& row, int& col, 
            vector<vector<bool>>& visited, vector<vector<int>>& jumpTo, set<coord>& moves, 
            set<coord>& waterCoord){
    if(visited[node.first][node.second])
        return;
    visited[node.first][node.second] = true;
    for(auto move : moves){
        coord newNode = make_pair(node.first + move.first, node.second + move.second);
        if(isValid(newNode, row, col, jumpTo)){
            dfs(newNode, row, col, visited, jumpTo, moves, waterCoord);
            jumpTo[node.first][node.second] += 1;
        }
    }
}
int main(){
    int t = 0;
    cin >> t;
    int c = 1;
    while(t--){
        int row, col, up, right;
        cin >> row >> col >> up >> right;
        int water;
        cin >> water;
        set<coord> waterCoord;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> jumpTo(row, vector<int>(col, 0));
        for(int i = 0;i < water;++i){
            int x, y;
            cin >> x >> y;
            waterCoord.insert(make_pair(x, y));
            jumpTo[x][y] = -2;
        }
    
        coord start = make_pair(0, 0);
        jumpTo[0][0] = 0;
        set<coord> moves;
        if(up != right){
            moves.insert(make_pair(-up, right));
            moves.insert(make_pair(up, right));
            moves.insert(make_pair(up, -right));
            moves.insert(make_pair(-up, -right));
        }
        moves.insert(make_pair(-right, up));
        moves.insert(make_pair(right, up));
        moves.insert(make_pair(right, -up));
        moves.insert(make_pair(-right, -up));

        dfs(start, row, col, visited, jumpTo, moves, waterCoord);

        int even = 0, odd = 0;
        for(int i = 0;i < row;++i)
            for(int j = 0;j < col;++j)
                if(jumpTo[i][j] > 0 || (i == 0 && j == 0))  // if nowhere, starting is marked as even
                    (jumpTo[i][j]%2 ? odd++ : even++);
        cout << "Case " << c << ": " << even << " " << odd << endl;
        c += 1;
    }
    return 0;
}
