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

uint64_t factorial(uint64_t n, uint64_t p) { 
    uint64_t r = 1;
    for(uint64_t i = 2; i <= n; i++) {
        r = ((r * i) % p); 
    } 
    return r; 
}
uint64_t comb(uint64_t n, uint64_t k, uint64_t p) { 
    uint64_t res = factorial(n, p);   
    uint64_t f = factorial(n - k, p); 
    uint64_t s = factorial(k, p);
    uint64_t invf = inverse_elem(f, p);  
    uint64_t invs = inverse_elem(s, p); 
    res = (((res * invf) % p) * invs) % p;
    return res; 
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    uint64_t n, k, p;
    cin >> n >> k >> p;  
    cout << comb(n, k, p) << "\n";
    return 0; 
}