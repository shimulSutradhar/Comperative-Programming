#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n, x;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> n;
        vector<vector<int> > v(n + 2, vector<int> (n + 2, -1));
        for(int i = 1; i <= n; i++){
            for(int j = i, k = 1; j >= 1, k <= i; j--, k++)
                cin >> v[j] [k];        }
        for(int i = 2; i <= n; i++){
            for(int j = i, k = n; k >= i, j <= n; k--, j++)
                cin >> v[k] [j];
        }
        vector<vector<int> > dp(n + 2, vector<int> (n + 2, 0));
        for(int i = 1; i <= n; i++){
            for(int j = i, k = 1; j >= 1, k <= i; j--, k++)
                dp[j] [k] = max(dp[j - 1] [k] + v[j] [k], dp[j] [k - 1] + v[j] [k]);
        }
        for(int i = 2; i <= n; i++){
            for(int j = i, k = n; k >= i, j <= n; k--, j++)
                dp[k] [j] = max(dp[k - 1] [j] + v[k] [j], dp[k] [j - 1] + v[k] [j]);
        }
        cout << "Case "<< ca <<": " << dp[n] [n] << '\n';
    }
    return 0;
}
