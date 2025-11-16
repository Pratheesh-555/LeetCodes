class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool dfs(int i, int j, int idx, vector<vector<char>> &board, vector<vector<int>> &vis, string word){
        if(board[i][j] != word[idx]) return false;
        if(idx == word.size()-1) return true;
        vis[i][j] = 1;
        
        int m = board.size();
        int n = board[0].size();

        for(auto &it : dir){
            int nr = i + it[0];
            int nc = j + it[1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
                if(dfs(nr, nc, idx+1, board, vis, word))
                    return true;
                else
                    vis[nr][nc] = 0;
            }
        }
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, 0, board, vis, word)) return true;
                }
            }
        }
        return false;
    }
};