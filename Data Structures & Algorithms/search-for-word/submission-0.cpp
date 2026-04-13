class Solution {
public:
    bool dfs(int i, int j, string &word, int wordptr, vector<vector<char>> &board) {
        if (wordptr == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[wordptr]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(i+1, j, word, wordptr+1, board) ||
                     dfs(i-1, j, word, wordptr+1, board) ||
                     dfs(i, j+1, word, wordptr+1, board) ||
                     dfs(i, j-1, word, wordptr+1, board);

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, word, 0, board)) return true;
                }
            }
        }
        return false;
    }
};