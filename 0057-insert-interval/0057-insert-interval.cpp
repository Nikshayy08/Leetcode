class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // find insert position , tilll not found, insert rest of intervals into result --> done
        // while overlapping ,update newInterval
        // if no overlapping , insert newInterval into result
        // insert remaining intervals into result

        vector<vector<int>> result;
        if(intervals.empty()){
            result.push_back({newInterval[0],newInterval[1]});
            return result;
        }
        int i=0;
        int flag = 0;

        while(i<intervals.size()){
            if(flag==1){
                result.push_back(intervals[i]);
                i++;
            }
            else if(newInterval[0]>intervals[i][1]){
                result.push_back(intervals[i]);
                i++;
            }
            else{
                if(intervals[i][0]>newInterval[1]){
                    result.push_back(newInterval);
                    flag = 1;
                }
                else{
                    while(i<intervals.size() && intervals[i][1]>=newInterval[0] && newInterval[1]>=intervals[i][0]){
                        newInterval[0] = min(newInterval[0],intervals[i][0]);
                        newInterval[1] = max(newInterval[1],intervals[i][1]);
                        i++;
                    }
                    result.push_back(newInterval);
                    flag = 1;
                }
            }
        }
        if(flag==0){
        result.push_back(newInterval);
    }
        return result;





        // int i = 0;
        // vector<vector<int>> result;

        // while(i<intervals.size() && newInterval[0]>intervals[i][1]){
        //     result.push_back(intervals[i]);
        //     i++;
        // }

        // // correct position found

        // while(i<intervals.size() && intervals[i][1]>=newInterval[0] && newInterval[1]>=intervals[i][0]){
        //     // update new interval
        //     newInterval[0] = min(newInterval[0],intervals[i][0]);
        //     newIntervals[1] = max(newInterval[1],intervals[i][1]);
        //     i++;
        // }

        // result.push_back(newInterval);

        // // insert remaining intervals now
        // while(i<intervals.length()){
        //     result.push_back(intervals[i]);
        //     i++;
        // }

        // return result;
    }
};