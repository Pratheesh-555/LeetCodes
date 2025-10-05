class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int i, int j, vector<vector<int>> &heights,vector<vector<int>> &vis){
        vis[i][j] = 1;

        for(auto &it : dir){
            int x = i + it[0];
            int y = j + it[1];

            if(x >=0 && x < m && y >= 0 && y < n && !vis[x][y] && heights[i][j] <= heights[x][y]){
                dfs(x,y,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n,0));
        vector<vector<int>> at(m, vector<int>(n,0));

        for(int i =0; i < m; i++) dfs(i,0,heights,pac);
        for(int j =0; j < n; j++) dfs(0,j,heights,pac);

        for(int j =0; j < n; j++) dfs(m-1,j,heights,at);
        for(int i =0; i < m; i++) dfs(i,n-1,heights,at);

        vector<vector<int>> res;

        for(int i=0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && at[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};