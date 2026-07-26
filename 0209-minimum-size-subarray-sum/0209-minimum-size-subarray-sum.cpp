class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int length = INT_MAX;

        while(j<nums.size()){
            
            sum+= nums[j];

            while(sum>=target){
                length = min(length,j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        if(length==INT_MAX) return 0;
        return length;
    }
};



















// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {

//         int i = 0;
//         int j = 0;
//         int sum = 0;
//         int length = INT_MAX;

//         while(j < nums.size()){

//             // expand window by adding nums[j]
//             sum += nums[j];

//             // shrink window while sum >= target
//             while(sum >= target){
//                 length = min(length, j - i + 1);
//                 sum -= nums[i];
//                 i++;
//             }

//             j++;
//         }

//         return (length == INT_MAX ? 0 : length);
//     }
// };