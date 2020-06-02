#include <bits/stdc++.h>
using namespace std;
int main(){
    int r, n;
    for(int k = 1; scanf("%d %d", &r, &n) and r + n; k++){
        r -= n;
        r = ceil((r * 1.0) / n);
        cout << "Case " << k <<": ";
        if(r > 26)
            cout << "impossible\n";
        else
            cout << r << '\n';
    }
    return 0;
}
