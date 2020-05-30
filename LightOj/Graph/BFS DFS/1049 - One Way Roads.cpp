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
 
vii adj[105];
bool visit[105];
int cost1, lastVisit, cost;
 
void dfs(int at){
    if(!visit[at])
        return;
    visit[at] = false;
    for(auto m : adj[at])
        if(visit[m.f]){
            lastVisit = m.f;
            cost1 += m.s;
            dfs(m.f);
        }
}
 
void dfs_anti(int at){
    if(!visit[at])
        return;
    visit[at] = false;
    for(int i = adj[at].size( ) - 1; i >= 0; i--){
        if(visit[adj[at] [i].f]){
            lastVisit = adj[at] [i].f;
            cost += adj[at] [i].s;
            dfs_anti(adj[at] [i].f);
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
    int t, n, u, v, w;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> u >> v >> w;
            adj[u].push_back({v, 0});
            adj[v].push_back({u, w});
        }
        clr(visit, true);
        cost1 = 0;
        dfs(1);
        for(auto m : adj[lastVisit])
            if(m.f == 1){
                cost1 += m.s;
                break;
            }
        clr(visit, true);
        cost = 0;
        dfs_anti(1);
        for(auto m : adj[lastVisit])
            if(m.f == 1){
                cost += m.s;
                break;
            }
        cout << "Case " << ca << ": "<< min(cost, cost1) << "\n";
        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
 