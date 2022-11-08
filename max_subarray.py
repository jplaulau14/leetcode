# Kadane's Algo

def maxSubArray(nums):
    curr_max, max_till_now = 0, -9999999

    for num in nums:
        curr_max = max(num, curr_max + num)
        max_till_now = max(max_till_now, curr_max)
    return max_till_now