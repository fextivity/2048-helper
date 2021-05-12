#include "2048.h"
#include <bits/stdc++.h>
using namespace std;

signed main(){
    Helper2048::Board board;
    for (int x = 0; x < Helper2048::N; x++){
        for (int y = 0; y < Helper2048::N; y++){
            cin >> board[x][y];
        }
    }
    bool lr = 0;
    while (board[0][0] >= 0){
        if (!lr){
            if (Helper2048::CanMove(board, Helper2048::Right)){
                lr = 1;
                cout << "R" << endl;
                for (int x = 0; x < Helper2048::N; x++){
                    for (int y = 0; y < Helper2048::N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
            if (Helper2048::CanMove(board, Helper2048::Left)){
                lr = 0;
                cout << "L" << endl;
                for (int x = 0; x < Helper2048::N; x++){
                    for (int y = 0; y < Helper2048::N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
        }
        else{
            if (Helper2048::CanMove(board, Helper2048::Left)){
                lr = 0;
                cout << "L" << endl;
                for (int x = 0; x < Helper2048::N; x++){
                    for (int y = 0; y < Helper2048::N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
            if (Helper2048::CanMove(board, Helper2048::Right)){
                lr = 1;
                cout << "R" << endl;
                for (int x = 0; x < Helper2048::N; x++){
                    for (int y = 0; y < Helper2048::N; y++){
                        cin >> board[x][y];
                    }
                }
                continue;
            }
        }
        if (Helper2048::CanMove(board, Helper2048::Up)){
            cout << "U" << endl;
            for (int x = 0; x < Helper2048::N; x++){
                for (int y = 0; y < Helper2048::N; y++){
                    cin >> board[x][y];
                }
            }
            continue;
        }
        if (Helper2048::CanMove(board, Helper2048::Down)){
            cout << "D" << endl;
            for (int x = 0; x < Helper2048::N; x++){
                for (int y = 0; y < Helper2048::N; y++){
                    cin >> board[x][y];
                }
            }
            continue;
        }
        assert(false);
    }
}