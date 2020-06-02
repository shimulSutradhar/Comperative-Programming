#include <bits/stdc++.h>
using namespace std;
int main(){
    auto eulers_totient =[](long long int n){
    	long long int co_prime = n;
    	for(int i = 2; i * i <= n; i++)
    		if(!(n % i)){
    			while(!(n % i)){
    				n /= i;
    			}
    			co_prime -= co_prime / i;
    		}
    	if(n > 1)
    		co_prime -= co_prime / n;
    	return co_prime;
    };
    long long int n;
    while(cin >> n and n)
    	cout << eulers_totient(n) << '\n';
    return 0;
}
