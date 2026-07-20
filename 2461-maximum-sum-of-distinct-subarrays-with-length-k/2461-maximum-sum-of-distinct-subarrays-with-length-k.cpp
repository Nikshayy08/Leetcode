class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return 0;

        unordered_map<int,int> mp;
        long long sum = 0;
        long long maxSum = 0;
        int dups = 0;

        // Build first window
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2) dups++;
            sum += nums[i];
        }

        if(dups == 0) maxSum = max(maxSum, sum);

        // Slide window
        for(int i = k; i < n; i++){
            int add = nums[i];
            int remove = nums[i-k];

            // Add new element
            mp[add]++;
            if(mp[add] == 2) dups++;
            sum += add;

            // Remove old element
            if(mp[remove] == 2) dups--;
            mp[remove]--;
            if(mp[remove] == 0) mp.erase(remove);
            sum -= remove;

            if(dups == 0) maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

// TLE
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         if(k > nums.size()) return 0;   
//         long maxSum = 0;
//         long sum = 0;
        
//         for(int i=0 ; i <= nums.size()-k ; i++){
//             unordered_set<int> st;
//             sum = 0;
//             bool isDup = false;
//             for(int j=i ; j<i+k-1 ; j++){
//                 if(st.count(nums[j])){
//                     isDup = true;
//                     break;
//                 }
//                 st.insert(nums[j]);
//                 sum += nums[j];
//             }
//             if(!isDup){
//                 maxSum = max(sum,maxSum);
//             }
//         }
//         return maxSum;
//     }
// };