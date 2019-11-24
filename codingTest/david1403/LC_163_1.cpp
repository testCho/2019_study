class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp;
        for (int i = 0 ; i < m*n ; i++) {
            temp.push_back(grid[i/m][i%m]);
        }
        vector<vector<int>> ret(n, vector<int> (m));
        //printf("%d\n", temp.size());
        for (int i = 0 ; i < k ; i++) {
            int x = temp[n*m-1];
            for (int j = n*m - 1; j > 0 ; j--) {
                temp[j] = temp[j-1];
            }
            temp[0] = x;
        }
        for (int i = 0 ; i < n*m ; i++) {
            ret[i/m][i%m] = temp[i];
        }
        return ret;
    }
};