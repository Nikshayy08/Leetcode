class Solution {
public:
    int calculateNextIndx(vector<int>& nums, int cur){
        int n = nums.size();
        return ((cur + nums[cur]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        // 1. There should be cycle.
        // 2. all elements should follow same direction in cycle either positive or either negative.
        // 3. The length of the cycle must be greater than 1.

        // A loop to check for each index weather there is cycle or not
        for(int i = 0 ; i < nums.size() ; i++){

            // Already processed
            if(nums[i] == 0) continue;

            // a flag to track first index that we start so that each should be in same direction -> isPos = nums[i]>0
            bool isPos = nums[i] > 0;

            int slow = i;
            int fast = i;

            // cycle detection ->
            while(true){

                // move slow by one step
                int nextSlow = calculateNextIndx(nums, slow);

                // direction changed or already processed
                if(nums[nextSlow] == 0 || (nums[nextSlow] > 0) != isPos)
                    break;

                // self loop
                if(nextSlow == slow)
                    break;

                // move fast first step
                int nextFast = calculateNextIndx(nums, fast);

                if(nums[nextFast] == 0 || (nums[nextFast] > 0) != isPos)
                    break;

                if(nextFast == fast)
                    break;

                // move fast second step
                nextFast = calculateNextIndx(nums, nextFast);

                if(nums[nextFast] == 0 || (nums[nextFast] > 0) != isPos)
                    break;

                if(nextFast == calculateNextIndx(nums, nextFast))
                    break;

                slow = nextSlow;
                fast = nextFast;

                if(slow == fast){
                    return true;
                }
            }

            // No valid cycle found.
            // Traverse the same path again and mark every visited element as 0.
            int cur = i;

            while(true){

                if(nums[cur] == 0) break;

                if((nums[cur] > 0) != isPos) break;

                int next = calculateNextIndx(nums, cur);

                nums[cur] = 0;

                if(next == cur) break;

                cur = next;
            }
        }

        return false;
    }
};