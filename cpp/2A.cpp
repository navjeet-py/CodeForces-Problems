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
    int N;
    cin >> N;
    map<string, int> mp;
    pair<string, int> scores[N];

    int max_score = 0;
    range(i, 0, N){
        string name;
        int score;
        cin >> name >> score;
        scores[i].first = name;
        scores[i].second = score;
        mp[name] += score;
    }
    for(const auto& it: mp) max_score = max(max_score, it.second);

    map<string, int> second;
    range(i, 0, N){
        string name = scores[i].first;
        int score = scores[i].second;

        second[name] += score;
        if (second[name] >= max_score && mp[name] == max_score){
            cout << name << '\n';
            return;
        }
    }

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
