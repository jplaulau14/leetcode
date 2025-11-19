class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeroes = 0
        non_zeroes = []

        for num in nums:
            if num == 0:
                zeroes += 1
            else:
                non_zeroes.append(num)
        
        non_zeroes = non_zeroes + [0] * zeroes

        for i in range(len(non_zeroes)):
            nums[i] = non_zeroes[i]
        