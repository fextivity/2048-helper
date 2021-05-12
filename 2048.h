#include <bits/stdc++.h>
using namespace std;

namespace Helper2048{
    const int N = 4;

    typedef array <array <int, N>, N> Board;

    const int Up = 0, Left = 1, Down = 2, Right = 3;

    int Randt(int l, int r, mt19937& rando);

    bool HasLegalMove(const Board& board);

    bool CanMove(const Board& board, int direction);

    class Game{
    private:
        int move, score;

        Board board;
    public:
        const int MaxMove = 500, MaxScore = 1000000000;
        
        Game();

        Board Init(mt19937& rando);

        Board Move(int direction, mt19937& rando);
    };

    int Randt(int l, int r, mt19937& rando){
        return rando() % (r - l + 1) + l;
    }

    bool HasLegalMove(const Board& board){
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

    bool CanMove(const Board& board, int direction){
        if (direction == Up){
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
        }
        else if (direction == Left){
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
        }
        else if (direction == Down){
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
        }
        else if (direction == Right){
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
        }
        else{
            assert(false);
        }
        return false;
    }

    Game::Game(){
        assert(N >= 3);
    }

    Board Game::Init(mt19937& rando){
        // Initialize board
        move = 0; score = 0;
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                board[x][y] = 0;
            }
        }
        // Add the first two elements.
        pair <int, int> firstPos, secondPos;
        firstPos = make_pair(Randt(0, N - 1, rando), Randt(0, N - 1, rando));
        board[firstPos.first][firstPos.second] = Randt(1, 2, rando) * 2;
        while (1){
            secondPos = make_pair(Randt(0, N - 1, rando), Randt(0, N - 1, rando));
            if (secondPos != firstPos){
                break;
            }
        }
        board[secondPos.first][secondPos.second] = Randt(1, 2, rando) * 2;
        return board;
    }

    Board Game::Move(int direction, mt19937& rando){
        if (CanMove(board, direction) == false){
            for (int x = 0; x < N; x++){
                for (int y = 0; y < N; y++){
                    board[x][y] = -2;
                }
            }
            return board;
        }
        // General algorithm: Move all cell without merge first, then merge.
        move++;
        if (direction == Up){
            for (int y = 0; y < N; y++){
                for (int x = 1; x < N; x++){
                    int tx = x;
                    while (tx > 0 and board[tx - 1][y] == 0 and board[tx][y] > 0){
                        swap(board[tx - 1][y], board[tx][y]);
                        tx--;
                    }
                }
                for (int x = 1; x < N; x++){
                    if (board[x][y] == 0){
                        break;
                    }
                    if (board[x - 1][y] == board[x][y]){
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
                        swap(board[x][ty - 1], board[x][ty]);
                        ty--;
                    }
                }
                for (int y = 1; y < N; y++){
                    if (board[x][y] == 0){
                        break;
                    }
                    if (board[x][y - 1] == board[x][y]){
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
                        swap(board[tx + 1][y], board[tx][y]);
                        tx++;
                    }
                }
                for (int x = N - 2; x >= 0; x--){
                    if (board[x][y] == 0){
                        break;
                    }
                    if (board[x + 1][y] == board[x][y]){
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
                        swap(board[x][ty + 1], board[x][ty]);
                        ty++;
                    }
                }
                for (int y = N - 2; y >= 0; y--){
                    if (board[x][y] == 0){
                        break;
                    }
                    if (board[x][y + 1] == board[x][y]){
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
        else{
            assert(false);
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
            board[candidates[0].first][candidates[0].second] = Randt(1, 2, rando) * 2;
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
        if (HasLegalMove(board) == false){
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
}