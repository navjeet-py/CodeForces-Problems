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
 
int N, P;
int * A;
set<int> st;
 
bool check(int moves){
 
    if (moves >= P - 1) return true;
 
    if (moves < P - 100) return false;
 
    int alpha = A[N - 1];
    int final = moves + alpha;
    if (final <= P - 1){
        range(i, 0, alpha){
            if (st.find(i) == st.end()) return false;
        }
        range(i, final + 1, P){
            if (st.find(i) == st.end()) return false;
        }
        return true;
    }
 
    final = final % P;
 
    st.insert(0);
    bool found = false;
    for(int chicken = N - 2; chicken >= 0; chicken--){
        if (A[chicken] == P - 1) continue;
        else {
            found = true;
            st.insert(A[chicken] + 1);
            break;
        }
    }
    if (!found) st.insert(1);
 
 
 
    range(i, final + 1, alpha){
        if (st.find(i) == st.end()) return false;
    }
    return true;
 
}
 
 
 
void solve() {
 
    cin >> N >> P;
    st.clear();
    A = new int[N];
 
    range(i, 0, N){
        cin >> A[i];
        st.insert(A[i]);
    }
 
 
    for(int moves = max((long long) 0, P - 105); moves < P; moves++){
        if (check(moves)) {
            cout << moves << '\n';
            break;
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
