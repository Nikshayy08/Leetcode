class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> merged;
        for(int i=0 ; i<meetings.size() ; i++){
            if(merged.empty() || merged.back()[1]<meetings[i][0]){
                merged.push_back(meetings[i]);
            }
            else{
                merged.back()[1] = max(merged.back()[1],meetings[i][1]);
            }
        }
        int meetingDays = 0;
        for(int i=0 ; i<merged.size() ; i++){
            meetingDays += merged[i][1] - merged[i][0] +1;
        }
        return days - meetingDays;
    }
};