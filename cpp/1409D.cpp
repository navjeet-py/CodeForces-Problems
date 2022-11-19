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


vector<int> digits(int N){
    vector<int> v;
    while(N > 0){
        v.push_back(N  % 10);
        N /= 10;
    }
    return v;
}

int sum(vector<int> v){
    int sm = 0;
    for(int a: v){
        sm += a;
    }
    return sm;
}

int diff(vector<int> A, vector<int> B){
    int factor = 1;
    int i = 0;
    int ans = 0;
    while(i < A.size()){
        ans += (factor * (B[i] - A[i]));
        factor*=10;
        i++;
    }
    while(i < B.size()){
        ans += (factor * (B[i]));
        factor*=10;
        i++;
    }

    return ans;

}


void solve() {


    int N, S;
    cin >> N >> S;
    vector<int> v = digits(N);


    while(sum(v) > S){
//        print_array(v);

        range(i, 0, v.size()){
            if (v[i] == 0) continue;
            v[i] = 0;
            if (i == v.size() - 1){
                v.push_back(1);
                break;
            }
            range(x, i + 1, v.size()){
                if (v[x] == 9){
                    v[x] = 0;
                    if (x == v.size() - 1) {
                        v.push_back(1);
                        break;
                    }
                    continue;
                }else{
                    v[x]++;
                    break;
                }
            }
            break;
        }
    }

    int ans = diff(digits(N), v);
    cout << ans << '\n';

//    cout << ans << '\n';





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
