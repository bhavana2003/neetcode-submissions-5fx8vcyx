class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int l = 0, r = heights.size()-1;

        while(l < r){
            int length = r-l;
            if (heights[l] <= heights[r]){
                maxi = max(heights[l]*length, maxi);
                l++;
            }
            else{
                maxi = max(heights[r]*length, maxi);
                r--;
            }
        }

        return maxi;
    }
};
