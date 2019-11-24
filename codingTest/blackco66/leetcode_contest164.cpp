#include <bits/stdc++.h>
using namespace std;
int distance(vector<int> a, vector<int> b) {
    int aa = a[0] - b[0] > 0 ? a[0] - b[0] : b[0] - a[0];
    int bb = a[1] - b[1] > 0 ? a[1] - b[1] : b[1] - a[1];
    return aa > bb ? aa : bb;
}
vector<string> suggest(vector<string>& products, string searchWord) {
    vector<string> common;
    int n = searchWord.size();
    for (int i = 0; i < products.size(); i++) {
        if (products[i].substr(0, n).compare(searchWord) == 0) {
            common.push_back(products[i]);
        }
    }
    sort(common.begin(), common.end());
    vector<string> res;
    int num = common.size() > 3 ? 3 : common.size();
    for (int i = 0; i < num; i++) {
        res.push_back(common[i]);
    }
    return res;
}
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            ans += distance(points[i], points[i + 1]);
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowsum(grid.size(), 0);
        vector<int> colsum(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                rowsum[i] += grid[i][j];
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                colsum[i] += grid[j][i];
            }
        }
        vector<vector<int>> revised(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            if (rowsum[i] > 1) {
                revised[i] = grid[i];
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            if (colsum[i] > 1) {
                for (int j = 0; j < grid.size(); j++) {
                    if (grid[j][i] == 1) {
                        revised[j][i] = 1;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < revised.size(); i++) {
            for (int j = 0; j < revised[0].size(); j++) {
                sum += revised[i][j];
            }
        }
        return sum;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++) {
            ans.push_back(suggest(products, searchWord.substr(0, i + 1)));
        }
        return ans;
    }
    int numWays(int steps, int arrLen) {
        int num[501][502];
        num[0][0] = 1;
        const int MOD = 1000000007;
        int min = steps > arrLen - 1 ? arrLen - 1 : steps;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= min; j++) {
                num[i][j] = num[i - 1][j];
                if (j == 0 && arrLen > 1)
                    num[i][j] = (num[i][j] + num[i - 1][j + 1]) % MOD;
                else if (j == arrLen - 1 && arrLen > 1)
                    num[i][j] = (num[i][j] + num[i - 1][j - 1]) % MOD;
                else if (arrLen > 2)
                    num[i][j] = ((num[i - 1][j - 1] + num[i - 1][j + 1]) % MOD + num[i][j]) % MOD;
            }
        }
        return num[steps][0];
    }
};
int main() {
    vector<int> aa{1, 1, 2, 1, 1};
    string a1 = "xxyyxyxyxx";
    string a2 = "xyyxyxxxyx";
    Solution aaaa;
    cout << find(7);
}