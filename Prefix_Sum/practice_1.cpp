#include <iostream>
#include <vector>
using namespace std ;

int main(){
    long long n , q ;
    cin>> n >> q ;

    vector<long long> v(n);
    for(auto &it : v){
        cin >>it ;
    }

    vector<long long > pre(n);
    pre[0] = v[0];

    for(long long i = 1 ; i < n ; i++){
        pre[i] = pre[i - 1] + v[i];
    }
    
    while(q--){
        long long a,b ;
        cin>>a >> b ;

        a-- ;
        b-- ;


        cout<< pre[b] - ((a == 0) ? 0 : pre[a - 1]) << endl;




    }
}