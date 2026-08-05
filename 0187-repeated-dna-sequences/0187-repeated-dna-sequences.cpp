class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen; // to store all the strings
        unordered_set<string> set; // to store all the answers
        vector<string> ans;
        string str;
        for(int i=0 ; i<=s.length() ; i++){
            str = "";
            if(i+10<=s.length()){
                for(int j=i ; j<i+10 ; j++){
                    str.push_back(s[j]);
                }
            }
            if(seen.count(str)){
                set.insert(str);
            }
            if(str!="")
                seen.insert(str);
        }
        for(auto str : set){
            ans.push_back(str);
        }
        return ans;
    }
};