#include <iostream>
#include <vector>
using namespace std ;

int main(){
    int n ;
    cin>> n ;

    vector<int> fact ;

    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            fact.push_back(i);
            if(i != n/i){
                fact.push_back(n/i);
            }
        }

    }

    for(auto &it : fact) cout<< it <<" ";

    cout<<endl ;

}