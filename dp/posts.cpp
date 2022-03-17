#include <iostream> 
#include <algorithm>  
#include <vector>
#include <climits>

using namespace std;  

void printvv(vector<vector<int>>& v, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " "; 
        } 
        cout << '\n';
    }
}
int main() { 
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n, m; 
    cin >> n >> m; 
    vector<int> coord(n); 
    for(int i = 0; i < n; i++) {
        cin >> coord[i]; 
    } 
    //optimal is mean that the summ of minimal distance between village_j(0 <= j <= i) and its nearest post office is minmak
    //best[i][r] - optimal to place r offices from coordinates[0] to coordinates[i] and one is in the coordinates[i]  
    //of course r <= i and r starts from 1 to m include this 
    /* my dp :  
        best[i][r] = min {
                            best[i - 1][r - 1], 
                            best[i - 2][r - 1] + sum(i - 1) <- расстояние до ближайшего почтового отделения 
                            best[i - 3][r - 1] + sum(i - 1, i - 2) <- сумма расстояний от i - 1 до ближайшего почтового отделения, от i-2 до ближайшего почтового отеделения 
                            ... 
        }
    */ 
    vector<vector<int>> best(n, vector<int>(m + 1)); 
    int coord_count = 0;
    for(int i = 1; i < n; i++) { 
        for(int r = 1; r <= m; r++) { 
            if(r == 1) {  
                coord_count += i * (coord[i] - coord[i - 1]); 
                best[i][1] = coord_count; 
            } else { 
                best[i][r] = INT_MAX; 
            }
        }
    }

    for(int i = 0; i < n; i++) { 
        for(int r = 2; r <= m; r++) {  
            for(int j = i - 1; j >= 0; j--) { 
                int coord_res = 0; 
                for(int k = j + 1; k < i; k++) {
                    coord_res += min(coord[i] - coord[k], coord[k] - coord[j]);
                }
                if(best[i][r] > best[j][r - 1] + coord_res) {
                    best[i][r] = best[j][r - 1] + coord_res; 
                }
            }
        }
    }   
    //printvv(best, n, m + 1);
    int res = INT_MAX; 
    int index = -1;
    for(int i = n - 1; i >= m - 1; i--) { 
        int sum = 0; 
        for(int j = i + 1; j < n; j++) {
            sum += coord[j] - coord[i];
        } 
        if(res > best[i][m] + sum) {
            res = best[i][m] + sum;
            index = i;
        }
    } 
    cout << res << "\n"; 
    //cout << index << "\n";
    //как понять кого берем с собой 
    vector<int> answ; 
    answ.push_back(coord[index]); 
    for(int r = m; r >= 2; r--) {
        for(int i = n - 1; i >= 0; i--) {
            int coord_res = 0; 
            for(int j = i + 1; j < index; j++) {
                coord_res += min(coord[index] - coord[j], coord[j] - coord[i]);
            }
            if(best[index][r] == best[i][r - 1] + coord_res) {
                answ.push_back(coord[i]); 
                index = i;
                break;
            }
        }
    } 

    for(size_t i = 0; i < answ.size(); i++) {
        cout << answ[answ.size() - i - 1] << " ";
    } 
    cout << "\n";
    return 0;
}