#include <bits/stdc++.h>
using namespace std;
int main(){
    auto solved = [](int n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                long long int k = (i * i * i) - (j * j * j);
                if(k == n){
                    cout << i << ' ' << j << '\n';
                    return;         
                }
            }
        }
        cout << "No solution\n";
    };
    int n;
    while(cin >> n && n)
        solved(n);
    return 0;
}
