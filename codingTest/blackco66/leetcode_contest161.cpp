#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> oddpos;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] % 2 == 1) {
				oddpos.push_back(i);
			}
		}
		if (oddpos.size() < k) return 0;
		int ans = 0;
		if (k == 0) {
			for (int i = 0; i < oddpos.size() + 1; i++) {
				int diff = 0;
				if (i == 0) {
					diff = oddpos[i];
				}
				else if(i == oddpos.size()){
					diff = nums.size() - oddpos[i] - 1;
				}
				else {
					diff = oddpos[i] - oddpos[i - 1] - 1;
				}
				ans += 1 << diff;
			}
			return ans;
		}
		for (int i = 0; i < oddpos.size() - k + 1; i++) {
			int front = oddpos[i];
			int back = oddpos[i + k - 1];
			int tmp = 0;
			if (i == 0) {
				tmp += front + 1;
			}
			else {
				tmp += oddpos[i] - oddpos[i - 1];
			}
			if (i + k - 1 == oddpos.size() - 1) {
				tmp *= n - oddpos[i + k - 1];
			}
			else {
				tmp *= oddpos[i + k] - oddpos[i + k - 1];
			}
			ans += tmp;
		}
		return ans;
	}
	int minimumSwap(string s1, string s2) {
		int xnum = 0;
		int ynum = 0;
		int xy = 0;
		int yx = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == 'x')xnum++;
			else ynum++;
			if (s2[i] == 'x')xnum++;
			else ynum++;
			if(s1[i] != s2[i]){
				if(s1[i] == 'x') xy++;
				else yx++;
			}
		}
		if (xnum % 2 == 1 || ynum % 2 == 1) return -1;
		int ans = 0;
		ans += xy / 2;
		ans += yx / 2;
		ans += (xy % 2 + yx % 2);
		return ans;
    }
	string minRemoveToMakeValid(string s) {
		stack<int> par;
		vector<int> tmp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')continue;
			if (s[i] == '(') {
				par.push(i);
			}
			else {
				if (par.size() == 0)tmp.push_back(i);
				else par.pop();
			}
		}
		int n = par.size();
		for (int i = 0; i < n; i++) {
			tmp.push_back(par.top());
			par.pop();
		}
		string ans;
		for (int i = 0; i < tmp.size(); i++) {
			s[tmp[i]] = '.';
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			ans += s[i];
		}
		return ans;
    }
	int gcd_minus(int a, int b) {
		while (b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	bool isGoodArray(vector<int>& nums) {
		int gcd = nums[0];
		if (gcd == 1)return true;
		for (int i = 1; i < nums.size(); i++) {
			gcd = gcd_minus(gcd, nums[i]);
			if (gcd == 1)return true;
		}
		return false;
    }
};

int main() {
	vector<int> aa{ 1,1,2,1,1 };
	string a1 = "xxyyxyxyxx";
	string a2 = "xyyxyxxxyx";
	Solution aaaa;
	cout << aaaa.minimumSwap(a1, a2);
}