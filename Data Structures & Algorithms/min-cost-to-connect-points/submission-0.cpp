class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n,0);
        int sum = 0;

        // {cost, index}
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            int cost = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            if (visited[i]) continue;
            visited[i] = 1;
            sum += cost;

            for (int j=0; j<n; j++){
                if (!visited[j]){
                    int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    pq.push({d, j});
                }
            }
        }

        return sum;
    }
};
