class Solution {
public:
    bool isAnagram(string s, string t) {
        int map[256] = {0};
        for(int i=0 ; i<s.length() ; i++)
        {
            map[s[i]]++;
        }
        for(int i=0 ; i<t.length() ; i++){
            map[t[i]]--;
        }
        for(int i=0 ; i<256 ; i++){
            if(map[i]!=0){
                return false;
            }
        }
        return true;
    }
};