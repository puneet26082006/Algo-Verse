// class Solution {

//     bool check(string s, string s1){
//         sort(s.begin(), s.end());
//         sort(s1.begin(), s1.end());

//         for(int i = 0 ; i < s.size() ; i++){
//             if(s[i] != s1[i]){
//                 return false ;
//             }
//         }

//         return true ;
//     }
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n = s1.size() ;
//         int m = s2.size() ;

//         if(n > m) return false ;

//         string s = "";
//         for(int i = 0 ; i < n ; i++){
//             s += s2[i];
//         }

//         bool possible = check(s, s1);
//         if(possible) return true ;

//         for(int i = n ; i < m ; i++){
//             s += s2[i];
//             s.erase(s.find(s2[i - n]), 1);

//             possible = check(s, s1);
//             if(possible) return true ;

//         }


//         return false ;    
//     }
// };