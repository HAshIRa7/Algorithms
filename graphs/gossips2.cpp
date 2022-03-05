#include <iostream> 
#include <vector> 
#include <queue>   

using namespace std; 

struct point {
    int x; 
    int y; 
};  

struct graph {
    vector<vector<int>> dist; 
    int n, m;
    graph(int n, int m) : n(n), m(m)  {  
        dist = vector<vector<int>>(n, vector<int> (m)); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dist[i][j] = -1;
            }
        }
    } 

    void modify_bfs(vector<point>& sp) { 
        queue<point> q; 
        for(size_t i = 0; i < sp.size(); i++) {
            q.push(sp[i]);
            int z = sp[i].x;
            int d = sp[i].y;
            dist[z][d] = 0;
        } 
        while(!q.empty()) {
            point p = q.front(); 
            q.pop(); 
            if(p.x + 1 != n && dist[p.x + 1][p.y] < 0) {
                dist[p.x + 1][p.y] = dist[p.x][p.y] + 1; 
                q.push({p.x + 1, p.y});
            } 
            if(p.x != 0 && dist[p.x - 1][p.y] < 0) {
                dist[p.x - 1][p.y] = dist[p.x][p.y] + 1; 
                q.push({p.x - 1, p.y});
            }
            if(p.y + 1 != m && dist[p.x][p.y + 1] < 0) {
                dist[p.x][p.y + 1] = dist[p.x][p.y] + 1; 
                q.push({p.x, p.y + 1});
            }
            if(p.y != 0 && dist[p.x][p.y - 1] < 0) {
                dist[p.x][p.y - 1] = dist[p.x][p.y] + 1; 
                q.push({p.x, p.y - 1});
            }
        }
    } 

    int GetMax(vector<point>& sp) { 
        modify_bfs(sp); 
        int max = -1; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dist[i][j] > max) { 
                    max = dist[i][j];
                }
            }
        } 
        return max; 
    }
};  

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int n, m, k; 
    cin >> n >> m >> k;     
    vector<point> sp; 
    for(int i = 0; i < k; i++) { 
        int x, y;
        cin >> x >> y;  
        sp.push_back({x, y});  
    }   
    graph g(n, m); 
    cout <<  g.GetMax(sp) << "\n"; 
    return  0; 
}