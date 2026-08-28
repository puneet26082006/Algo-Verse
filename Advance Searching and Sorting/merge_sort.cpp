#include <bits/stdc++.h>
using namespace std ;

int temp[100000];

void merge(vector<int>& a, int si, int ei){
    int mid = si + (ei - si)/ 2 ;
    int i = si ;
    int j = mid + 1 ;
    int k = 0 ;

    // vector<int> temp(ei - si + 1);

    while(i <= mid && j <= ei){
        if(a[i] > a[j]){
            temp[k] = a[j];
            k++ ;
            j++ ;
        } else {
            temp[k] = a[i];
            k++ ;
            i++ ;
        }
    }

    while(i <= mid){
        temp[k] = a[i] ;
        k++ ;
        i++ ;
    }

    while(j <= ei){
        temp[k] = a[j] ;
        k++ ;
        j++ ;
    }

    int l = si ;

    for(int i = 0 ; i <= (ei - si) ; i++){
        a[l] = temp[i] ;
        l++ ;
    }
}


void mergeSort(vector<int>& a, int si, int ei){
    if(si >= ei){
        return ;
    }

    int mid = si + (ei - si)/ 2 ;

    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);

    merge(a, si, ei);
}

void solve(){
    int n ;
    cin>> n ;

    vector<int>a(n);
    for(auto &it : a) cin>> it ;

    mergeSort(a, 0, n - 1);

    for(auto &it : a) cout<< it <<" ";
    cout<< endl  ;
}


int main(){
    int t = 1 ;
    // cin>> t ;

    while(t--){
        solve() ;
    }
}