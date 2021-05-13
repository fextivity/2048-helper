#include "testlib.h"
#include "2048.h"
#include <bits/stdc++.h>
using namespace std;
using namespace Helper2048;

class Tgen{
private:
    mt19937 rando;

    int randt(int l, int r){
        return rando() % (r - l + 1) + l;
    }
public:
    Tgen(){

    }

    Tgen(int seed){
        rando = mt19937(seed);
    }

    void operator() (Board& board){
        vector <pair <int, int>> candidates;
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                if (board[x][y] == 0){
                    candidates.push_back(make_pair(x, y));
                }
            }
        }
        shuffle(candidates.begin(), candidates.end(), rando);
        board[candidates[0].first][candidates[0].second] = randt(1, 2) * 2;
    }
};

signed main(int argc, char* argv[]){
    registerInteraction(argc, argv);
    cout << flush;
    int seed = inf.readInt();
    Tgen gen(seed);
    Game game;
    Board board = game.Init(gen);
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            cout << board[x][y] << ' ';
        } cout << endl;
    } cout << flush;
    while (1){
        string s = ouf.readWord();
        if (s == "U"){
            board = game.Move(Up, gen);
        }
        else if (s == "L"){
            board = game.Move(Left, gen);
        }
        else if (s == "D"){
            board = game.Move(Down, gen);
        }
        else if (s == "R"){
            board = game.Move(Right, gen);
        }
        else{
            quitf(_wa, "invalid move - wtf is %s", s.c_str());
        }
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                cout << board[x][y] << ' ';
            } cout << endl;
        } cout << flush;
        if (board[0][0] == -2){
            tout << -1 << " " << -1 << endl;
            quitf(_wa, "invalid move - cannot move in the %s direction", s.c_str());
            return 0;
        }
        if (board[0][0] == -1){
            tout << board[0][1] << " " << board[0][2] << endl;
            return 0;
        }
    }
}