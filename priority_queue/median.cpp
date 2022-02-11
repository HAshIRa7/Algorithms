#include <iostream> 
#include <vector> 
#include <queue>

using namespace std; 

int main() {

    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int N; 
    cin >> N;  

    priority_queue<int> left_side; 
    priority_queue<int, vector<int>, greater<int>> right_side; 
    left_side.push(INT32_MIN);
    right_side.push(INT32_MAX);
    int left_inv = 0; 
    int right_inv = 0;  
    int current_median;

    for(int i = 0; i < N; i++) {
        int number;
        cin >> number; 
        if(number == 0) {
            int x; 
            cin >> x; 
            if(left_inv == 0 && right_inv == 0) {
                current_median = x; 
                right_inv++;
            }
            else if(right_inv > left_inv) { 
                if(x >= current_median) { 
                    right_side.push(x);
                } else {
                    right_side.push(current_median);
                    if(x >= left_side.top()){
                        current_median = x; 
                    } else {
                        current_median = left_side.top(); 
                        left_side.pop(); 
                        left_side.push(x); 
                    } 
                }
                left_inv++;
            } else if(right_inv == left_inv) {
                if(x <= current_median) {
                    left_side.push(x);
                } else  {
                    left_side.push(current_median); 
                    if(x <= right_side.top()) {
                        current_median = x; 
                    } else {
                        current_median = right_side.top(); 
                        right_side.pop(); 
                        right_side.push(x);
                    }
                }
                right_inv++;
            }
        } 
        if(number == 1) {
            cout << current_median << "\n";
        }
    } 

    return 0;
}