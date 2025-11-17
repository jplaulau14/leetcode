#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int max_len = strlen(strs[0]);
    char* result = (char*)malloc(max_len + 1);
    int result_len = 0;

    for (int i = 0; i < strlen(strs[0]); i++) {
        char char_to_check = strs[0][i];

        for (int j = 0; j < strsSize; j++) {
            if (i >= strlen(strs[j]) || strs[j][i] != char_to_check) {
                result[result_len] = '\0';
                return result;
            }
        }

        result[result_len++] = char_to_check;
    }

    result[result_len] = '\0';
    return result;
}