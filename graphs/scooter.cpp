#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits>
#include <map> 
#include <set>

using namespace std;    

typedef struct vertex  {
    int i; 
    int j;  
    int d; 
} vertex;

struct pq_less { 
    bool operator ()(vertex const &l, vertex const &r) {
        return l.d < r.d; 
    }
}; 

bool operator < (vertex const &l, vertex const &r) {
    if(l.d > r.d) return false; 
    if(l.d < r.d) return true; 
    if(l.i < r.i) return true; 
    if(l.i > r.i) return false; 
    return l.j < r.j;
}

struct graph { 
    vector<vector<int>> inp;  
    vector<vector<int>> dist;
    int n, m;

    graph(int n, int m) : n(n), m(m) {
        inp = vector<vector<int>>(n, vector<int>(m)); 
        dist = vector<vector<int>> (n, vector<int>(m));  
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dist[i][j] = INT_MAX; 
            }
        } 
    } 

    void add(int i, int j, int h) {
        inp[i][j] = h;
    }  

    void Dijikstra() { 
        dist[0][0] = 0; 
        set<vertex> pq;
        //priority_queue<vertex, vector<vertex>, pq_less> pq; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //pq.push({i, j, dist[i][j]});
                pq.insert({i, j, dist[i][j]});
            }
        } 
        while(!pq.empty()) {
            vertex u = *pq.begin(); 
            pq.erase(pq.begin()); 
            int i = u.i; 
            int j = u.j; 
            if(i + 1 != n && dist[i + 1][j] > dist[i][j] + (inp[i + 1][j] > inp[i][j] ? inp[i + 1][j] - inp[i][j] : 0)) {
                pq.erase({i + 1, j, dist[i + 1][j]});
                dist[i + 1][j] = dist[i][j] + (inp[i + 1][j] > inp[i][j] ? inp[i + 1][j] - inp[i][j] : 0);
                pq.insert({i + 1, j, dist[i + 1][j]});
            } 
            if(i != 0 && dist[i - 1][j] > dist[i][j] + (inp[i - 1][j] > inp[i][j] ? inp[i - 1][j] - inp[i][j] : 0)) { 
                pq.erase({i - 1, j, dist[i - 1][j]});
                dist[i - 1][j] = dist[i][j] + (inp[i - 1][j] > inp[i][j] ? inp[i - 1][j] - inp[i][j] : 0); 
                pq.insert({i - 1, j, dist[i - 1][j]});
            } 
            if(j + 1 != m && dist[i][j + 1] > dist[i][j] + (inp[i][j + 1] > inp[i][j] ? inp[i][j + 1] - inp[i][j] : 0)) {
                pq.erase({i, j + 1, dist[i][j + 1]});
                dist[i][j + 1] = dist[i][j] + (inp[i][j + 1] > inp[i][j] ? inp[i][j + 1] - inp[i][j] : 0);
                pq.insert({i, j + 1, dist[i][j + 1]});
            } 
            if(j != 0 && dist[i][j - 1] > dist[i][j] + (inp[i][j - 1] > inp[i][j] ? inp[i][j - 1] - inp[i][j] : 0)) { 
                pq.erase({i, j - 1, dist[i][j - 1]});
                dist[i][j - 1] = dist[i][j] + (inp[i][j - 1] > inp[i][j] ? inp[i][j - 1] - inp[i][j] : 0);
                pq.insert({i, j - 1, dist[i][j - 1]});
            } 
        }
    } 

    void GetDist() {
        Dijikstra();
        cout << dist[n - 1][m - 1] << "\n";
    }

};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n, m;
    cin >> n >> m;  
    graph g(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int h;
            cin >> h; 
            g.add(i, j, h);
        }
    } 
    g.GetDist();
    return 0;
}