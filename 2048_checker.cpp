#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const double M_E = 2.71828182845904523536028747135266249;

double f(int x){
    if (x <= 20){
        return 100.0;
    }
    if (20 < x and x <= 50){
        return 101.0 - exp(log(21) * (x - 20.0) / 30.0);
    }
    if (50 < x and x < 1000000000){
        return 80.0 / (M_E - 1.0) * (M_E - pow(1.0 + 80.0 / (x - 50.0), (x - 50.0) / 80.0));
    }
    if (x == 1000000000){
        return 0.0;
    }
    return -100.0;
}

signed main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    int move = ouf.readInt(), score = ouf.readInt();
    if (move == -1 and score == -1){
        quitf(_wa, "invalid move");
        return 0;
    }
    quitp(f(score), "ok move=%d score=%d", move, score);
}