class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()){
            return {};
        }
        vector<vector<int>> answer;
        for(auto interval1 : firstList){
            for(auto interval2 : secondList){
                if(interval2[0]<=interval1[1] && interval1[0]<=interval2[1]){
                    int first = max(interval1[0],interval2[0]);
                    int second = min(interval1[1],interval2[1]);
                    if(first<=second)
                        answer.push_back({first,second});
                }
            }
        }
        return answer;
    }
};