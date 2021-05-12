#include "testlib.h"
#include "2048.h"
#include <bits/stdc++.h>
using namespace std;

signed main(int argc, char* argv[]){
    registerInteraction(argc, argv);
    cout << flush;
    int seed = inf.readInt();
    mt19937 rando(seed);
    Helper2048::Game game;
    Helper2048::Board board = game.Init(rando);
    for (int x = 0; x < Helper2048::N; x++){
        for (int y = 0; y < Helper2048::N; y++){
            cout << board[x][y] << ' ';
        } cout << endl;
    } cout << flush;
    while (1){
        string s = ouf.readWord();
        if (s == "U"){
            board = game.Move(Helper2048::Up, rando);
        }
        else if (s == "L"){
            board = game.Move(Helper2048::Left, rando);
        }
        else if (s == "D"){
            board = game.Move(Helper2048::Down, rando);
        }
        else if (s == "R"){
            board = game.Move(Helper2048::Right, rando);
        }
        else{
            quitf(_wa, "invalid move - wtf is %s", s.c_str());
        }
        for (int x = 0; x < Helper2048::N; x++){
            for (int y = 0; y < Helper2048::N; y++){
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