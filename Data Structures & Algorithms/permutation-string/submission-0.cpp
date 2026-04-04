class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (k > s2.length()) return false;
        unordered_map <char,int> mp;
        for(auto c:s1){
            mp[c]++;
        }

        int i=0;
        while(i <= (int)s2.length() - k){
            if (mp.find(s2[i]) == mp.end()){
                i++;
                continue;
            }
            unordered_map <char,int> mp2;
            for(int j=0; j<k; j++){
                mp2[s2[i+j]]++;
            }
            if (mp == mp2)   return true;
            i++;
        }
        return false;
    }
};
