// to find the prime factors of a number 

#include <iostream> 
#include <vector> 
using namespace std ;

int main(){
    int n ;
    cin>> n ;

    vector<int> prime_factor ;

    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            while(n % i == 0){
                prime_factor.push_back(i);
                n/= i ;
            }

        }

    }
    
    if(n > 1){
        prime_factor.push_back(n);
    }

    for(auto &it : prime_factor) cout<< it <<" ";
}