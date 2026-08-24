// class Solution {
// public:
//     int characterReplacement(string s, int k) {
        
//         int maxFreq = 0;  
        
//         for(int i=0 ; i<s.length() ; i++){

//             int maxCh = 0;  frequency of the maximum occuring ch in substr
//             int chFreq[26] = {0}; array to maintain freq of each uppercase ch inside str

//             for(int j=i ; j<s.length() ; j++){

//                 chFreq[s[j] - 'A']++;   increment freq of current ch and store in array

//                 maxCh = max(maxCh , chFreq[s[j] - 'A']); update maxch with max value inside the substr

//                 int ops = (j-i+1) - maxCh;  no of oprn required ti make elements similar inside substr
//                 if(ops>k){
//                     break;
//                 }
                
//                 maxFreq = max(maxFreq,j-i+1); update answer
//             }
//         }

//         return maxFreq;
//     }
// };


//  NO here is the optimized dynamic sliding window solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxFreq = 0;
        int i = 0;
        int j = 0;

        int maxCh = 0;
        int chFreq[26] = {0};
        
        while(j<s.length()){

            chFreq[s[j] - 'A']++;

            maxCh = max(maxCh , chFreq[s[j] - 'A']);

            int ops = (j-i+1) - maxCh;

            while(ops>k){
                chFreq[s[i] - 'A']--;
                i+=1;
                maxCh = max(maxCh , chFreq[s[j] - 'A']);
                ops = (j-i+1) - maxCh;
            }

            maxFreq = max(maxFreq,j-i+1);
            j+=1;
        }

        return maxFreq;
    }
};