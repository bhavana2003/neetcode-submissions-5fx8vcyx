class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0, right = 1;
        int maxProfit = 0;

        while (left < right && right < n){
            if (prices[left] > prices[right]){
                left++;
                right = left+1;
            }
            else{
                maxProfit = max(maxProfit, prices[right] - prices[left]);
                right++;
            }
        }

        return maxProfit;
    }
};
