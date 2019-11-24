#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class FindElements {
public:
    TreeNode* rt;
    FindElements(TreeNode* root) {
        if (root == NULL) {
            rt = NULL;
            return;
        }
        this->rt = new TreeNode(0);
        this->rt->left = make_left(this->rt, root->left);
        this->rt->right = make_right(this->rt, root->right);
    }
    TreeNode* make_left(TreeNode* parent, TreeNode* ref) {
        if (ref == NULL) {
            return NULL;
        }
        TreeNode* result = new TreeNode(parent->val * 2 + 1);
        result->left = make_left(result, ref->left);
        result->right = make_right(result, ref->right);
        return result;
    }
    TreeNode* make_right(TreeNode* parent, TreeNode* ref) {
        if (ref == NULL) {
            return NULL;
        }
        TreeNode* result = new TreeNode(parent->val * 2 + 2);
        result->left = make_left(result, ref->left);
        result->right = make_right(result, ref->right);
        return result;
    }
    bool find(int target) {
        int lev = -1;
        int shift = 1;
        for (int i = 0; i < 20; i++) {
            if ((target + 1) / shift > 0) {
                shift *= 2;
                continue;
            }
            lev = i;
            break;
        }
        int col = target + 1 - (1 << (lev - 1));

        bool res = findef(col, this->rt, lev);
        return res;
    }
    bool findef(int col, TreeNode* parent, int lev) {
        if (parent == NULL) return false;
        if (lev == 1) {
            if (parent == NULL)
                return false;
            else
                return true;
        }

        bool res;
        if (col < 1 << (lev - 2)) {
            res = findef(col % (1 << (lev - 2)), parent->left, lev - 1);
        } else {
            res = findef(col % (1 << (lev - 2)), parent->right, lev - 1);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> tmpgrid(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmpgrid[m * i + j] = grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = tmpgrid[(m * i + j - k + k * n * m) % (n * m)];
            }
        }
        return grid;
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<int> one;
        vector<int> oone;
        int maxsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            maxsum += tmp;
            if (tmp % 3 == 1)
                one.push_back(tmp);
            else if (tmp % 3 == 2)
                oone.push_back(tmp);
        }
        sort(one.begin(), one.end());
        sort(oone.begin(), oone.end());
        int o = one.size();
        int oo = oone.size();
        int n = o > oo ? o - oo : oo - o;
        if (n % 3 == 1) {
            if (o > oo) {
                if (o < 3 || oo < 2 || one[0] < oone[0] + oone[1]) {
                    maxsum -= one[0];
                } else {
                    maxsum -= oone[0] + oone[1];
                }
            } else {
                if (oo < 3 || o < 2 || oone[0] < one[0] + one[1]) {
                    maxsum -= oone[0];
                } else {
                    maxsum -= one[0] + one[1];
                }
            }
        } else if (n % 3 == 2) {
            if (o > oo) {
                if (o < 3 || oo < 1 || one[0] + one[1] < oone[0]) {
                    maxsum -= one[0] + one[1];
                } else {
                    maxsum -= oone[0];
                }
            } else {
                if (oo < 3 || o < 1 || oone[0] + oone[1] < one[0]) {
                    maxsum -= oone[0] + oone[1];
                } else {
                    maxsum -= one[0];
                }
            }
        }
        return maxsum;
    }
};

int main() {
    vector<int> aa{1, 1, 2, 1, 1};
    string a1 = "xxyyxyxyxx";
    string a2 = "xyyxyxxxyx";
    Solution aaaa;
    cout << find(7);
}