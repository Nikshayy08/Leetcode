class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()){
            return {{""}};
        }
        unordered_map<string , vector<string>> mp;
        for(auto &word : strs){
            string signature = word;
            sort(signature.begin(),signature.end());
            mp[signature].push_back(word);
        }
        vector<vector<string>> result;
        for(auto &entry : mp){
            result.push_back(entry.second);
        }
        return result;
    }
};
