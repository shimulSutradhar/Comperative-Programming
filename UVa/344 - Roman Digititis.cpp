#include <bits/stdc++.h>
using namespace std;
struct Node{
    int i, v, x, l, c;
    Node(int _i, int _v, int _x, int _l, int _c){
        i = _i;
        v = _v;
        x = _x;
        l = _l;
        c = _c;
    }
};
int main(){
    auto romanNum = [](int n){
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
        string sym[] = {"i","iv","v","ix","x","xl","l","xc","c","cd","d","cm","m"};
        string roman_number;
        int i = 12;
        while(n > 0){
            int d = n / num[i];
            n = n % num[i];
            while(d--){
                roman_number += sym[i]; 
            } 
            --i;
        }
        return roman_number;
    };
    vector<Node> ans;
    ans.emplace_back(0, 0, 0, 0, 0);
    int count[27];
    memset(count, 0, sizeof count);
    for(int i = 1; i <= 100; i++){
        string a = romanNum(i);
        for(auto m : a)
            ++count[m - 'a'];
        ans.emplace_back(Node(count['i' - 'a'], count['v' - 'a'], count['x' - 'a'], count['l' - 'a'], count['c' - 'a']));
    }
    int n;
    while(cin >> n and n){
        cout << n << ": " << ans[n].i << " i, " << ans[n].v << " v, " << ans[n].x << " x, " << ans[n].l << " l, " << ans[n].c << " c\n";
    }
    return 0;
}
