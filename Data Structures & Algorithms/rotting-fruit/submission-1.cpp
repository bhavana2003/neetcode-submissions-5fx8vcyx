class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> q; // {i,j}
        
        vector <pair<int,int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while (fresh > 0 && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < grid.size() &&
                        col >= 0 && col < grid[0].size() &&
                        grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
