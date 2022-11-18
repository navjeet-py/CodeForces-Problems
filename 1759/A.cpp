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
 
char nex(char c){
    if (c == 'Y') return 'e';
    if (c == 'e') return 's';
    if (c == 's') return 'Y';
}
 
 
 
 
void solve() {
 
    string S;
    cin >> S;
 
    int N = S.length();
    if (S[0] == 'Y' || S[0] == 'e' || S[0] == 's'){
        string X = "";
        X += S[0];
        range(i, 1, N){
            X += nex(S[i - 1]);
        }
 
        if (X == S){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
 
    }else{
        cout << "NO\n";
        return;
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
