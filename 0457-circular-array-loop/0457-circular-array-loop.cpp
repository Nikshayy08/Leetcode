class Solution {
public:
    int calculateNextIndx(vector<int>& nums, int cur){
        int n = nums.size();
        int nextPos = ((cur + nums[cur]) % n + n) % n;
        return nextPos;
    }

    bool circularArrayLoop(vector<int>& nums) {
        // 1. There should be cycle.
        // 2. all elements should follow same direction in cycle either positive or either negative.
        // 3. The length of the cycle must be greater than 1.

        // A loop to check for each index whether there is cycle or not
        for(int i = 0; i < nums.size(); i++){

            unordered_set<int> st;
            st.insert(i);

            bool isPos = nums[i] > 0;
            int cur = i;

            while(true){

                int next = calculateNextIndx(nums, cur);

                if(isPos){
                    if(nums[next] < 0){
                        // direction changed
                        break;
                    }
                    else{
                        // self loop is not allowed
                        if(next == cur){
                            break;
                        }

                        if(st.count(next)){
                            return true;
                        }

                        st.insert(next);
                    }
                }
                else{
                    if(nums[next] > 0){
                        // direction changed
                        break;
                    }
                    else{
                        // self loop is not allowed
                        if(next == cur){
                            break;
                        }

                        if(st.count(next)){
                            return true;
                        }

                        st.insert(next);
                    }
                }

                cur = next;
            }
        }

        return false;
    }
};