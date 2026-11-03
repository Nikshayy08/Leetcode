class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // first element will alws be unique so start i from 1
        int i=1;
        for(int j=1 ; j<nums.size() ; j++){
            if(nums[j]!=nums[j-1]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};









    // // we'll start form index 1 cuz we know one single element at indx 0 is single so it can't be duplicate
    //     int i = 1; 
    //     for(int j=1 ; j<nums.size() ; j++){
    //         if(nums[j-1]!=nums[j]){
    //             nums[i] = nums[j];
    //             i++;
    //         }
    //     }
    //     return i;
    // }