#include<iostream>
using namespace std ;

int natural_no(int n){
    if(n == 1){
        return 1 ;
    }

    if(n == 0){
        return 0 ;
    }

    return natural_no(n - 1) + n ;
}

int main(){
    int n ;
    cin>> n ;

    cout<< natural_no(n) <<endl;
}