class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        vector<int> non_zeroes;
        
        for (int num : nums) {
            if (num == 0) {
                zeroes++;
            } else {
                non_zeroes.push_back(num);
            }
        }
        
        for (int i = 0; i < zeroes; i++) {
            non_zeroes.push_back(0);
        }
        
        for (int i = 0; i < non_zeroes.size(); i++) {
            nums[i] = non_zeroes[i];
        }
    }
};