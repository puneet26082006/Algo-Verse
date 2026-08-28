#include <bits/stdc++.h>
using namespace std ;

int partition(vector<int>& a, int si, int ei){
    int cnt = 0 ;
    for(int i = si + 1 ; i <= ei ; i++){
        if(a[i] < a[si]){
            cnt++ ;
        }
    }

    int partition_idx = si + cnt ;
    swap(a[si], a[partition_idx]);

    int i = si ;
    int j = partition_idx + 1;

    while(i <= partition_idx && j <= ei){
        if(a[i] < a[partition_idx]){
            i++ ;
            continue ;
        }

        if(a[j] >= a[partition_idx]){
            j++ ;
            continue ;
        }

        swap(a[i], a[j]);
        i++ ;
        j++ ;
    }


    return partition_idx ;
}


void quickSort(vector<int>& a, int si, int ei){
    if(si >= ei){
        return ;
    }

    int p = partition(a, si, ei);
    quickSort(a, si, p - 1);
    quickSort(a, p + 1, ei);
}

void solve(){
    int n ;
    cin>> n ;

    vector<int> a(n);
    for(auto &it : a) cin>> it ;

    quickSort(a, 0, n - 1);

    for(auto &it : a) cout<< it <<" ";
    cout<<endl ;
}

int main(){
    int t = 1 ;

    while(t--){
        solve();
    }
}