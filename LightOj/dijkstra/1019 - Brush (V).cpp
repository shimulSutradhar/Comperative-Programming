#include <bits/stdc++.h>
using namespace std;
typedef long long int           i64;
typedef pair<int, int>          pii;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        typedef vector<int>             vi;
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
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
struct Node{
    int at, cost;
    Node(int _at, int _cost){
        at = _at;
        cost = _cost;
    }
    bool operator < (const Node & a) const{
        return cost > a.cost;
    }
};
 
i64 dist[110], n;
vector<pii> adj[110];
 
void dijkstra(int s){
    for(int i = 0; i <= n; i++)
        dist[i] = INF;
    priority_queue<Node> q;
    q.push(Node(s, 0));
    dist[s] = 0;
    while(!q.empty()){
        Node u = q.top();
        q.pop();
        error(u.at, u.cost, dist[u.at]);
        if(u.cost != dist[u.at])
            continue;
        for(auto m : adj[u.at]){
            if(dist[m.f] > u.cost + m.s){
                dist[m.f] = u.cost + m.s;
                q.push(Node(m.f, dist[m.f]));
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
    int m, x, y, w, t;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> n >> m;
        while(m--){
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dijkstra(1);
        cout << "Case " << ca << ": ";
        if(dist[n] == INF)
            cout << "Impossible" << "\n";
        else
            cout << dist[n] << "\n";
        for(int i = 0; i <= n; i++) adj[i].clear();
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
