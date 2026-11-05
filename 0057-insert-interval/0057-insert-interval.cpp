class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // find insert position , tilll not found, insert rest of intervals into result --> done
        // while overlapping ,update newInterval
        // if no overlapping , insert newInterval into result
        // insert remaining intervals into result

        vector<vector<int>> answer;
        int i=0;
        bool inserted = false;
        while(i<intervals.size()){

            if(newInterval[0]>intervals[i][1]){
                answer.push_back(intervals[i]);
            }
            else{
                if(newInterval[1]<intervals[i][0]){
                    answer.push_back({newInterval[0],newInterval[1]});
                    inserted = true;
                    break;
                }
                else{
                    newInterval[0] = min(newInterval[0],intervals[i][0]);
                    newInterval[1] = max(newInterval[1],intervals[i][1]);
                }
            }
            i++;
        }
        if(!inserted){
            answer.push_back(newInterval);
        }
        while(i<intervals.size()){
            answer.push_back(intervals[i]);
            i++;
        }
        return answer;
    }
};






















// int i = 0;
//         vector<vector<int>> result;

//         while(i<intervals.size() && newInterval[0]>intervals[i][1]){
//             result.push_back(intervals[i]);
//             i++;
//         }

//         // correct position found

//         while(i<intervals.size() && intervals[i][1]>=newInterval[0] && newInterval[1]>=intervals[i][0]){
//             // update new interval
//             newInterval[0] = min(newInterval[0],intervals[i][0]);
//             newInterval[1] = max(newInterval[1],intervals[i][1]);
//             i++;
//         }

//         result.push_back(newInterval);

//         // insert remaining intervals now
//         while(i<intervals.size()){
//             result.push_back(intervals[i]);
//             i++;
//         }

//         return result;


