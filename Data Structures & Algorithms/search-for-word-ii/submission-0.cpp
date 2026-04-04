class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};
class Solution {
public:
    int ROWS, COLS;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();

        TrieNode* root = new TrieNode();

        for (string &word : words)
            addWord(root, word);

        vector<string> ans;
        string temp = "";

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(ans, temp, r, c, board, root);
            }
        }
        return ans;
    }

    void dfs(vector<string> &ans, string &temp, int r, int c,
         vector<vector<char>>& board, TrieNode* node) {

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] == '#')
            return;

        char ch = board[r][c];
        TrieNode* nextNode = node->children[ch - 'a'];

        if (!nextNode) return;  // prune immediately

        temp.push_back(ch);

        if (nextNode->word) {
            ans.push_back(temp);
            nextNode->word = false;   // avoid duplicates
        }

        board[r][c] = '#';

        dfs(ans, temp, r + 1, c, board, nextNode);
        dfs(ans, temp, r - 1, c, board, nextNode);
        dfs(ans, temp, r, c + 1, board, nextNode);
        dfs(ans, temp, r, c - 1, board, nextNode);

        board[r][c] = ch;
        temp.pop_back();
    }

    void addWord(TrieNode* root, string word){
        TrieNode* curr = root;
        for (char c:word){
            if (curr->children[c-'a'] == NULL){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->word = true;
    }
};
