#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
    int n;
    while(cin >> n && n){
        int x = upper_bound(p.begin(), p.end(), n) - p.begin();
        if(x == 22)
            cout << 0 << '\n';
        else{
            int d1 = log10(n * 1.0) + 1;
            int d2 = log10(p[x] * 1.0) + 1;
            if(d1 == d2)
                cout << p[x] << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}
