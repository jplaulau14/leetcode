class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        """
        Two pointer approach to check if s is a subsequence of t.

        Time Complexity: O(n) where n = len(t)
        Space Complexity: O(1)
        """
        i = 0  # Pointer for s
        j = 0  # Pointer for t

        # Continue while we have characters left in both strings
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1  # Found a match, move s pointer
            j += 1  # Always move t pointer

        # If i reached the end of s, all characters were found
        return i == len(s)
