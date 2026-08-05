class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        unordered_set<string> seen; // to store all the strings
        unordered_set<string> set; // to store all the answers
        vector<string> ans;
        string str;
        int i=0;
        if(s.length()>=10){
            str = "";
            while(i<10){
                str.push_back(s[i]);
                i++;
            }
        }
        seen.insert(str);
        while(i<s.length()){
            str.push_back(s[i]);
            str.erase(0,1); // str.erase(position, number_of_characters);
            if(seen.count(str)){
                set.insert(str);
            }
            else if(str!=""){
                seen.insert(str);
            }
            i++;
        }
        for(auto st : set){
            ans.push_back(st);
        }
        return ans;
    }
};