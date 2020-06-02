#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e7;
bool mark[maxN];
int main( ){
	vector<int> prime;
	auto sieve = [&](){	
		int limit = sqrt(maxN * 1.0) + 2;
		prime.emplace_back(2);
		mark[0] = mark[1] = true;
		for(int i = 4; i < maxN; i += 2)
			mark[i] = true;
		for(int i = 3; i < maxN; i += 2)
			if(!mark[i]){
				prime.emplace_back(i);
				if(i <= limit)
					for(int j = i * i; j < maxN; j += i * 2)
						mark[j] = true;
			}
	};
	auto fourNumber = [&](int n){
		int x = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
		--x;
		if(prime[x] == n)
			--x;
		while(x >= 0){
			if(prime[x] * 4 == n){
				cout << prime[x] << ' ' << prime[x] << ' ' << prime[x] << ' ' << prime[x] << '\n'; 
				return true;
			}
			if(n - (prime[x] * 3) > 0 && (prime[x] * 3) + !mark[n - (prime[x] * 3)] == n){
				cout << prime[x] << ' ' << prime[x] << ' ' << prime[x] << ' ' << n - (prime[x] * 3) << '\n'; 
				return true;	
			}
			int left = 0, right = x;
			while(left <= right){
				int k = prime[x] + prime[left] + prime[right];
				if(n - k > 0 && !mark[n - k]){
					cout << prime[x] << ' ' <<  prime[left] << ' ' << prime[right] <<' '<< n - k << '\n';
					return true;
				}else if(k + prime[right] > n)
					--right;
				else
					++left;
			}
			--x;
		}
		return false;
	};
	sieve();
	int n = 2;
	while(cin >> n){
		bool ok = fourNumber(n);
		if(!ok) cout << "Impossible.\n";
	}
	return 0;
}
