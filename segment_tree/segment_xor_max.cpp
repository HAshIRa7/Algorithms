#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;  

struct Sum_tree{ 
    vector<int> tree; 

    Sum_tree(int n, vector<int>&v) {
        tree = vector<int>(4 * n + 1); 
        tree[0] = 0; 
        build(v, 1, 0, n - 1); 
    } 

    void build(vector<int>& v, int k, int left, int right) {
        if(right == left){ 
            tree[k] = v[left]; 
            return;
        } 
        //cout << "there" << "\n";
        int mid = (left + right) / 2;  
        build(v, 2 * k, left, mid); 
        build(v, 2 * k + 1, mid + 1, right); 
        tree[k] = tree[2 * k] ^ tree[2 * k + 1];
    } 

    void PrintV() {
        for(int i = 0; i <= tree.size(); i++) {
            cout << i << " " << tree[i] << "\n";
        }
    }

    int xor_(vector<int>& v,int k, int t_left, int t_right, int left, int right) {
        if(left > right) {
            return 0;
        }
        if(t_left == left && t_right == right) {
            return tree[k];
        }  
        int mid = (t_left + t_right) / 2;
        return xor_(v, 2 * k, t_left, mid, left, min(mid, right)) ^ xor_(v, 2 * k + 1, mid + 1, t_right, max(left, mid + 1), right);
    }  

    void update(vector<int>& v, int k, int t_left, int t_right, int i, int new_) {
        if(t_left == t_right && i == t_left) {
            v[i] = new_; 
            tree[k] = new_;
            return;
        } 

        int mid = (t_left + t_right) / 2; 
        if(i <= mid) {
            update(v, 2 * k, t_left, mid, i, new_); 
        } else {
            update(v, 2 * k + 1, mid + 1, t_right, i, new_); 
        }
        tree[k] = tree[2 * k] ^ tree[2 * k + 1];
    }
};

int main() { 

    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n; 
    int m; 
    cin >> m; 
    vector<int> v(n); 
    for(int i = 0; i < n; i++) {
        cin >>  v[i]; 
    }  

    Sum_tree tree(n, v);  
    //tree.PrintV();   

    for(int j = 0; j < m; j++) {
        int x, y, z; 
        cin >> x >> y >> z; 

        if(x == 1) { 
            cout << tree.xor_(v, 1, 0, n - 1, y, z) << "\n"; 
        }  
        if(x == 2) {
            tree.update(v, 1, 0, n - 1, y, z); 
        }
    }

    return 0; 
}