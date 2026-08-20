class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 0;
        sort(nums.begin(), nums.end());

        long long sum = 0; // sum of processed elements

        int i=0;
        int j=0;  // dynamic size sliding window (two variables needed)   

        while(j<nums.size()){
            sum += nums[j];  //add the new element entering window

            long long total = (long long)(j-i+1)*nums[j];   // helps in calculating x

            long long x = total - sum;      //total oprations needed to make elements similar

            while(x>k){
                // reduce the size of the window
                sum -= nums[i];  //  remove leftmost element
                i+=1;
                total = (long long)(j-i+1)*nums[j];
                x = total - sum;
            }

            maxFreq = max(maxFreq,j-i+1);
            j+=1;
        }  
        return maxFreq; 
    }
};