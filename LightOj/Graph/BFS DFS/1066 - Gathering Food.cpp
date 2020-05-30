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
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
struct Node{
    char c;
    int x, y;
    Node(char _c, int _x, int _y){
        c = _c;
        x = _x;
        y = _y;
    }
    bool operator < (const Node & e) const{
        return c < e.c;
    }
};
 
int k, cost[14] [14];
char board[14] [14];
bool visit[14] [14];
 
bool valid(int x, int y, char c){
    return x >= 0 && x < k && y >= 0 && y < k && visit[x] [y] && (board[x] [y] == '.' || board[x] [y] == c + 1);
}
 
void bfs(int x, int y, char c){
    clr(visit, true);
    clr(cost, -1);
    queue<pii> q;
    q.push({x, y});
    visit[x] [y] = false;
    cost[x] [y] = 0;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            if(valid(v.f + dr[i], v.s + dc[i], c)){
                visit[v.f + dr[i]] [v.s + dc[i]] = false;
                cost[v.f + dr[i]] [v.s + dc[i]] = cost[v.f] [v.s] + 1;
                q.push({v.f + dr[i], v.s + dc[i]});
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
    int t;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> k;
        vector<Node> v;
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++){
                cin >> board[i] [j];
                if(board[i] [j] >= 'A' && board[i] [j] <= 'Z'){
                    v.push_back(Node(board[i] [j], i, j));
                }
            }
        sort(all(v));
        int ans = 0;
        bool flag = true;
        for(int i = 0; i < v.size() - 1; i++){
            bfs(v[i].x, v[i].y, v[i].c);
            board[v[i].x] [v[i].y] = '.';
            if(cost[v[i + 1].x] [v[i + 1].y] == -1){
                flag = false;
                break;
            }
            // error(cost[v[i + 1].x] [v[i + 1].y]);
            ans += cost[v[i + 1].x] [v[i + 1].y];
        }
        cout << "Case " << ca << ": ";
        if(flag)
            cout << ans  << "\n";
        else
            cout << "Impossible\n";
 
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
 