class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> one;
        vector<int> two;
        int ret = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            ret += nums[i];
            if (nums[i] % 3 == 1) {
                one.push_back(nums[i]);
            }
            if (nums[i] % 3 == 2) {
                two.push_back(nums[i]);
            }
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        //return ret;
        if (ret % 3 == 1) {
            if (one.size() >= 1 && two.size() >= 2) {
                int m = min(one[0], two[0] + two[1]);
                ret -= m;
            }
            else if (one.size() > 0) {
                ret -= one[0];
            }
            else {
                ret -= (two[0] + two[1]);
            }
        }
        else if (ret % 3 == 2) {
            if (one.size() >= 2 && two.size() >= 1 ) {
                int m = min(one[0] + one[1], two[0]);
                ret -= m;
            }
            else if (one.size() >= 2) {
                ret -= (one[0] + one[1]);
            }   
            else {
                ret -= two[0];
            }

        }
        return ret;
    }
};