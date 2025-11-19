class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        write_pos = 0
        
        for read_pos in range(len(nums)):
            if nums[read_pos] != 0:
                nums[write_pos] = nums[read_pos]
                write_pos += 1
        
        for i in range(write_pos, len(nums)):
            nums[i] = 0