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
 
bool visit[20100], node[20100];
int color[20100];
vector<int> adj[20100];
 
void dfs(int a, bool col){
    if(!visit[a])
        return;
    visit[a] = false;
    color[a] = col;
    for(auto m : adj[a])
        if(visit[m])
            dfs(m, !col);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, x, y, n;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> n;
        clr(node, true);
        int mNode = 0;
        for(int i = 0; i< n; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            node[x] = node[y] = false;
            mNode = max(mNode, max(x, y));
        }
        int ans = 0;
        clr(visit, true);
        for(int i = 1; i < mNode; i++){
            if(!node[i] && visit[i]){
                x = 0, y = 0;
                clr(color, -1);
                dfs(i, true);
                for(int i = 1; i <= mNode; i++){
                    x += color[i] == 0;
                    y += color[i] == 1;
                }
                ans += max(x, y);
            }
        }
        for(int i = 0; i <= mNode; i++)
            adj[i].clear();
        cout <<"Case " <<ca <<": "<< ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}