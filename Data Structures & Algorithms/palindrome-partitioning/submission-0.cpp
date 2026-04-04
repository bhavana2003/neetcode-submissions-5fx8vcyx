class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(temp, s, 0);
        return ans;
    }

    void backtrack(vector<string> &temp, string s, int index){
        if (index == s.length()){
            ans.push_back(temp);
            return;
        }

        for (int i=index; i<s.length(); i++){
            if (isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                backtrack(temp, s, i+1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r){
        while (l<=r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
};
