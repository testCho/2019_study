class Solution {
public:
    map<vector<vector<char>>, int> dist;
    bool visited[20][20];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1 ,0};
    int n, m;
    vector<vector<char>> board;
    
    void DFS(int x, int y, vector<vector<char>> &v) {
        visited[x][y] = true;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!visited[nx][ny] && (v[nx][ny] == '.' || v[nx][ny] == 'T')) {
                    DFS(nx, ny, v);
                }
            }
        }
    }
    
    int BFS() {
        
        queue<vector<vector<char>>> q;
        q.push(board);
        while(!q.empty()) {
            vector<vector<char>> cur = q.front();
            int cur_move;
            q.pop();

            int fx, fy;
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < m ; j++) {
                    if (cur[i][j] == 'S') {
                        memset(visited, false, sizeof(visited));
                        DFS(i, j, cur);
                        fx = i;
                        fy = j;
                    }
                }
            }
            vector<pair<int, int>> start_points;
            int i, j;
            for (int ci = 0 ; ci < n ; ci++) {
                for (int cj = 0 ; cj < m ; cj++) {
                    if (cur[ci][cj] == 'B') {
                        i = ci;
                        j = cj;
                        cur_move = dist[cur];
                        for (int k = 0 ; k < 4 ; k++) {
                            int startx = i + dx[k];
                            int starty = j + dy[k];
                            if (0 <= startx && startx < n && 0 <= starty && starty < m) {
                                if (visited[startx][starty] && cur[startx][starty] != 'T') {
                                    start_points.push_back(make_pair(startx, starty));
                                }
                            }
                        }
                    }
                }
            }
            for (int k = 0 ; k < start_points.size() ; k++) {
                vector<vector<char>> temp = cur;
                temp[fx][fy] = '.';
                temp[start_points[k].first][start_points[k].second] = 'S';

                
                 // case1 : person on the left of the box
                if (j-1 >= 0 && temp[i][j-1] == 'S') {
                    if (j+1 < m) {
                        if (temp[i][j+1] == 'T') {
                            return cur_move + 1;
                        }
                        else if (temp[i][j+1] == '.') {
                            vector<vector<char>> next = temp;
                            next[i][j-1] = '.';
                            next[i][j] = 'S';
                            next[i][j+1] = 'B';
                            if (dist[next] == 0) {
                                dist[next] = cur_move + 1;
                                q.push(next);
                            }
                        }
                    }
                }
                // case2 : person on the right of the box
                if (j+1 < m && temp[i][j+1] == 'S') {
                    if (j-1 >= 0) {
                        if (temp[i][j-1] == 'T') {
                            return cur_move + 1;
                        }
                        else if (temp[i][j-1] == '.') {
                            vector<vector<char>> next = temp;
                            next[i][j+1] = '.';
                            next[i][j] = 'S';
                            next[i][j-1] = 'B';
                            if (dist[next] == 0) {
                                dist[next] = cur_move + 1;
                                q.push(next);
                            }
                        }
                    }
                }
                // case3 : person on the top of the box
                if (i-1 >= 0 && temp[i-1][j] == 'S') {
                    if (i+1 < n) {
                        if (temp[i+1][j] == 'T') {
                            return cur_move + 1;
                        }
                        else if (temp[i+1][j] == '.') {
                            vector<vector<char>> next = temp;
                            next[i-1][j] = '.';
                            next[i][j] = 'S';
                            next[i+1][j] = 'B';
                            if (dist[next] == 0) {
                                dist[next] = cur_move + 1;
                                q.push(next);
                            }
                        }
                    }
                }
                // case4 : person on the bottom of the box
                if (i+1 <  n && temp[i+1][j] == 'S') {
                    if (i-1 >= 0) {
                        if (temp[i-1][j] == 'T') {
                            return cur_move + 1;
                        }
                        else if (temp[i-1][j] == '.') {
                            vector<vector<char>> next = temp;
                            next[i+1][j] = '.';
                            next[i][j] = 'S';
                            next[i-1][j] = 'B';
                            if (dist[next] == 0) {
                                dist[next] = cur_move + 1;
                                q.push(next);
                            }
                        }
                    }
                }
            }

        }
        return -1; 
    }
    
    int minPushBox(vector<vector<char>>& grid) {
        board = grid;
        n = grid.size();
        m = grid[0].size();
        int x = BFS();
        return x;
    }
};