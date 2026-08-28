1. Modular operations for ( + )

(a + b) % mod = ((a % mod) + (b % mod)) % mod 

2. Modular operations for ( - )

(a - b) % mod = ((a % mod) - (b % mod) + mod) % mod 

3. Modular operation for ( * )

(a * b) % mod = ((a % mod) * (b % mod)) % mod 

4. Modular operations for ( / )

(a / b) = ((a % mod) * ((b^-1) % mod)) % mod 



Code to find (b^-1) :

b^-1 = b^(m - 2) (By Fermat's little theorem) and m is mod .

int m = mod 
int res = 1 ;

for(int i = 0 ; i < m - 2 ; i++){
    res *= m ;
    res %= m ;
}

res -> b^-1 


