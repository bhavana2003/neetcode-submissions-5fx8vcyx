class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector <int> isvisited(n, 0);

        for (int i=0; i<n; i++){
            if (!isvisited[i]){
                isvisited[i] = 1;
                vector <string> temp;
                temp.push_back(strs[i]);
                for (int j = i+1; j<n; j++){
                    if (!isvisited[j] && isAnagram(strs[i], strs[j])){
                        temp.push_back(strs[j]);
                        isvisited[j] = 1;
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }

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
