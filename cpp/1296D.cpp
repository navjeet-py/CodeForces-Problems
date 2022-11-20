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

    int a, b, n, k;
    cin >> n >> a >> b >> k;

    int usage[n];

    range(i, 0, n){
        int hp;
        cin >> hp;
        hp = hp % (a + b);
        if (hp == 0) hp += (a + b);
        if (hp <= a){
            usage[i] = 0;
            continue;
        }
        hp -= a;
        usage[i] = hp / a;
        if (hp % a != 0) usage[i]++;
    }


    sort(usage, usage + n);
    int ans = 0;
    int use = 0;
    for(int x: usage){
        if (use + x <= k) {
            ans++;
            use += x;
        }
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
