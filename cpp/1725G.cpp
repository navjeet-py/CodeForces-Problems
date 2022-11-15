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

void solve() {

    int N;
    cin >> N;
    int ans = 0;
    if (N == 1) ans = 3;
    if (N == 2) ans = 5;
    if (N == 3) ans = 7;

    if (ans != 0){
        cout << ans << '\n';
        return;
    }

    N -= 4;
    int x = N / 3;
    x += 2;
    x *= 4;
    if (N %3==1) x +=1;
    if (N % 3 == 2) x += 3;
    cout << x << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }





    return 0;
}
