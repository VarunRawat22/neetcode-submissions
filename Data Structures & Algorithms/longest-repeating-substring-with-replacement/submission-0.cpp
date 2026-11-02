class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int n=s.size();
        int l=0;
        int r=0;
        int maxFreq=0;
        int maxLen=0;
        while(r<n){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq, freq[s[r]-'A']);

            if((r-l+1)-maxFreq >k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;

        }
        return maxLen;
    }
};
