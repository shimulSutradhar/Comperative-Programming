#include <bits/stdc++.h>
using namespace std;
int main(){
    auto solved = [&](int n, int k, int p){
        if(p <= n - k){
            cout << k + p << '\n';
            return;
        }
        p -= n - k;
        if(p % n == 0)
            cout << n << '\n';
        else
            cout << p % n << '\n';
    };
    int t, n, k, p, ca = 1;
    cin >> t;
    while(t--){
        cin >> n >> k >> p;
        cout << "Case " << ca++ << ": ";
        solved(n, k, p);
    }
    return 0;
}
