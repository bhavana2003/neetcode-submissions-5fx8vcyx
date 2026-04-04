class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        vector<int> res;
        deque<int> d;
        for(int i = 0; i < n; i++){
            // Removing from left as window slides
            while(d.size() && d.front() < l){
                d.pop_front();
            }
            // Removing all indices whose values are less tha current element
            while (d.size() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }
            // push current element
            d.push_back(i);
            if(i >= k - 1){
                // leftmost will have max value of window
                res.push_back(nums[d.front()]);
                l++;
            }
        }
        return res;
    }
};
