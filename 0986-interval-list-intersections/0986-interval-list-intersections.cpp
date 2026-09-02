// class Solution {
// public:
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

//         // If any list is empty → no intersections possible
//         if(firstList.empty() || secondList.empty()){
//             return {};
//         }

//         vector<vector<int>> answer;

//         // Brute force: compare every interval in firstList with every interval in secondList
//         for(auto interval1 : firstList){
//             for(auto interval2 : secondList){

//                 // Overlap condition:
//                 // interval1 = [a1, a2], interval2 = [b1, b2]
//                 // They overlap only if: a1 <= b2 AND b1 <= a2
//                 if(interval2[0] <= interval1[1] && interval1[0] <= interval2[1]){

//                     // Intersection start = max of both starts
//                     // Intersection end   = min of both ends
//                     int first = max(interval1[0], interval2[0]);
//                     int second = min(interval1[1], interval2[1]);

//                     // Valid intersection only if start <= end
//                     if(first <= second)
//                         answer.push_back({first, second});
//                 }
//             }
//         }

//         return answer;
//     }
// };






class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int i=0;
        int j=0;
        while(i<firstList.size() && j<secondList.size()){
            if(secondList[j][0]<=firstList[i][1] && firstList[i][0]<=secondList[j][1])
            {
                int start = max(firstList[i][0],secondList[j][0]);
                int end = min(firstList[i][1],secondList[j][1]);
                if(start<=end){
                    answer.push_back({start,end});
                }
            }
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }
            else j++;
        }
        return answer;
    }
};
