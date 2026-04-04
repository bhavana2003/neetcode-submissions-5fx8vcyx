class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp; // <char, count>
        int maxFreq = 0;
        int maxLength = 0;
        int l = 0, r = 0;

        while(r<s.length()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int windowSize = r-l+1;
            if (windowSize > k + maxFreq){
                mp[s[l]]--;
                l++;
            }
            else{
                maxLength = max(maxLength, windowSize);
            }
            r++;
        }

        return maxLength;
    }
};
