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

bool *cat;
int *dp;
vector<int> *adj;
int *final;

void dfs(int cur, int par){

    for(int nb: adj[cur]){
        if (nb == par) continue;

        if (cat[nb]) dp[nb] = dp[cur] + 1;
        else dp[nb] = 0;

        dfs(nb, cur);

    }
}

void final_calc_dfs(int cur, int par){
    for(int nb: adj[cur]){
        if (nb == par) continue;

        final[nb] = max(dp[nb], final[cur]);

        final_calc_dfs(nb, cur);
    }
}



void solve() {

    int N, M;
    cin >> N >> M;
    adj = new vector<int>[N];
    cat = new bool[N];
    range(i, 0, N){
        cin >> cat[i];
    }
    range(i, 0, N - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp = new int[N];
    if (cat[0]) dp[0] = 1;
    else dp[0] = 0;

    dfs(0, 0);

    final = new int[N];
    final[0] = dp[0];

    final_calc_dfs(0, 0);

    int cnt = 0;
    range(i, 1, N){
        if(adj[i].size() == 1 and final[i] <= M){
            cnt++;
        }
    }

    cout << cnt << '\n';
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
