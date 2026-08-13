class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Number of rows (and columns, since matrix is square)

        // Step 1: Transpose the matrix
        // Convert rows into columns by swapping matrix[i][j] with matrix[j][i]
        for (int row = 0; row < n; row++) {
            for (int col = row; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row
        // This completes the 90-degree clockwise rotation
        for (int row = 0; row < n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};
