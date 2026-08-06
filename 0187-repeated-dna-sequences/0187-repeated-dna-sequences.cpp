class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // RABIN KARP ALGO
        if(s.length()<10){
            return {};
        }

        int k = 10;

        // Mapping each reppeatitive ch
        unordered_map<char,int> mp;
        mp['A'] = 0;
        mp['C'] = 1;
        mp['G'] = 2;
        mp['T'] = 3;


        unordered_set<int> seen; // to store all the integer hash values
        unordered_set<string> result; // to store all the answers

        int hash = 0;

        // Calculate the hash of the first window.

        for(int i=0 ; i<k ; i++){
            int power = k-i-1;
            hash += pow(4,power) * mp[s[i]];
        }

        seen.insert(hash); // insert first window hash into the set

        for(int i=k ; i<s.length() ; i++){
            // Remove leftmost character
            hash -= pow(4, k - 1) * mp[s[i - k]];

            // Shift remaining characters
            hash *= 4;

            // Add new character
            hash += mp[s[i]];

            if(seen.count(hash)){
                result.insert(s.substr(i-k+1,k));
            }

            seen.insert(hash);
        }

        return vector<string>(result.begin(),result.end());
    }
};