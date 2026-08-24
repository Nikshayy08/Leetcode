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