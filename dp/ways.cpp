#include <iostream>   
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n, m, k; // количество строк, количество столбцов, количество доступных ходов  
    cin >> n >> m >> k;  

    int st_x; 
    int st_y;  
    int f_x; 
    int f_y; 

    vector<vector<char>> table(n, vector<char>(m));  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> table[i][j];  
            if(table[i][j] == '@') {
                st_x = i; 
                st_y = j; 
            } 
            if(table[i][j] == '#') {
                f_x = i; 
                f_y = j;
            }
        }
    } 

    vector<vector<vector<uint64_t>>> dp(n, vector<vector<uint64_t>>(m, vector<uint64_t>(k + 1))); 
    dp[st_x][st_y][0] = 1; 
    for(int h = 1; h <= k; h++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { 
                if(table[i][j] != '+') {
                    dp[i][j][h] += (i > 0) ? dp[i - 1][j][h - 1] : 0; 
                    dp[i][j][h] += (i < n - 1) ? dp[i + 1][j][h - 1] : 0; 
                    dp[i][j][h] += (j > 0) ? dp[i][j - 1][h - 1] : 0; 
                    dp[i][j][h] += (j < m - 1) ? dp[i][j + 1][h - 1] : 0;
                }
            }
        }  
        //cout << h << "\n";
        //for(int i = 0; i < n; i++) {
        //    for(int j = 0; j < m; j++) {
        //        cout << dp[i][j][h] << " "; 
        //    } 
        //    cout << "\n";
        //}
    } 

    cout << dp[f_x][f_y][k] << "\n";
    return 0;
}