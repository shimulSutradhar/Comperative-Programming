#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    while(cin >> n >> k){
        int total = n;
        while(n >= k){
            total += n / k;
            n = n / k + n % k;
        }
        cout << total << '\n';
    }
    return 0;
}
