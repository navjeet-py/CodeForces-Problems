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


int binomial(int n, int r){
    if (r == 0) return 1;
    int ans = 1;
    range(x, 1, n - r + 1){
        ans *= (r + x);
        ans /= (x);
    }
    return ans % mod2;
}

map<int, int> A, B;

void solve() {
    int p;
    cin >> p;
    cout << A[p] << ' ' << B[p] << ' ' << 1 << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    A[2] = 1, A[4] = 3, A[6] = 12;
    B[2] = 0, B[4] = 2, B[6] = 7;

    for (int x = 8; x <= 60; x += 2){

        A[x] = (binomial(x - 1, (x - 2) / 2) + B[x - 2]) % mod2;
        B[x] = (binomial(x, x / 2) - A[x] - 1) % mod2;
        if (B[x] < 0) B[x] += mod2;
    }

    while (T--) {
        solve();
    }





    return 0;
}
