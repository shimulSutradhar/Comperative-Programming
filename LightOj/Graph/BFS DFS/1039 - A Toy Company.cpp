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
 
int n;
string start, target;
bool constaint[55][3][27], visited[27] [27] [27];
int dist[27] [27] [27];
 
bool valid(string a){
    for(int i = 0; i < n; i++)
        if(!constaint[i] [0] [a[0] - 'a'] && !constaint[i] [1] [a[1] - 'a'] && !constaint[i] [2] [a[2] - 'a'])
            return false;
    return true;
}
 
string nodes(string a, int at){
    if(at == 0){
        if(a[0] == 'a') a[0] = 'z';
        else --a[0];
        return a;
    }
    if(at == 1){
        if(a[0] == 'z') a[0] = 'a';
        else ++a[0];
        return a;
    }
    if(at == 2){
        if(a[1] == 'a') a[1] = 'z';
        else --a[1];
        return a;
    }
    if(at == 3){
        if(a[1] == 'z') a[1] = 'a';
        else ++a[1];
        return a;
    }  
    if(at == 4){
        if(a[2] == 'a') a[2] = 'z';
        else --a[2];
        return a;
    }
    if(at == 5){
        if(a[2] == 'z') a[2] = 'a';
        else ++a[2];
        return a;
    }  
}
 
void bfs(){
    queue<string> q;
    q.push(start);
    if(!valid(start))
        return;
    visited[start[0] - 'a'] [start[1] - 'a'] [start[2] - 'a'] = false;
    dist[start[0]- 'a'] [start[1]- 'a'] [start[2]- 'a'] = 0;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            string v = nodes(u, i);
            if(valid(v) && visited[v[0]- 'a'] [v[1]- 'a'] [v[2]- 'a']){
                q.push(v);
                visited[v[0]- 'a'] [v[1]- 'a'] [v[2]- 'a'] = false;
                dist[v[0]- 'a'] [v[1]- 'a'] [v[2]- 'a'] = dist[u[0]- 'a'] [u[1]- 'a'] [u[2]- 'a'] + 1;
                if(v == target)
                    return;  
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
    int t;
    string a, b, c;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> start >> target;
        cin >> n;
        clr(constaint, true);
        clr(visited, true);
        clr(dist, -1);
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c;
            for(auto m : a)
                constaint[i] [0] [m - 'a'] = false;
            for(auto m : b)
                constaint[i] [1] [m - 'a'] = false;
            for(auto m : c)
                constaint[i] [2] [m - 'a'] = false;
        }
        bfs();
        cout << "Case "<< ca << ": " << dist[target[0]- 'a'] [target[1]- 'a'] [target[2]- 'a'] << "\n";
    }
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
 