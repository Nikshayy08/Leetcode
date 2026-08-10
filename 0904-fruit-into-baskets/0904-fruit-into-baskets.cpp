class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        long long maxFruits = 0;
        int i=0;
        int j=0;
        unordered_map<int,int> map;
        while(j<fruits.size()){
            map[fruits[j]]++;
            while(map.size()>2){
                map[fruits[i]]--;
                if(map[fruits[i]]==0){
                    map.erase(fruits[i]);
                }
                i++;
            }
           if(j-i+1>maxFruits){
                maxFruits = j-i+1;
            }
            j++;
        } 
        return maxFruits;
    }
};