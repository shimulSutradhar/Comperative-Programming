#include<bits/stdc++.h>
using namespace std;
// number theory template
// topic include:
//         name                   time complexity      function name
//      1. sieve of eratosthenes  O(nlogn)             void sieve() 
//      2. prime factorization    O(logn)              vector<T> primeFactors(T n)
//      3. number of divisor      O(logn)              T numberOfDivisor(T)
//      4. sum of divisor         O(logn)              T sumOfDivisor(T)
//      5. sum of divisor mod     O(logn)              T sumOfDivisor(T, mod)
template<typename T>
class numberTheory{
public:
    // variable
    int limit = 0;
    int inDex = 0;
    T *prime;
    bitset<10000000> primeMark;  // need changes for differendt limit
    numberTheory( ){}
    numberTheory(int _limit = 0){
        limit = _limit;
        prime = new T[limit + 7];
        inDex = 0;
    }
    T operator[](int n){
        return n >= inDex ? -1 : prime[n];
    }
    void sieve();
    vector<T> primeFactors(T n);
    T bigmod(T n, T p, T m);
    T power(T n, T p);
    T numberOfDivisor(T n);
    T sumOfDivisor(T n, T mod);
    T sumOfDivisor(T n);
};
// power function
template<typename T>
T numberTheory<T>::power(T n, T p){ 
    T res = 1;
    while(p > 0){
        if(p & 1)res *= n;
        n *= n;
        p >>= 1;
    }
    return res;
}
// big mod
template<typename T>
T numberTheory<T>::bigmod(T n, T p, T m){
    n %= m;
    T res = 1;
    while(p > 0){
        if(p & 1)res = res * n % m;
        n = n * n % m;
        p >>= 1;
    }
    return res;
}
// sieve of eratosthenes O(nlogn)
template<typename T>
void numberTheory<T>::sieve(){
    int maxN = sqrt(limit * 1.0) + 2;
    primeMark[0] = primeMark[1] = true;
    prime[inDex++] = 2;
    prime[inDex++] = 3;
    for(int i = 4; i < limit; i += 2){
        primeMark[i] = true;
    }
    for(int i = 9; i < limit; i += 6){
        primeMark[i] = true;
    }
    for(int i = 5; i < limit; i += 6){
        if(!primeMark[i]){
            prime[inDex++] = i;
            if(i <= maxN){
                for(int j = i * i; j < limit; j += i * 2){
                    primeMark[j] = true;               
                }
            }
        }
        if(!primeMark[i + 2]){
            int x = i + 2;
            prime[inDex++] = x;
            if(x <= maxN){
                for(int j = x * x; j < limit; j += 2 * x)
                    primeMark[j] = true;
            }
        }
    }
}
//prime factorization   O(logn)
//for prime factorization call sieve( ) function first
template<typename T>
vector<T> numberTheory<T>::primeFactors(T n){
    vector<T> pFactor;
    for(int i = 0; i < inDex and prime[i] * prime[i] <= n; i++){
        while(!(n % prime[i])){
            pFactor.emplace_back(prime[i]);
            n /= prime[i];
        }
    }   
    if(n > 1){
        pFactor.emplace_back(n);
    }
    return pFactor;
}
//number of divisor   O(logn)
//for number of divisor call sieve( ) function first
template<typename T>
T numberTheory<T>::numberOfDivisor(T n){
    T cnt = 1;
    for(int i = 0; i < inDex and prime[i] * prime[i] <= n; i++){
        if(!(n % prime[i])){
            T subCnt = 0;
            while(!(n % prime[i])){
                ++subCnt;
                n /= prime[i];
            }
            cnt *= (subCnt + 1);
        }
    }   
    if(n > 1){
        cnt *= 2;
    }
    return cnt;
}
//number of divisor   O(logn)
//for number of divisor call sieve( ) function first
template<typename T>
T numberTheory<T>::sumOfDivisor(T n){
    T ans = 1;
    for(int i = 0; i < inDex and prime[i] * prime[i] <= n; i++){
        if(!(n % prime[i])){
            T cnt = 0;
            while(!(n % prime[i])){
                ++cnt;
                n /= prime[i];
            }
            ans *= power(prime[i], cnt + 1) - 1;
            ans /= prime[i] - 1;
        }
    }
    if(n > 1){
        ans *= n * n - 1;
        ans /= n - 1;
    }
    return ans;
}
//number of divisor   O(logn)
//for number of divisor call sieve( ) function first
//with mod
template<typename T>
T numberTheory<T>::sumOfDivisor(T n, T mod){ 
    T ans = 1;
    for(int i = 0; i < inDex and prime[i] * prime[i] <= n; i++){
        if(!(n % prime[i])){
            T cnt = 0;
            while(!(n % prime[i])){
                ++cnt;
                n /= prime[i];
            }
            ans = (ans % mod * (bigmod(prime[i], cnt + 1, mod) - 1 + mod) % mod) % mod;
            ans = (ans % mod * bigmod(prime[i] - 1, mod - 2, mod) % mod) % mod;
        }
    }
    if(n > 1){
        ans = (ans % mod * (bigmod(n, 2, mod) - 1 + mod) % mod) % mod;
        ans = (ans % mod * bigmod(n - 1, mod - 2, mod) % mod) % mod;
    }
    return ans;
}


// Euler totient function
template <typename T>
class totientFunction{
public:
    T *phi;
    int limit;
    bitset<10000000> mark; // edit limit in different data limit
    totientFunction(){}
    totientFunction(int _limit){
        phi = new T[_limit + 7];
        limit = _limit;
    }
    T operator[](int n){ 
        return n < limit ? phi[n] : -1;
    }
    void sievephi();
    T phiFun(T n);
};
// sieve phi
template<typename T>
void totientFunction<T>::sievephi(){
    for(int i = 0; i < limit; i++){
        phi[i] = i;
    }
    mark[1] = true;
    for(int i = 2; i < limit; i++){
        if(!mark[i]){
            for(int j = i; j < limit; j += i){
                mark[j] = true;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
// loop phi
template<typename T>
T totientFunction<T>::phiFun(T n){
    T ret = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(!(n % i)){
                n /= i;
            }
            ret -= ret / i;
        }
    }
    if(n > 1)
        ret -= ret / n;
    return ret;
}

// extended GCD
// Linear Diophantine Equation
int egcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main(){
    numberTheory<int> f(1000000);
    f.sieve();
    for(int i = 0; i < f.inDex; i++){
        cout << f[i] << ' ';
    }
    return 0;
}
 
