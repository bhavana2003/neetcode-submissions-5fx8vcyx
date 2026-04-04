class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        for(int i=0; i<=word1.size(); i++){
            dp[i][0] = i;
        }

        for(int j=0; j<=word2.size(); j++){
            dp[0][j] = j;
        }

        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.length(); j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = dp[i][j-1]; // i+1 is inserted
                    int replace = dp[i-1][j-1];
                    int del = dp[i-1][j]; // i is deleted
                    dp[i][j] = 1 + min(insert, min(replace, del));
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
