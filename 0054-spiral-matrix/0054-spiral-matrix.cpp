class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total=row*col;
        int minr=0;
        int maxr=row-1;
        int minc=0;
        int maxc=col-1;
        while(count<total){
            for(int i=minc ; i<=maxc && count<total ; i++){
                ans.push_back(matrix[minr][i]);
                count++;
            }
            minr++;
            for(int i=minr ; i<=maxr && count<total ; i++){
                ans.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            for(int i=maxc ; i>=minc && count<total ; i--){
                ans.push_back(matrix[maxr][i]);
                count++;
            }
            maxr--;
            for(int i=maxr ; i>=minr && count<total ; i--){
                ans.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return ans;
    }
};