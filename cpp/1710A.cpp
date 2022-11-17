#include <iostream>
//#include <bits/stdc++.h>
#include "vector"
#include "cmath"
#include "set"
#include "map"
#include <algorithm>


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

void print_array(const vector<int> &V) {
    for (int a: V) cout << a << ' ';
    cout << '\n';
}


void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    int A[K];
    range(i, 0, K) {
        cin >> A[i];
    }

    int cnt = 0;
    bool greater = false;
    // check by M
    for(int a: A){
        if (a / M >= 2){
            if (a / M > 2) greater = true;
            cnt += (a / M);
        }
    }
    if (N % 2 == 0 && cnt >= N){
        cout << "Yes\n";
        return;
    }else if (N % 2 == 1 && cnt >= N && greater){
        cout << "Yes\n";
        return;
    }
    cnt = 0;
    greater = false;
    // check by N
    for(int a: A){
        if (a / N >= 2){
            if (a / N > 2) greater = true;
            cnt += (a / N);
        }
    }

    if (M % 2 == 0 && cnt >= M){
        cout << "Yes\n";
        return;
    }else if (M % 2 == 1 && cnt >= M && greater){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";


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
