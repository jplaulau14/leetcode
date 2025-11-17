class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        result = ""
        
        for i in range(len(strs[0])):
            char_to_check = strs[0][i]
            
            for string in strs:
                if i >= len(string) or string[i] != char_to_check:
                    return result
            
            result += char_to_check
        
        return result