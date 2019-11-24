class Solution {
public:
    // dp(dynamic programming) table
    long long dp[501][501];
    long long m = 1000000007;

    // the rightmost index possible 
    int maximum;

    // returns the number of cases that can finish in index 0 when
    // the remaining number of movements is "move"
    // and the current index is "position"
    long long go(int move, int position) {

        // if the current index is out of the array, then the movement is invalid
        if (position < 0 || position >= maximum) {
            return 0;
        }

        // if there are no remaining movements
        if (move == 0) {
            // only valid when the current position has returned to zero
            if (position == 0) return 1;
            else return 0;
        }

        // if we have already visited the current case, return it
        if (dp[move][position] != -1) {
            return dp[move][position];
        }
        // we can either
        // 1) move one position to the left
        // 2) stay at the current position
        // 3) move one position to the right
        // and whatever we do, we use one movement remaining
        long long ret = 0LL;
        ret += (go(move - 1, position - 1) + go(move - 1, position) + go(move - 1, position + 1)) % m;

        // return the value and fill in the dp table
        return dp[move][position] = ret;
    }
    
    int numWays(int steps, int arrLen) {
        maximum = arrLen;
        memset(dp, -1, sizeof(dp));
        return (int)go(steps, 0);
    }
};