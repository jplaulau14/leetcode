class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        x, y, idx = m-1, n-1, m + n - 1

        while y >= 0:
            if x >= 0 and nums1[x] > nums2[y]:
                nums1[idx] = nums1[x]
                x -= 1
            else:
                nums1[idx] = nums2[y]
                y -= 1
            idx -= 1