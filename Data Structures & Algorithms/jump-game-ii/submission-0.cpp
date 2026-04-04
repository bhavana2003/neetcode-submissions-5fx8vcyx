class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int steps = 0;
        while(r < nums.size()-1){
            int temp = max(nums[r] + r, nums[l] + l);
            l = r +1;
            r = temp;
            steps++;
        }
        return steps;
    }
};
