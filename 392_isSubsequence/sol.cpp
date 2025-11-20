class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // Pointer for s
        int j = 0;  // Pointer for t
        
        // Continue while we have characters left in both strings
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;  // Found a match, move s pointer
            }
            j++;  // Always move t pointer
        }
        
        // If i reached the end of s, all characters were found
        return i == s.length();
    }
};
