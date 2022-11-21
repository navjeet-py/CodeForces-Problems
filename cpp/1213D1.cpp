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


    int N, K;
    cin >> N >> K;
    int A[N];
    int mx = 0;

    range(i, 0, N){
        cin >> A[i];
        mx = max(mx, A[i]);
    }

    int ans = LONG_LONG_MAX;

    for (int ending = 0; ending <= mx; ending++){

        vector<int> steps;
        for(int a: A){

            int st = 0;
            while(a > ending){
                a /= 2;
                st++;
            }
            if (a == ending){
                steps.push_back(st);
            }else{
                steps.push_back(INT_MAX);
            }
        }

        sort(steps.begin(), steps.end());
        int sm = 0;
        range(i, 0, K)sm += steps[i];
        ans = min(ans, sm);


    }

    cout << ans << '\n';

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
