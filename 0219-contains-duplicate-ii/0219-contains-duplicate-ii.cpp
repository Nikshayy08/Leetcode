class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int i=0;
        bool isDup = false;
        while(i<min(k,int(nums.size()))){
            if(set.count(nums[i])){
                isDup = true;
                break;
            }
            set.insert(nums[i]);
            i++;
        }
        if(isDup) return true;
        while(i<nums.size()){
            if(set.count(nums[i])){
                isDup = true;
                break;
            }
            set.insert(nums[i]);
            set.erase(nums[i-k]);   
            i++;
        }
        return isDup;
    }
};