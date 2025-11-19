class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write_pos = 0;
        
        for (int read_pos = 0; read_pos < nums.size(); read_pos++) {
            if (nums[read_pos] != 0) {
                nums[write_pos] = nums[read_pos];
                write_pos++;
            }
        }
        
        for (int i = write_pos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};