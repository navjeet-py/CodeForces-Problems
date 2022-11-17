#include <iostream>
#include <bits/stdc++.h>
//#include "vector"
//#include "cmath"
//#include "set"
//#include "map"


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

    int N, K;
    cin >> N >> K;
    int ans = 0;
    int rems[N];
    range(i, 0, N) {
        int a;
        cin >> a;
        ans += (a / K);
        rems[i] = a % K;
    }

    sort(rems, rems + N);
    int j = N - 1, i = 0;
    while (i < j){
        if (rems[i] + rems[j] >= K){
            ans++;
            i++, j--;
        }else{
            i++;
        }
    }
    cout << ans << '\n';




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
