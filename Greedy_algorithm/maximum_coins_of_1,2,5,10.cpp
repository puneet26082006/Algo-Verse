// class Solution {
// 	public:
// 	int findMin(int n) {
// 		// code here
// 		vector<int> arr = {1, 2, 5, 10} ;
// 		int sum = 0 ;
		
// 		int ans = 0 ;
		
// 		for (int i = arr.size() - 1 ; i >= 0 ; i--) {
			
// 			while (sum < n) {
// 				sum += arr[i];
// 				ans++ ;
// 			}
			
// 			if (sum == n) {
// 				break ;
// 			}
			
// 			if (sum > n) {
// 				sum -= arr[i];
// 				ans-- ;
// 			}
			
// 		}
		
// 		return ans ;
// 	}
// };
