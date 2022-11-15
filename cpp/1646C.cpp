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

vector<int> powers;
vector<int> factorials;

int count_binary_digits(int x){

    int cnt = 0;
    int p = 1;
    while (p <= x){
        if (p & x) cnt++;
        p *= 2;
    }

    return cnt;

}

int count_t(int N, int factor){
    int x = 1;
    int cnt = 0;
    range(ppp, 0, 12){
        if (x & factor){
            if (N >= factorials[ppp]){
                N -= factorials[ppp];
                cnt++;
            }
        }
        x *= 2;
    }
    
    return cnt + count_binary_digits(N);
}


void solve() {

    int N;
    cin >> N;

    int mn = 1000;
    range(i, 0, (1 << 12)){
        mn = min(mn, count_t(N, i));
    }
    cout << mn << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p = 6;
    int x = 4;
    while (p < 1000000000000){
        factorials.push_back(p);
        p *= (x++);
    }

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }
    
    
    return 0;
}
