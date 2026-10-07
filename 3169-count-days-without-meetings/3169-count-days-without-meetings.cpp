class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());                                  

        int maxEnd = meetings[0][1]; // what is the maximum end time we got so far
        int gap = 0; // tracks if some days are missing in the intervals

        for(int i=1 ; i<meetings.size() ; i++){

            if(meetings[i][0]>maxEnd){
                gap += meetings[i][0] - maxEnd - 1;   
            }
            // [2,9][11,12] , maxEnd = 9 , meetings[i][0] = 11 which is greater than maxEnd
            //         i
            // so, overlap not possible and gap exist
            // gap = 11-9-1 = 1  cuz 10 is the only day thats free so we did --> gap += meetings[i][0] - maxEnd - 1; 

            maxEnd = max(maxEnd,meetings[i][1]);  
        }
        // maybe the working days not started with day 1
        gap += meetings[0][0] - 1;

        return days - maxEnd + gap;
        
    }
};






















// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         sort(meetings.begin(),meetings.end());
//         vector<vector<int>> merged;
//         for(int i=0 ; i<meetings.size() ; i++){
//             if(merged.empty() || merged.back()[1]<meetings[i][0]){
//                 merged.push_back(meetings[i]);
//             }
//             else{
//                 merged.back()[1] = max(merged.back()[1],meetings[i][1]);
//             }
//         }
//         int meetingDays = 0;
//         for(int i=0 ; i<merged.size() ; i++){
//             meetingDays += merged[i][1] - merged[i][0] +1;
//         }
//         return days - meetingDays;
//     }
// };


