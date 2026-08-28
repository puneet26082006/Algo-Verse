// https://atcoder.jp/contests/abc103/tasks/abc103_c


#include <iostream>
#include <vector>
using namespace std ;

int main(){
    int n ;
    cin>> n ;

    vector<int > v(n);
    for(auto &it : v) cin>> it ;

    int sum = 0 ;
    for(auto &it : v) sum += it ;

    cout<< sum - n << endl ;

}