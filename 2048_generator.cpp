#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

signed main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int seed = rnd.next(1, 1000000000);
    cout << seed << endl;
}