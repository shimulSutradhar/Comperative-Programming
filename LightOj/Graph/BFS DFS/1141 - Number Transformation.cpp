#include <bits/stdc++.h>
using namespace std;
typedef long long int           i64;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<double>          vd;
typedef vector<string>          vs;
typedef vector<pair<int, int> > vii;
#define all(c)              c.begin(), c.end()
#define clr(x,y)            memset(x,y,sizeof x)
#define MOD                 1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932
#define max3(x, y, z)       max(max(x, y), z)
#define min3(x, y, z)       min(min(x, y), z)
#define to_lower(x)         transform(x.begin(), x.end(), x.begin(), ::tolower)
#define to_upper(x)         transform(x.begin(), x.end(), x.begin(), ::toupper)
#define vin(x)              for(auto &m : x) cin >> m;
#define f                   first                
#define s                   second              
 
int dr[] = {-1, 0, 1,  0};
int dc[] = { 0, 1, 0, -1};
 
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
 
int hr[] = {1, 1, 2, 2,-1,-1,-2,-2};
int hc[] = {2,-2, 1,-1, 2,-2, 1,-1};
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
vi adj[1010];
int pf[1010], dist[1010], t;
bool mark[1010];
 
void sieve(){
    pf[1] = 1;
    for(int i = 2; i < 1010; i++)
        pf[i] = i;
    for(int i = 4; i < 1010; i += 2)
        pf[i] = 2;
    for (int i = 3; i*i < 1010; i++) {
        if (pf[i] == i){
            for (int j = i*i; j < 1010; j += i)
                if (pf[j]==j)
                    pf[j] = i;
        }
    }
}
vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1){
        ret.push_back(pf[x]);
        x = x / pf[x];
    }
    return ret;
}
void primeFactors(){
    sieve();
    for(int i = 1; i <= 1000; i++){
        vector<int> v = getFactorization(i);
        if(v.size() > 1)adj[i] = v;
    }
}

void bfs(int s){
    clr(mark, true);
    clr(dist, -1);
    dist[s] = 0;
    mark[s] = false;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto m : adj[u]){
            if(m + u <= 1000 && mark[m + u]){
                dist[m + u] = dist[u] + 1;
                mark[m + u] = false;
                q.push(m + u);
                if(m + u == t)
                    break;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    primeFactors();
    int n, s, k = 1;
    cin >> n;
    while(n--){
        cin >> s >> t;
        bfs(s);
        cout <<"Case "<< k++ << ": " << dist[t] << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}