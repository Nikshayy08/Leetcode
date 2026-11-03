class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int i=0;
        while(i<nums.size()){
            int lookingFor = target - nums[i];
            auto it = map.find(lookingFor);
            if(it!=map.end()){
                return {i,it->second};
            }
            map.insert({nums[i],i});
            i++;
        }
        return {};
    }
};






// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> mp;
//         int i = 0;
//         // first we find the element we are looking for 
//         // lookingFor - target - element at ith index.
//         //  if we dont find the lookingFor inside map, simply insert the current element at ith and its index.
//         // ans if the lookingFor gets found, return the current index i and index of element in map (it->second)
//         while(i<nums.size()){
//             int lookingFor = target - nums[i];
//             auto it = mp.find(lookingFor);
//             if(it!=mp.end()){
//                 return {i,it->second};
//             }
//             mp.insert({nums[i],i});
//             i++;
//         }
//         return {-1};
//     }
// };