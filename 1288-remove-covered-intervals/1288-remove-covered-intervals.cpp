class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count = 0;
        int maxEnd = 0;
        for(int i=0 ; i<intervals.size() ; i++){
            if(intervals[i][1]>maxEnd){
                count ++;
                maxEnd = intervals[i][1];
            }
        }
        return count;
    }
};




// int count = 0;

//         for(int i=0 ; i<intervals.size() ; i++){

//             int c = intervals[i][0];
//             int d = intervals[i][1];
//             bool isCovered = false;

//             for(int j=0 ; j<intervals.size() ; j++){

//                 int a = intervals[j][0];
//                 int b = intervals[j][1];

//                 if(i!=j && a <= c && d <= b){
//                     isCovered = true;
//                     break;
//                 }
//             }
//             if(!isCovered){
//                 count+=1;
//             }
//         }
//         return count;