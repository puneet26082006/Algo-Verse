#include <bits/stdc++.h>
using namespace std ;


class max_heap {
    vector<int> heap ;

    void heapify_down(int idx){
        int n = heap.size() ;
        int left = 2 * idx + 1 ;
        int right = 2 * idx + 2 ;

        int largest = idx ;
        int value = heap[idx];

        if(left < n && value < heap[left]){
            largest = left ;
            value = heap[left];
        } 

        if(right < n && value < heap[right]){
            largest = right ;
            value = heap[right];
        } 

        if(largest == idx) return ;

        swap(heap[idx], heap[largest]);
        heapify_down(largest);

    }

    void heapify_up(int idx){
        if(idx == 0) return ;
        int parent = (idx - 1)/2 ;

        if(heap[parent] < heap[idx]){
            swap(heap[parent], heap[idx]);
            heapify_up(parent);
        }
    }

    public:
        max_heap(vector<int> arr){
            heap = arr ;
        }

        void build(){
            int n = heap.size() ;
            for(int i = n/2 - 1 ; i >= 0 ; i--){
                heapify_down(i);
            }
        }

        int get_max(){
            if(heap.size() == 0){
                return -1 ;
            } else {
                return heap[0];
            }
        }

        void insert(int val){
            heap.push_back(val);
            heapify_up(heap.size() - 1);
        }

        void remove(){
            int n = heap.size() ;
            swap(heap[0], heap[n - 1]);

            heap.pop_back() ;

            if(heap.size() == 0) return ;

            heapify_down(0);
        }
};

void solve(){
    int n ;
    cin>> n ;

    vector<int > a(n);
    for(auto &it : a) cin>> it ;

    max_heap pq(a);
    pq.build() ;

    cout<< pq.get_max() <<endl ;

    pq.remove() ;

    cout<< pq.get_max() <<endl ;

    pq.insert(40);

    cout<< pq.get_max() <<endl ;

}

int main(){
    int t = 1 ;
    // cin>> t ;

    while(t--){
        solve();
    }
}