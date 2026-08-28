// 1248. Count Number of Nice Subarrays
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 
#include <iostream>
#include <vector>
#include <map>

using namespace std ;


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int ans = 0 ;
        int sum = 0 ;
        mp[0] = 1 ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 0){
                sum += 0 ;
            } else {
                sum += 1 ;
            }

            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
                mp[sum]++;
            } else {
                mp[sum]++ ;
            }

            
        }

        return ans ;
    }
};


int main() {
    // 1. Correct Vector Initialization: Use curly braces {}, not brackets []
    vector<int> arr = {1, 1, 2, 1, 1};
    
    // 2. Define k: It was missing in your main function
    int k = 3;

    // 3. Create an instance of the class
    Solution sol;

    // 4. Call the function on the object (and fix capitalization)
    int result = sol.numberOfSubarrays(arr, k);

    // 5. Output the result
    cout << "Number of subarrays with " << k << " odd numbers: " << result << endl;

    return 0;
}