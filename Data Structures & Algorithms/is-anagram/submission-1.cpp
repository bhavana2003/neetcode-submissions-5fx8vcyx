class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())   return false;

        unordered_map <char, int> mp;
        for (char c:s){
            mp[c]++;
        }

        for(char c:t){
            if (mp[c]){
                mp[c]--;
            }
            else return false;
        }

        return true;
    }
};
