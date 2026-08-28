#include <iostream>
#include <vector>
#include <map>
using namespace std ;

int main() {
    long long n, x ;
    cin>> n >> x ;

    vector<long long>v(n);
    for(auto &it : v) cin>> it ;

    map<long long, long long>mp ;
    // mp[0] = 1 ;
    long long sum = 0 ;
    long long ans = 0 ;

    for(long long i = 0 ; i < n ; i++){
        sum += v[i];
        ans += mp[sum - x];
        if(sum - x == 0) ans ++ ;
        mp[sum]++ ;

    }

    cout<< ans <<endl ;    //  TC : O(nlog(n))
}