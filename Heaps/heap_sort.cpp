#include <bits/stdc++.h>
using namespace std;

class max_heap
{
    vector<int> heap;

    void heapify_down(int idx)
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        int largest = idx;
        int value = heap[idx];

        int n = heap.size();

        if (left < n && value < heap[left])
        {
            largest = left;
            value = heap[left];
        }

        if (right < n && value < heap[right])
        {
            largest = right;
            value = heap[right];
        }

        if (largest == idx)
            return;

        swap(heap[largest], heap[idx]);
        heapify_down(largest);
    }

public:
    max_heap(vector<int> &arr)
    {
        heap = arr;
    }

    void build()
    {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify_down(i);
        }
    }

    void heapify(int idx, int last)
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        int largest = idx;
        int value = heap[idx];

        if (left < last && value < heap[left])
        {
            largest = left;
            value = heap[left];
        }

        if (right < last && value < heap[right])
        {
            largest = right;
            value = heap[right];
        }

        if(largest == idx) return ;

        swap(heap[idx], heap[largest]);
        heapify(largest, last);


    }

    void sort(){
        int n = heap.size() ;
        for(int i = n - 1 ; i >= 0 ; i--){
            swap(heap[0], heap[i]);
            heapify(0, i);
        }
    }

    void print(){
        for(auto &it : heap) cout<< it <<" " ;
        cout<< endl ;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    max_heap pq(a);

    pq.build();

    pq.sort();

    // for(auto &it : a) cout<< it <<" ";
    
    pq.print() ;
}

int main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }
}