class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        int k=j;
        vector<int> ans(nums.size());
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[k--] = nums[i]*nums[i];
                i++;
            }
            else{
                ans[k--] = nums[j]*nums[j];
                j--;
            }
        }
        return ans;
    }
};




// vector<int> answer;
    //     // //  take two ptr from first and last.
    //     // int i=0,j=nums.size()-1;
    //     // // compare each element and push the square of larger element into answer
    //     // while(i<=j){
    //     //     if(abs(nums[i])>abs(nums[j])){
    //     //         answer.push_back(nums[i]*nums[i]);
    //     //         i++;
    //     //     }
    //     //     else{
    //     //         answer.push_back(nums[j]*nums[j]);
    //     //         j--;
    //     //     }
    //     // }
    //     // // now we have answer in reverse order so well reverse the array and get correct answer
    //     // i=0,j=nums.size()-1;
    //     // while(i<j){
    //     //     swap(answer[i],answer[j]);
    //     //     i++;
    //     //     j--;
    //     // }
    //     // return answer;


    //     // another one(efficient) is to take third pointer to keep track of answer array and fill it from last to first.
    //     vector<int>ans(nums.size());
    //     int i=0,j=nums.size()-1;
    //     int k=nums.size()-1;
    //     while(i<=j){
    //         if(abs(nums[i])>abs(nums[j])){
    //             ans[k] = nums[i]*nums[i];
    //             i++;
    //         }
    //         else{
    //             ans[k] = nums[j]*nums[j];
    //             j--;
    //         }
    //         k--;
    //     }
    //     return ans;
    // }