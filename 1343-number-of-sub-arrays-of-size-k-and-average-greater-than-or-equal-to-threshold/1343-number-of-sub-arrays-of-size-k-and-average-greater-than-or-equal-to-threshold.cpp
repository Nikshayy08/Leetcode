class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int i=0;
        int avg=0;
        int sum = 0;
        while(i<k){
            sum += arr[i];
            i++;
        }
        avg = sum/k;
        if(avg>=threshold){
            count++;
        }
        while(i<arr.size()){
            int add = arr[i];
            int remove = arr[i-k];
            sum += add;
            sum -= remove;
            avg = sum/k;
            if(avg>=threshold){
                count++;
            }  
            i++;
        }
        return count;
    }
};