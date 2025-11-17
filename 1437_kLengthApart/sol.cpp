class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int flag = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (flag != -1) {
                    // [0, 1, 0, 1], 2
                    int distance = i - flag - 1;
                    if (distance < k) {
                        return false;
                    }
                }

                flag = i;
            }
        }

        return true;
    }
};