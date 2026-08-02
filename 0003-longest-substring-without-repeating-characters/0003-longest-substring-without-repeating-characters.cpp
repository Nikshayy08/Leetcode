class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int maxLen = 0;
        unordered_set<char> set;
        int i = 0;
        int j = 0;
        while(i<s.length()){
            while(set.count(s[i])){  // is duplicate exist in the set
                set.erase(s[j]);  // erase the first occurance of that ch
                j+=1;   // reduce the size of the window
            }
            set.insert(s[i]);
            maxLen = max(maxLen,i-j+1);  // update the maxLen with maximum lenghtt of nrc in string
            i+=1;
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen = 0;
//         int n = s.length();
//         unordered_set<char> set;
//         for(int i=0 ; i<n ; i++){
//             int len = 0;
//             for(int j = i ; j<n ; j++){
//                 if(set.count(s[j])){
//                     // erase all elements of set
//                     set.clear();
//                     break;
//                 }
//                 set.insert(s[j]);
//                 len+=1;
//             }
//             maxLen = max(len,maxLen);
//         }
//         return maxLen;
//     }
// };