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
 
int *A;
int power, N;
 
int max_eat(int f1, int f2, int f3) {
 
    int factors = 0;
    int ans = 0;
 
    int i = 0;
    while (i < N) {
//        cout << power << ' ';
        if (power > A[i]) {
            power += (A[i] / 2);
            i++;
            ans++;
            continue;
        }
        if (factors == 0) {
            power *= f1;
            factors = 1;
        }else if (factors == 1){
            power *= f2;
            factors = 2;
        }else if (factors == 2){
            power *= f3;
            factors = 3;
        }else{
            break;
        }
    }
    return ans;
}
 
 
void solve() {
 
    cin >> N >> power;
    int initial_power = power;
 
    A = new int[N];
    range(i, 0, N) cin >> A[i];
 
    sort(A, A + N);
 
    int ans = 0;
    ans  = max(ans, max_eat(2, 2, 3));
    power = initial_power;
    ans  = max(ans, max_eat(2, 3, 2));
    power = initial_power;
    ans  = max(ans, max_eat(3, 2, 2));
 
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
