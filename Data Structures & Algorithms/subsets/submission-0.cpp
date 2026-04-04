class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int> &temp, int i){
        if (i == nums.size()){
            ans.push_back(temp);
            return;
        }

        // Consider case
        temp.push_back(nums[i]);
        backtrack(nums, temp, i+1);
        temp.pop_back();

        // Not Consider case
        backtrack(nums, temp, i+1);
    }
};
