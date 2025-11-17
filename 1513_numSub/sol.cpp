class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int count = 0;
        
        for (char c : s) {
            count = (c == '1') ? count + 1 : 0;
            result += count;
        }
        
        return result % MOD;
    }
};