class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> mp; // char, index+1
        int maxLength = 0;
        int l = 0, r = 1;
        if(s.length()>0){
            mp[s[0]] = 1;
            maxLength = 1;
        }

        while (l<r && r<s.length()){
            if(mp[s[r]]){
                int i = mp[s[r]];
                while (l < i){
                    mp[s[l++]] = 0;
                }
            }
            maxLength = max(maxLength, r-l+1);
            mp[s[r]] = r+1;
            r++;
        }

        return maxLength;
    }
};
