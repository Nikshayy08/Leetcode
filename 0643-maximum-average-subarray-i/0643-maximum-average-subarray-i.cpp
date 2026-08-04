class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        double sum = 0;
        double avg = 0;
        while(i<min(k,int(nums.size()))){
            sum += nums[i];
            i++;
        }
        avg = sum/k;
        while(i<nums.size()){
            int add = nums[i];
            int sub = nums[i-k];
            sum += add;
            sum -= sub;
            avg = max(avg,sum/k);
            i++;
        }
        return avg;
    }
};














        // int i = 0;
        // double avg = 0;
        // double sum = 0;
        // while(i<min(k,int(nums.size()))){
        //     sum += nums[i];
        //     i++;
        // }
        // avg = sum/k;
        // for(i = k ; i<nums.size() ; i++){
        //     double add = nums[i];
        //     double sub = nums[i-k];
        //     sum = sum + add;
        //     sum = sum - sub;
        //     double newAvg = sum/k; 
        //     if(newAvg > avg){
        //         avg = newAvg;
        //     }
        // }
        // return avg;