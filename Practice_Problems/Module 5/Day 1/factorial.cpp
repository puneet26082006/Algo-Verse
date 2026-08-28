// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J

#include <iostream>
using namespace std ;
 
long long factorial(long long n){
    if(n == 0) return 1 ;
    
    return factorial(n - 1) * n ;
}
 
int main(){
    long long n ;
    cin>> n ;
    
    cout<< factorial(n) <<endl ;
}