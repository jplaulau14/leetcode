class Solution:
    def reverseWords(self, s: str) -> str:
        lst = s.strip().split()

        lst.reverse()

        return " ".join(lst)