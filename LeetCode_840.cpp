// class Solution {
// public:
//     bool isValid(int i, int j, vector<vector<int>>& grid){
//         int sum = 0;
//         int temp = 0;
//         for(int a = i; a < 3; a++){
//             for(int b = j; b < 3; b++){
//                 sum+= grid[a][b];
//             }
//             if(temp!=0) temp = sum;
//             if(temp != sum) return false;
//         }
//         sum = 0;
//         temp = 0;
//         for(int a = j; a < 3; a++){
//             for(int b = i; b < 3; b++){
//                 sum+= grid[a][b];
//             }
//             if(temp!=0) temp = sum;
//             if(temp != sum) return false;
//         }
//         temp = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
//         if(temp != sum) return false;
//         temp = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
//         if(temp != sum) return false;
//         return true;
//     }
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int res = 0;
//         int m = grid.size(); 
//         int n = grid[0].size();

//         for(int i = 0; i < m-2; i++){
//             for(int j = 0; j < n-2; j++){
//                 if(isValid(i,j,grid)) res++;
//             }
//         }
//         return res;
//     }
// };



class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        unordered_set<int> st;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num)) return false;
                st.insert(num);
            }
        }

        for(int i = 0; i < 3; i++) {
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
        }

        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i <= m - 3; i++) {
            for(int j = 0; j <= n - 3; j++) {
                if(isMagicSquare(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};