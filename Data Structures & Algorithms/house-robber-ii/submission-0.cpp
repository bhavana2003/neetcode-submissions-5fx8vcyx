class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(linearRob(vector<int>(nums.begin() + 1, nums.end())),linearRob(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int linearRob(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i=2; i<=n; i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};
