// class Solution {         BRUTE FORCE
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         bool isMerged = true;
//         while(isMerged){
//             isMerged = false;

//             for(int i=0 ; i<intervals.size() ; i++){
//                 int j = i+1;
//                 while(j<intervals.size()){
//                     if(intervals[i][1]>=intervals[j][0] && intervals[j][1]>=intervals[i][0]){
//                         intervals[i][0] = min(intervals[i][0],intervals[j][0]);
//                         intervals[i][1] = max(intervals[i][1],intervals[j][1]);
//                         intervals.erase(intervals.begin() + j); 
//                         // intervals.begin() → gives you an iterator pointing to the first element of the vector.
//                         // + j → moves that iterator forward by j positions.
//                         isMerged = true;
//                     }
//                     else{
//                         j+=1;
//                     }
//                 }
//             }
//         }
//         return intervals;
//     }
// };



//       OPTIMIZED APPROACH

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(int i=0 ; i<intervals.size() ; i++){
            // check overlap 
            if(merged.empty() || merged.back()[1]<intervals[i][0]){  // if its the first interval || if intervals doesnt overlap
                merged.push_back(intervals[i]);
            }
            else{ // overlap exist
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};