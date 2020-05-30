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
 
vector<int> adj[1050];
bool visit[1050], nodes[1050];
int money[1050], nodeNumber, totalCost;
 
void bfs(int a){
    queue<int> q;
    q.push(a);
    visit[a] = false;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ++nodeNumber;
        totalCost += money[v];
        for(auto m : adj[v]){
            if(visit[m]){
                visit[m] = false;
                q.push(m);
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
    int t, n, m, x, y;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++){
        scanf("%d%d", &n, &m);
        clr(money, 0);
        for(int i = 1; i <= n; i++)
            scanf("%d", &money[i]);
        clr(visit, true);
        clr(nodes, true);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
            nodes[x] = nodes[y] = false;
        }
        bool flag = true;
        int pre = -1;
        for(int i = 1; i <= n; i++){
            // error(i,n);
            if(visit[i] && !nodes[i]){
                totalCost = nodeNumber = 0;
                bfs(i);
                // error(totalCost,nodeNumber);
                if(totalCost % nodeNumber != 0){
                    flag = false;
                }
                if(pre == -1){
                    pre = totalCost / nodeNumber;
                }else{
                    if(pre != totalCost / nodeNumber){
                        flag = false;
                    }
                }
            }
            if(!flag)
                break;
        }
        if(flag){
            for(int i = 1; i <= n; i++)
                if(visit[i] && money[i] != pre){
                    flag = false;
                    break;
                }
        }
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        cout <<"Case " << ca << ": "<< (flag?"Yes":"No") << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
 