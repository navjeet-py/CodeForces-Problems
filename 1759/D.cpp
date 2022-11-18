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
 
int highest_zero(int K){
    int ans = 1;
    while(K > 0){
        if (K < 10){
            ans *= K;
        }else{
            ans *= 10;
        }
        K /= 10;
    }
    return ans;
}
 
 
void solve() {
 
    int N, M;
    cin >> N >> M;
 
    int X = N;
    while(X > 0 and X % 10 == 0){
        X /= 10;
    }
 
    int req = 1;
    while(X > 0 and X % 2 == 0) {
        X /= 2;
        req *= 5;
    }
    while(X > 0 and X % 5 == 0){
        X /= 5;
        req *= 2;
    }
 
    if (req == 1){
        cout <<  N * highest_zero(M) << ' ';
        return;
    }
 
    if (M < req){
        int a = -1;
        if (req % 2 == 0) a = 2;
        else a = 5;
        int p = 1;
        while(p * a <= M){
            p *= a;
        }
        if (p * 4 <= M) p *= 4;
        if (p * 3 <= M) p*= 3;
        if (p * 2 <= M) p*=2;
 
        cout << p * N << ' ';
        return;
    }
 
    while(req * 10 <= M){
        req *= 10;
    }
 
    for(int xx = 9; xx > 1; xx--){
        if (req * xx <= M)  req *= xx;
    }
    cout << req * N << ' ';
 
 
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
