// UVa 11831 - Sticket Collector Robot
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

enum Direction{
    UP,    // N
    DOWN,  // S
    LEFT,  // O
    RIGHT  // L
};

enum Instruction{
    TURN_RIGHT, // D
    TURN_LEFT,  // E
    MOVE   // F
};

Instruction mapInstruction(char instruction){
    switch(instruction){
        case 'D':
            return Instruction::TURN_RIGHT;
        case 'E':
            return Instruction::TURN_LEFT;
        case 'F':
            return Instruction::MOVE;
    }
    // return Instruction::TURN_RIGHT;
}

Direction mapDirection(char direction){
    switch(direction){
        case 'N':
            return Direction::UP;
        case 'S':
            return Direction::DOWN;
        case 'L':
            return Direction::RIGHT;
        case 'O':
            return Direction::LEFT;
    }
    // return Direction::UP;
}

Direction executeDirection(Direction direction, Instruction instruction){
    switch(instruction){
        case Instruction::TURN_RIGHT:
            switch(direction){
                case Direction::UP:
                    return Direction::RIGHT;
                case Direction::DOWN:
                    return Direction::LEFT;
                case Direction::RIGHT:
                    return Direction::DOWN;
                case Direction::LEFT:
                    return Direction::UP;
            }
        case Instruction::TURN_LEFT:
            switch(direction){
                case Direction::UP:
                    return Direction::LEFT;
                case Direction::DOWN:
                    return Direction::RIGHT;
                case Direction::RIGHT:
                    return Direction::UP;
                case Direction::LEFT:
                    return Direction::DOWN;
            }
        case Instruction::MOVE:
            return direction;
    }
    // return Direction::UP;
}

pair<int, int> applyDelta(Direction& direction, pair<int, int> position){
    switch(direction){
        case Direction::UP:
            return make_pair(position.first - 1, position.second + 0);
        case Direction::LEFT:
            return make_pair(position.first + 0, position.second - 1);
        case Direction::DOWN:
            return make_pair(position.first + 1, position.second + 0);
        case Direction::RIGHT:
            return make_pair(position.first + 0, position.second + 1);
    }
}

void executeMove(pair<int, int>& position, Instruction& instruction, vector<string>& grid, Direction& direction){
    int row = grid.size();
    int col = grid[0].size();
    pair<int, int> newPosition = make_pair(position.first, position.second);
    newPosition = applyDelta(direction, newPosition);
    if(newPosition.first < 0 || newPosition.first >= row || newPosition.second < 0 || newPosition.second >= col){
        return ;
    }
    if(grid[newPosition.first][newPosition.second] == '#'){
        return ;
    }
    position = make_pair(newPosition.first, newPosition.second);
}

void execute(Direction& robotDirection, Instruction& instruction, pair<int, int>& position, vector<string>& grid, int& stickers){
    robotDirection = executeDirection(robotDirection, instruction);
    if(instruction == Instruction::MOVE)
        executeMove(position, instruction, grid, robotDirection);
    if(grid[position.first][position.second] == '*'){
        grid[position.first][position.second] = '.';
        stickers += 1;
    }
}

int main(){
    int row, col, numberOfInstructions;
    cin >> row >> col >> numberOfInstructions;
    while(row != 0 && col != 0 && numberOfInstructions != 0){
        vector<string> grid(row);
        for(int i = 0;i < row;++i)
            cin >> grid[i];
        pair<int, int> position;
        Direction robotDirection;
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j){
                if(grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O'){
                    position = make_pair(i, j);
                    robotDirection = mapDirection(grid[i][j]);
                }
            }
        }
        int stickers = 0;
        string instructions;
        cin >> instructions;
        for(int i = 0;i < instructions.size();++i){
            Instruction instruction = mapInstruction(instructions[i]);
            execute(robotDirection, instruction, position, grid, stickers);
        }
        cout << stickers << endl;
        cin >> row >> col >> numberOfInstructions;
    }
    return 0;
}
