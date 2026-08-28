// Given an array of N elements, answer the following Q queries
// ● Query: L, R
// ● Result = A[L] + 2 * A[L + 1] + 3 * A[L + 2] + .... (R - L + 1) * A[R]

#include <iostream >
#include <vector >
using namespace std ;

int main(){
    int n, q ;
    cin>> n >> q;

    vector<int>A(n + 1);

    for(int i = 1 ; i <= n ; i++){
        cin>>A[i] ;
    }

    vector<int>pre1(n + 1, 0);
    vector<int>pre2(n + 1, 0);

    for(int i = 1 ; i <= n ; i++){
        pre1[i] = pre1[i - 1] + (i * A[i]);
        pre2[i] = pre2[i - 1] + A[i];
    }

    
    while(q--){
        int l, r ; 
        cin>> l >> r ;
        

        cout<< pre1[r] - pre1[l - 1] - ((l - 1) * (pre2[r] - pre2[l - 1])) << endl ;



    }
}