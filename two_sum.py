# Brute force O(n^2) solution
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

# Two-pass Hash Table
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = {}
        for i, num in enumerate(nums):
            num_dict[num] = i
            
        for i, num in enumerate(nums):
            if target - num in num_dict and num_dict[target - num] != i:
                return [i, num_dict[target - num]]