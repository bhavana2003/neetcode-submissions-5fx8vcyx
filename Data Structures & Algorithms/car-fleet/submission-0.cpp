class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        stack<double> st;
        for (auto& p : pairs) {
            double time = (double)(target - p.first) / p.second;
            
            if (!st.empty() && time <= st.top())
            {
                // st.pop_back();
            }
            else{
                st.push(time);
            }
        }
        return st.size();
    }
};
