class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;

        for(int i=0 ; i<intervals.size() ; i++){

            int c = intervals[i][0];
            int d = intervals[i][1];
            bool isCovered = false;

            for(int j=0 ; j<intervals.size() ; j++){

                int a = intervals[j][0];
                int b = intervals[j][1];

                if(i!=j && a <= c && d <= b){
                    isCovered = true;
                    break;
                }
            }
            if(!isCovered){
                count+=1;
            }
        }
        return count;
    }
};