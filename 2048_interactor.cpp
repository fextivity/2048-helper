#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define N 4

typedef array <array <int, N>, N> Board;

class Game{
private:
    mt19937 rando;

    int move, score;

    Board board;

    int Randt(int l, int r);

    bool HasLegalMove();
public:
    const int MaxMove = 500, MaxScore = 1000000000;
    const int Up = 0, Left = 1, Down = 2, Right = 3;
    
    Game();

    Board Init();

    Board Init(int seed);

    Board Move(int direction);
};

int Game::Randt(int l, int r){
    return rando() % (r - l + 1) + l;
}

bool Game::HasLegalMove(){
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            if (board[x][y] < 0){
                return false;
            }
            if (board[x][y] == 0){
                return true;
            }
        }
    }
    for (int x = 1; x < N; x++){
        for (int y = 0; y < N; y++){
            if (board[x][y] == board[x - 1][y]){
                return true;
            }
        }
    }
    for (int x = 0; x < N; x++){
        for (int y = 1; y < N; y++){
            if (board[x][y] == board[x][y - 1]){
                return true;
            }
        }
    }
    return false;
}

Game::Game(){
    assert(N >= 3);
}

Board Game::Init(){
    return Init(-1);
}

Board Game::Init(int seed){
    // Initialize rando and board
    if (seed == -1){
        seed = chrono::steady_clock::now().time_since_epoch().count();
    }
    rando = mt19937(seed);
    move = 0; score = 0;
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            board[x][y] = 0;
        }
    }
    // Add the first two elements.
    pair <int, int> firstPos, secondPos;
    firstPos = make_pair(Randt(0, N - 1), Randt(0, N - 1));
    board[firstPos.first][firstPos.second] = Randt(1, 2) * 2;
    while (1){
        secondPos = make_pair(Randt(0, N - 1), Randt(0, N - 1));
        if (secondPos != firstPos){
            break;
        }
    }
    board[secondPos.first][secondPos.second] = Randt(1, 2) * 2;
    return board;
}

Board Game::Move(int direction){
    // General algorithm: Move all cell without merge first, then merge.
    move++;
    bool checkInvalid = true;
    if (direction == Up){
        for (int y = 0; y < N; y++){
            for (int x = 1; x < N; x++){
                int tx = x;
                while (tx > 0 and board[tx - 1][y] == 0 and board[tx][y] > 0){
                    checkInvalid = false;
                    swap(board[tx - 1][y], board[tx][y]);
                    tx--;
                }
            }
            for (int x = 1; x < N; x++){
                if (board[x][y] == 0){
                    break;
                }
                if (board[x - 1][y] == board[x][y]){
                    checkInvalid = false;
                    score += board[x - 1][y];
                    board[x - 1][y] *= 2;
                    board[x][y] = 0;
                    for (int x2 = x; x2 < N - 1; x2++){
                        swap(board[x2][y], board[x2 + 1][y]);
                    }
                }
            }
        }
    }
    else if (direction == Left){
        for (int x = 0; x < N; x++){
            for (int y = 1; y < N; y++){
                int ty = y;
                while (ty > 0 and board[x][ty - 1] == 0 and board[x][ty] > 0){
                    checkInvalid = false;
                    swap(board[x][ty - 1], board[x][ty]);
                    ty--;
                }
            }
            for (int y = 1; y < N; y++){
                if (board[x][y] == 0){
                    break;
                }
                if (board[x][y - 1] == board[x][y]){
                    checkInvalid = false;
                    score += board[x][y - 1];
                    board[x][y - 1] *= 2;
                    board[x][y] = 0;
                    for (int y2 = y; y2 < N - 1; y2++){
                        swap(board[x][y2], board[x][y2 + 1]);
                    }
                }
            }
        }
    }
    else if (direction == Down){
        for (int y = 0; y < N; y++){
            for (int x = N - 2; x >= 0; x--){
                int tx = x;
                while (tx < N - 1 and board[tx + 1][y] == 0 and board[tx][y] > 0){
                    checkInvalid = false;
                    swap(board[tx + 1][y], board[tx][y]);
                    tx++;
                }
            }
            for (int x = N - 2; x >= 0; x--){
                if (board[x][y] == 0){
                    break;
                }
                if (board[x + 1][y] == board[x][y]){
                    checkInvalid = false;
                    score += board[x + 1][y];
                    board[x + 1][y] *= 2;
                    board[x][y] = 0;
                    for (int x2 = x; x2 > 0; x2--){
                        swap(board[x2][y], board[x2 - 1][y]);
                    }
                }
            }
        }
    }
    else if (direction == Right){
        for (int x = 0; x < N; x++){
            for (int y = N - 2; y >= 0; y--){
                int ty = y;
                while (ty < N - 1 and board[x][ty + 1] == 0 and board[x][ty] > 0){
                    checkInvalid = false;
                    swap(board[x][ty + 1], board[x][ty]);
                    ty++;
                }
            }
            for (int y = N - 2; y >= 0; y--){
                if (board[x][y] == 0){
                    break;
                }
                if (board[x][y + 1] == board[x][y]){
                    checkInvalid = false;
                    score += board[x][y + 1];
                    board[x][y + 1] *= 2;
                    board[x][y] = 0;
                    for (int y2 = y; y2 > 0; y2--){
                        swap(board[x][y2], board[x][y2 - 1]);
                    }
                }
            }
        }
    }
    // Insert a new number
    {
        vector <pair <int, int>> candidates;
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                if (board[x][y] == 0){
                    candidates.push_back(make_pair(x, y));
                }
            }
        }
        shuffle(candidates.begin(), candidates.end(), rando);
        board[candidates[0].first][candidates[0].second] = Randt(1, 2) * 2;
    }
    if (checkInvalid == true){
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                board[x][y] = -2;
            }
        }
        return board;
    }
    if (move > MaxMove){
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                board[x][y] = -1;
            }
        }
        board[0][1] = move;
        board[0][2] = MaxScore;
        return board;
    }
    if (HasLegalMove() == false){
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                board[x][y] = -1;
            }
        }
        board[0][1] = move;
        board[0][2] = score;
        return board;
    }
    return board;
}

signed main(int argc, char* argv[]){
    registerInteraction(argc, argv);
    cout << flush;
    int seed = inf.readInt();
    Game game;
    Board board = game.Init(seed);
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            cout << board[x][y] << ' ';
        } cout << endl;
    } cout << flush;
    while (1){
        string s = ouf.readWord();
        if (s == "U"){
            board = game.Move(game.Up);
        }
        else if (s == "L"){
            board = game.Move(game.Left);
        }
        else if (s == "D"){
            board = game.Move(game.Down);
        }
        else if (s == "R"){
            board = game.Move(game.Right);
        }
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                cout << board[x][y] << ' ';
            } cout << endl;
        } cout << flush;
        if (board[0][0] == -2){
            tout << -1 << " " << -1 << endl;
            quitf(_wa, "invalid move");
            return 0;
        }
        if (board[0][0] == -1){
            tout << board[0][1] << " " << board[0][2] << endl;
            return 0;
        }
    }
}