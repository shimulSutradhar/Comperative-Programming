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
 
struct Edge{
    int x, y, canJump;
    Edge(int _x, int _y, int _canJump){
        x = _x;
        y = _y;
        canJump = _canJump;
    }
};
 
struct Node{
    int x, y, haveJump, cost;
    Node(int _x, int _y, int _haveJump, int _cost){
        x = _x;
        y = _y;
        haveJump = _haveJump;
        cost = _cost;
    }
    bool operator < (const Node &a) const{
        return cost > a.cost;
    }
};
 
 
int height, width;
char board[15] [15];
int dist[12] [12] [102];
bool mark[15] [15];
bool valid(int x, int y){
    return x >= 0 and x < height and y >= 0 and y < width and mark[x] [y];
}
void dijkstra(int x, int y, int knightNum, int c){
    int Ncost, jLeft;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
            dist[i] [j] [c] = inf;
    }
 
    clr(mark, true);
    dist[x] [y] [c] = 0;
    mark[x] [y] = false;
    queue<Node> q;
    q.push(Node(x, y, 0, 0));
   
    while(!q.empty()){
        Node u = q.front();
        q.pop();
        if(u.haveJump == 0){
            Ncost = dist[u.x] [u.y] [c] + 1;
            jLeft = knightNum - 1;
        }else{
            Ncost = dist[u.x] [u.y] [c];
            jLeft = u.haveJump - 1;
        }
        for(int i = 0; i < 8; i++){
            if(valid(u.x + hr[i], u.y + hc[i])){
                mark[u.x + hr[i]] [u.y + hc[i]] = false;
                dist[u.x + hr[i]] [u.y + hc[i]] [c] = Ncost;
                q.push(Node(u.x + hr[i], u.y + hc[i], jLeft, Ncost));
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
    int t, m, s, d, x, y, w;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> height >> width;
        vector<Edge> v;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                cin >> board[i] [j];
                if(board[i] [j] >= '1' && board[i] [j] <= '9'){
                    v.push_back(Edge(i, j, board[i] [j] - '0'));
                }
            }
        }
        for(int i = 0; i < v.size(); i++)
            dijkstra(v[i].x, v[i].y, v[i].canJump, i);
        i64 ans = inf;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                i64 sub_ans = 0;
                for(int k = 0; k < v.size(); k++){
                    sub_ans += dist[i] [j] [k];
                }
                ans = min(ans, sub_ans);
            }
        }
        cout << "Case " << ca << ": ";
        if(ans >= inf)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}