#include <iostream> 
#include <unordered_map>  
#include <map> 
#include <utility> 
#include <set>
#include <functional> 
using namespace std;   
 
const int N = 1000 * 1000 + 19;
int n, m;  

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return (hash1  + 1089) * (hash2 + 67) % N;
    }
};

void Fill(unordered_map<pair<int, int>, int, hash_pair>& points1, int x, int y) {
    pair<int, int> p = make_pair(x, y); 
    points1[p] += 0; 
    if(x != 0) {
        pair<int, int> p1 = make_pair(x - 1, y); 
        points1[p1] += 1; 
    } 
    if(x != n - 1) {
        pair<int, int> p2 = make_pair(x + 1, y); 
        points1[p2] += 1; 
    } 
    if(y != 0) {
        pair<int, int> p3 = make_pair(x, y - 1);
        points1[p3] += 1; 
    } 
    if(y != m - 1) {
        pair<int, int> p4 = make_pair(x, y + 1); 
        points1[p4] += 1; 
    } 
    if(x != 0 && y != 0) {
        pair<int, int> p5 = make_pair(x - 1, y - 1);
        points1[p5] += 1; 
    } 
    if(x != n - 1 && y != 0) {
        pair<int, int> p6 = make_pair(x + 1, y - 1); 
        points1[p6] += 1;
    } 
    if(x != 0 && y != m - 1) {
        pair<int, int> p7 = make_pair(x - 1, y + 1); 
        points1[p7] += 1; 
    } 
    if(x != n - 1 && y != m - 1) {
        pair<int, int> p8 = make_pair(x + 1, y + 1); 
        points1[p8] += 1; 
    }
}

int main(void) {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int l, k; 
    cin >> n >> m >> l >> k; 

    unordered_map<pair<int, int>, int, hash_pair> points1; 
    unordered_map<pair<int, int>, int, hash_pair> points2;  
    map<pair<int, int>, bool> live1;  
    map<pair<int, int>, bool> live2; 

    for(int i = 0; i < l; i++) {
        int x, y;  
        cin >> x >> y;   
        live1[{x, y}] = true;
        Fill(points1, x, y);
    }   

    //cout << "------------------------------------" << "\n";

    //for(auto it : points1) { 
    //    cout << it.first.first << " " << it.first.second <<  " " <<it.second << "\n"; 
    //} 

    //cout << "------------------------------------" << "\n";

    for(int i = 0; i < k; i++) {
        for(auto it : points1) {
            if(live1[it.first] == true && it.second == 2) { 
                //cout << it.first.first << " " << it.first.second << "\n";
                live2[it.first] = true;   
                int x = it.first.first; 
                int y = it.first.second; 
                Fill(points2, x, y);
            } 
            if(it.second == 3) { 
                //cout << it.first.first << " " << it.first.second << "\n";
                live2[it.first] = true;
                int x = it.first.first; 
                int y = it.first.second;  
                Fill(points2, x, y); 
            }
        } 
        points1.clear();  
        live1.clear();
        points1.insert(points2.begin(), points2.end());  
        live1.insert(live2.begin(), live2.end());
        points2.clear(); 
        live2.clear();
    }  

    //cout << "------------------------------------" << "\n";
 
    for(auto it : live1) { 
        cout << it.first.first << " " << it.first.second << "\n";
    } 
    return 0;
}