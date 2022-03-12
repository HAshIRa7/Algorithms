#include <iostream>  
 
using namespace std;   

uint64_t fast_pow(uint64_t x, uint64_t mod, uint64_t pow) {  
    if (pow == 0) {
        return 1;
    }
    if(pow % 2 == 1) {
        return (fast_pow(x, mod, pow - 1) * x) % mod; 
    } else {
        uint64_t tmp = (fast_pow(x, mod, pow / 2));  
        return (tmp * tmp) % mod;
    }
}

uint64_t inverse_elem(uint64_t x, uint64_t mod) {  
    //знаем, что x ^ (mod - 1) == 1 (mod m) 
    //надо найти x ^ (mod - 2) mod m 
    return fast_pow(x, mod, mod - 2);
}

int main(void) {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 

    uint64_t p, m;
    cin >> p >> m; 

    cout << inverse_elem(p, m) << "\n";
    return 0;
}