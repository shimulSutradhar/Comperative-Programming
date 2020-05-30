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
 
int w, h, dp[510] [510];
char board[510] [510];
bool mark[510] [510];
 
bool valid(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w && mark[x] [y] && (board[x] [y] == '.' || board[x] [y] == 'C');
}
 
void bfs(int x, int y){
    int ans = 0;
    queue<pii > q, mq;
    q.push({x, y});
    mq.push({x, y});
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        ans += board[u.first] [u.second] == 'C';
        for(int i = 0; i < 4; i++){
            if(valid(u.first + dr[i], u.second + dc[i])){
                mark[u.first + dr[i]] [u.second + dc[i]] = false;
                q.push({u.first + dr[i], u.second + dc[i]});
                mq.push({u.first + dr[i], u.second + dc[i]});
            }
        }
    }
    while(!mq.empty()){
        pii v = mq.front();
        mq.pop();
        dp[v.first] [v.second] = ans;
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
    int t, x, y, q;
    scanf("%d ", &t);
    for(int ca = 1; ca <= t; ca++){
        scanf("%d%d%d", &h, &w, &q);
        for(int i = 0; i < h; i++)
            scanf("%s", board[i]);
        clr(mark, true);
        clr(dp, -1);
        cout << "Case " << ca << ":\n";
        while(q--){
            scanf("%d%d", &x, &y);
            --x, --y;
            if(dp[x] [y] == -1){
                bfs(x, y);
            }
            cout << dp[x] [y] << "\n";
        }
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}