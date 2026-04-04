class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, nums, target, 0, 0);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> nums, int target, int currSum, int i){
        if (i >= nums.size() || currSum >= target){
            if (currSum == target){
                ans.push_back(temp);
            }
            return;
        }

        // Consider nums[i] in combination
        temp.push_back(nums[i]);
        backtrack(ans, temp, nums, target, currSum+nums[i], i);
        temp.pop_back();

        // Not Consider nums[i] in combination
        backtrack(ans, temp, nums, target, currSum, i+1);
    }
};
