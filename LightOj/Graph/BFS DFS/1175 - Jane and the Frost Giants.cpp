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
 
int h, w;
char board[210] [210];
bool visit[210] [210];
 
bool valid(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w && visit[x] [y] && board[x] [y] == '.';
}
 
void bfs(int x, int y, int dist[210] [210]){
    clr(visit, true);
    dist[x] [y] = 1;
    visit[x] [y] = false;
    queue<pii> q;
    q.push({x, y});
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(valid(u.f + dr[i], u.s + dc[i])){
                visit[u.f + dr[i]] [u.s + dc[i]] = false;
                if(dist[u.f + dr[i]] [u.s + dc[i]] > dist[u.f] [u.s] + 1){
                    dist[u.f + dr[i]] [u.s + dc[i]] = dist[u.f] [u.s] + 1;
                    q.push({u.f + dr[i], u.s + dc[i]});
                }
            }
        }
    }
}
 
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, jane[210] [210], fire[210] [210], jx, jy, fx, fy;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++){
        scanf("%d %d", &h, &w);
        vii v;
        getchar();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                board[i] [j] = getchar();
                if(board[i] [j] == 'J')
                    jx = i, jy = j;
                else if(board[i] [j] == 'F')
                    v.push_back({i, j});
            }
            getchar();
        }  
        clr(jane, inf);
        clr(fire, inf);
        bfs(jx, jy, jane);
        for(int i = 0; i < v.size(); i++)
            bfs(v[i].f, v[i].s, fire);
        int ans = inf;
 
        for(int i = 0; i < h; i++){
            if(jane[i] [0] < fire[i] [0] && board[i] [0] != '#')
                ans = min(ans , jane[i] [0]);
            if(jane[i] [w - 1] < fire[i] [w - 1] && board[i] [0] != '#')
                ans = min(ans , jane[i] [w - 1]);
        }
        for(int i = 0; i < w; i++){
            if(jane[0] [i] < fire[0] [i] && board[0] [i] != '#')
                ans = min(ans , jane[0] [i]);
            if(jane[h - 1] [i] < fire[h - 1] [i] && board[h - 1] [i] != '#')
                ans = min(ans , jane[h - 1] [i]);
        }  
        cout << "Case " << ca << ": ";
        if(ans == inf)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}