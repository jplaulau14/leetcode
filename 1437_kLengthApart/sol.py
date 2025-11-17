class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        flag = -1

        for i, n in enumerate(nums):
            if n == 1:
                if flag != -1:
                    distance = i - flag - 1
                    if distance < k:
                        return False

                flag = i
        
        return True

