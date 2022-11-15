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
#define mod2 998244353
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void print_array(const vector<int>& V){
    for(int a: V) cout << a << ' ';
    cout << '\n';
}


void solve() {

    int N;
    cin >> N;
    vector<int> A, B;
    range(i, 1, N - 1){
        if (i % 2 == 1) A.push_back(i);
        else B.push_back(i);
    }
    int alpha = (1 << 29);
    int first = alpha, second = alpha;
    for (int a: A) first ^= a;
    for (int b: B) second ^= b;

    if (first == second){
        first += (1 << 30);
        A[A.size() - 1] += (1 << 30);
    }

    A.push_back(first);
    B.push_back(second);

    int i = 0, j = 0;
    bool hehe = true;
    while (i + j < N){
        if (hehe) {
            cout << A[i++] << ' ';
            hehe = false;
        }else{
            cout << B[j++] << ' ';
            hehe = true;
        }
    }
    cout << '\n';

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
