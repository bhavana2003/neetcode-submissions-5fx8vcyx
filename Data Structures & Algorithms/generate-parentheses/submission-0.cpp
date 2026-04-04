class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string temp = "";
        backtrack(temp, 0, 0, n);
        return ans;
    }

    void backtrack(string &temp, int left, int right, int n){
        if (temp.length() == 2*n && left == n && right == n){
            ans.push_back(temp);
            return;
        }

        if (left < n){
            temp += '(';
            backtrack(temp, left+1, right, n);
            temp.pop_back();
        }

        if (left > right){
            temp += ')';
            backtrack(temp, left, right+1, n);
            temp.pop_back();   
        }     
    }
};
