class Solution {
    vector<int> delrow = {-1, 1, 0, 0};
    vector<int> delcol = {0, 0, -1, 1};
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& land, vector<vector<int>>& vis, int &maxr, int &maxc) {
        // ye & ki vajah se  value bahar tak retain rehti hai
        vis[r][c] = 1;
        maxr = max(maxr, r);
        maxc = max(maxc, c);

        for (int k = 0; k < 4; k++) {
            int nrow = r + delrow[k];
            int ncol = c + delcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && land[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, land, vis, maxr, maxc);
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    int maxr = i;
                    int maxc = j;
                    dfs(i, j, land, vis, maxr, maxc);
                    ans.push_back({i, j, maxr, maxc});
                }
            }
        }

        return ans;
    }
};