#include <iostream>
//#include <bits/stdc++.h>
#include "vector"
#include "cmath"
#include "set"
#include "map"


using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define el cout << '\n'
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

string alphabets = "abcdefghijklmnopqrstuvwxyz";

bool check(map<char, int>& A, map<char, int>& B){

    for (char c: alphabets){

        if (A[c] != 0 and B[c] == 0){
            return true;
        }
        if (A[c] == 0 and B[c] == 0){
            continue;
        }

        for (char p: alphabets){
            if (p > c and B[p] != 0){
                return true;
            }
        }

        if (A[c] >= B[c]){
            return false;
        }

        for (char p: alphabets){
            if (p > c and A[p] != 0){
                return false;
            }
        }

        return true;

    }
}

void solve() {

    int Q;
    cin >> Q;
    map<char, int> X, Y;
    for(char c: alphabets){
        X[c] = 0, Y[c] = 0;
    }
    X['a']++;
    Y['a']++;
    range(testcase, 0, Q){
        int d, k;
        string s;
        cin  >> d >> k >> s;

        if (d == 1){
            for(char c: s){
                X[c] += k;
            }
        }else{
            for (char c: s){
                Y[c] += k;
            }
        }

        bool ans = check(X, Y);
        if (ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }





    return 0;
}
