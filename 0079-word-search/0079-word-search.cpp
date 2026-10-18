
class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board,
               string word, int idx, int m, int n) {
        
        if (idx == word.size()) {
            return true;
        }

        if (row < 0 || row >= m || col < 0 || col >= n ||
            board[row][col] != word[idx]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '!';

        bool found = solve(row, col-1, board, word, idx+1, m, n) ||
                     solve(row, col+1, board, word, idx+1, m, n) ||
                     solve(row-1, col, board, word, idx+1, m, n) ||
                     solve(row+1, col, board, word, idx+1, m, n);

        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, board, word, 0, m, n)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
