#include <iostream> 
#include <vector> 

using namespace std;   

struct point {
    int x; 
    int y; 
    int order; 
}; 

struct graph { 
    int n, m; 
    vector<vector<int>> v;  
    vector<int> color;
    size_t comp;
    graph(int n, int m) : n(n), m(m) { 
        v = vector<vector<int>>(n, vector<int>(m));
        comp = 0;
    } 

    void ini(size_t count) {
        color.resize(count); 
    }
     
    void add(char c, int i, int j, int cur) {
        if(c == '+') {
            v[i][j] = cur;
        } else {
            v[i][j] = -1;
        }
    } 

    void dfs(vector<point>& sp) { 
        for(size_t i = 0; i < sp.size(); i++) {
            if(color[sp[i].order] == 0) {
                comp++; 
                dfs_go(sp[i]); 
            }
        } 
    }  

    void dfs_go(point const &p) { 
        int order = p.order; 
        int x = p.x; 
        int y = p.y;  
        color[order] = 1;
        if(x != 0 && v[x - 1][y] > 0 && color[v[x - 1][y]] == 0) {
            dfs_go({x - 1, y, v[x - 1][y]}); 
        }
        if(x + 1 != n && v[x + 1][y] > 0 && color[v[x + 1][y]] == 0) {
            dfs_go({x + 1, y, v[x + 1][y]});
        }
        if(y != 0 && v[x][y - 1] > 0 && color[v[x][y - 1]] == 0) {
            dfs_go({x, y - 1, v[x][y - 1]});
        }
        if(y + 1 != m && v[x][y + 1] > 0 && color[v[x][y + 1]] == 0) {
            dfs_go({x, y + 1, v[x][y + 1]});
        } 
        color[order] = 2; 
    }

    int GetComp(vector<point>& sp) { 
        dfs(sp);
        return comp; 
    }
};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n, m; 
    cin >> n >> m; 

    graph g(n, m); 
    vector<point> sp; 
    int count = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; 
            cin >> c; 
            g.add(c, i, j, count);
            if(c == '+') {  
                sp.push_back({i, j, count});
                count++; 
            }
        } 
    } 
    g.ini(count); 
    cout << g.GetComp(sp) << "\n";
    return 0; 
}