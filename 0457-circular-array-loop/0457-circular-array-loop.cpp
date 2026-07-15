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
        for(int i = 0; i < nums.size(); i++){

            // If already processed, skip it.
            if(nums[i] == 0) continue;

            // take a map to store weather the index is visited twice or not if yes , then there must be a cycle.
            // a flag to track first index that we start so that each should be in same direction -> isPos = nums[i]>0
            unordered_set<int> st;
            st.insert(i);

            bool isPos = nums[i] > 0;
            int cur = i;

            // cycle detection ->
            while(true){

                int next = calculateNextIndx(nums, cur);

                // self loop is not allowed
                if(next == cur){
                    break;
                }

                if(isPos){
                    if(nums[next] <= 0){
                        // direction changed or already processed
                        break;
                    }
                    else{
                        // now check weather the cycle exist or not
                        if(st.count(next)){
                            return true;
                        }

                        st.insert(next);
                    }
                }
                else{
                    if(nums[next] >= 0){
                        // direction changed or already processed
                        break;
                    }
                    else{
                        // now check weather the cycle exist or not
                        if(st.count(next)){
                            return true;
                        }

                        st.insert(next);
                    }
                }

                cur = next;
            }

            // No valid cycle found.
            // Traverse the same path again and mark every visited element as 0.
            cur = i;

            while(true){

                if(nums[cur] == 0) break;

                if(isPos && nums[cur] < 0) break;
                if(!isPos && nums[cur] > 0) break;

                int next = calculateNextIndx(nums, cur);

                nums[cur] = 0;

                if(next == cur) break;

                cur = next;
            }
        }

        return false;
    }
};