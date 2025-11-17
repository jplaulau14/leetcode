class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int countOnes = 0;
        for (int num : nums) {
            if (num == 1) countOnes++;
        }
        
        if (countOnes > 0) {
            return n - countOnes;
        }
        
        int minLen = n + 1;
        
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        
        if (minLen == n + 1) {
            return -1;
        }
        
        return minLen - 1 + n - 1;
    }
};