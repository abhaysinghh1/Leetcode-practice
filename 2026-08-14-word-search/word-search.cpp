class Solution {
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        // Base case: all characters matched
        if (idx == word.size())
            return true;

        // Boundary check and character match check
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        // Mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 adjacent cells for the next character
        for (auto& it : directions) {
            int i_ = i + it[0];
            int j_ = j + it[1];
            if (find(board, i_, j_, idx + 1, word)) {
                board[i][j] = temp;
                return true;
            }
        }

        // Backtrack: restore original character
        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the first character matches, begin DFS from (i, j)
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};