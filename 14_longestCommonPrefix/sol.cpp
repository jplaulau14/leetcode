#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        string result = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char char_to_check = strs[0][i];

            for (const string& str : strs) {
                if (i >= str.length() || str[i] != char_to_check) {
                    return result;
                }
            }
            result += char_to_check;
        }

        return result;
    }
};