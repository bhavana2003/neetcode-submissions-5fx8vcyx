class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n), rightMin(n);
        stack<int> st; // indices

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if (st.empty()){
                leftMin[i] = 0;
            }
            else{
                leftMin[i] = st.top()+1;
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if (st.empty()){
                rightMin[i] = n-1;
            }
            else{
                rightMin[i] = st.top()-1;
            }
            st.push(i);
        }

        int maxArea = INT_MIN;
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, (rightMin[i] - leftMin[i] + 1)*heights[i]);
        }

        return maxArea;
    }
};
