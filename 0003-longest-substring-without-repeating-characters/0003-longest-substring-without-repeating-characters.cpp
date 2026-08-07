class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_map<char,int> map;
        int i=0;
        int j=0;
        while(i<s.length()){
            if(map.count(s[i]) && map[s[i]]>=j){
                j=map[s[i]]+1;
            }
            map[s[i]] = i;
            maxlen = max(maxlen,i-j+1);
            i+=1;
        }
        return maxlen;
    }
};















// int maxLen = 0;
//         int i=0;
//         int j=0;
//         unordered_set<char> set;
//         while(i<s.length()){
//             while(set.count(s[i])){
//                 set.erase(s[j]);
//                 j+=1;
//             }
//             set.insert(s[i]);
//             maxLen = max(maxLen,i-j+1);
//             i+=1;
//         }
//         return maxLen;