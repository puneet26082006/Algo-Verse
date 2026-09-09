// struct Node {
//     vector<int> children ;
//     int ending_below ;
//     int ending_here ;

//     Node(){
//         children.resize(2, -1);
//         ending_below = 0 ;
//         ending_here = 0 ;
//     }
// };

// struct Trie {
//     vector<Node> tree ;
//     int size = 0 ;
//     Trie() {
//         tree.push_back(Node());
//         size++ ;
//     }

//     void add(int num) {
//         int curr = 0 ;
//         for(int i = 31 ; i >= 0 ; i--){
//             int bit = (num >> i) & 1 ;
//             if(tree[curr].children[bit] == -1){
//                 tree[curr].children[bit] = size ;
//                 tree.push_back(Node());
//                 size++ ;
//             }
//             curr = tree[curr].children[bit] ;
//             tree[curr].ending_below++ ;
//         }
//         tree[curr].ending_here++ ;
//     }

//     int get_max_xor(int num){
//         int curr = 0 ;

//         int max_xor = 0 ;
//         for(int i = 31 ; i >= 0 ; i--){
//             int bit = (num >> i) & 1 ;
//             int opp_bit = 1 - bit ;


//             if(tree[curr].children[opp_bit] != -1){
//                 max_xor |= (1 << i) ;
//                 curr = tree[curr].children[opp_bit];
//             } else {
//                 curr = tree[curr].children[bit];
//             }
//         }

//         return max_xor ;
//     }
// };

// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int n = nums.size() ;

//         Trie trie ;
//         for(auto &it : nums) {
//             trie.add(it) ;
//         }

//         int ans = 0 ;
//         for(auto &it : nums){
//             ans = max(ans, trie.get_max_xor(it));
//         }

//         return ans ;
//     }
// };