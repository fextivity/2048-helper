#include <bits/stdc++.h>
using namespace std;

#define N 4

typedef array <array <int, N>, N> Board;

bool CanMoveUp(const Board& board){
    for (int y = 0; y < N; y++){
        for (int x = 1; x < N; x++){
            if (board[x][y] > 0 and board[x - 1][y] == 0){
                return true;
            }
            if (board[x][y] != 0 and board[x][y] == board[x - 1][y]){
                return true;
            }
        }
    }
    return false;
}

bool CanMoveLeft(const Board& board){
    for (int x = 0; x < N; x++){
        for (int y = 1; y < N; y++){
            if (board[x][y] > 0 and board[x][y - 1] == 0){
                return true;
            }
            if (board[x][y] != 0 and board[x][y] == board[x][y - 1]){
                return true;
            }
        }
    }
    return false;
}

bool CanMoveDown(const Board& board){
    for (int y = 0; y < N; y++){
        for (int x = 1; x < N; x++){
            if (board[x][y] == 0 and board[x - 1][y] > 0){
                return true;
            }
            if (board[x][y] != 0 and board[x][y] == board[x - 1][y]){
                return true;
            }
        }
    }
    return false;
}

bool CanMoveRight(const Board& board){
    for (int x = 0; x < N; x++){
        for (int y = 1; y < N; y++){
            if (board[x][y] == 0 and board[x][y - 1] > 0){
                return true;
            }
            if (board[x][y] != 0 and board[x][y] == board[x][y - 1]){
                return true;
            }
        }
    }
    return false;
}

signed main(){
    Board board;
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            cin >> board[x][y];
        }
    }
    bool lr = 0;
    while (board[0][0] >= 0){
        if (!lr){
            if (CanMoveRight(board)){
                lr = 1;
                cout << "R" << endl;
                for (int x = 0; x < N; x++){
                    for (int y = 0; y < N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
            if (CanMoveLeft(board)){
                lr = 0;
                cout << "L" << endl;
                for (int x = 0; x < N; x++){
                    for (int y = 0; y < N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
        }
        else{
            if (CanMoveLeft(board)){
                lr = 0;
                cout << "L" << endl;
                for (int x = 0; x < N; x++){
                    for (int y = 0; y < N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
            if (CanMoveRight(board)){
                lr = 1;
                cout << "R" << endl;
                for (int x = 0; x < N; x++){
                    for (int y = 0; y < N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
        }
        if (CanMoveUp(board)){
            cout << "U" << endl;
            for (int x = 0; x < N; x++){
                for (int y = 0; y < N; y++){
                    cin >> board[x][y];
                }
            }
            continue;
        }
        if (CanMoveDown(board)){
            cout << "D" << endl;
            for (int x = 0; x < N; x++){
                for (int y = 0; y < N; y++){
                    cin >> board[x][y];
                }
            }
            continue;
        }
        assert(false);
    }
}