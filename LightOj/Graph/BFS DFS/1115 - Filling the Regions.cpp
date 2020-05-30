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
 
int h, w;
char board[60] [60];
bool mark[60] [60];
 
bool valid(int x, int y, char c){
    return x >= 0 && x < h && y >= 0 && y < w && board[x] [y] != c && mark[x] [y];
}
 
void bfs(int x, int y, char c){
    // if(board[x] [y] == ' ')
    //     return;
    if(board[x] [y] == c)
        return;
    queue<pii> q;
    q.push({x, y});
    mark[x] [y] = false;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(valid(v.f + dr[i], v.s + dc[i], c)){
                mark[v.f + dr[i]] [v.s + dc[i]] = false;
                q.push({v.f + dr[i], v.s + dc[i]});
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
    int t;
    // cin >> t;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++){
        // cin >> h >> w;
        scanf("%d %d", &h, &w);
        error(t, h, w);
        getchar();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                board[i] [j] = getchar();
            getchar();
        }
        for(int i = 0; i < 26; i++){
            clr(mark, true);
            for(int j = 0; j < h; j++){
                if(mark[j] [0])
                    bfs(j, 0, 'A' + i);
                if(mark[j] [w - 1])
                    bfs(j, w - 1, 'A' + i);
            }
            for(int j = 0; j < w; j++){
                if(mark[0] [j])
                    bfs(0, j, 'A' + i);
                if(mark[h - 1] [j])
                    bfs(h - 1, j, 'A' + i);
            }
            for(int k = 0; k < h; k++){
                for(int l = 0; l < w; l++)
                    if(mark[k] [l])
                        board[k] [l] = 'A' + i;
            }
        }
        cout << "Case " << ca << ":\n";
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                cout << board[i] [j];
            cout << "\n";
        }
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}