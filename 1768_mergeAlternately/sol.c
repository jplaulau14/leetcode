#include <string.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int min_len = min(len1, len2);
    
    char* result = (char*)malloc(len1 + len2 + 1);
    int pos = 0;
    
    for (int i = 0; i < min_len; i++) {
        result[pos++] = word1[i];
        result[pos++] = word2[i];
    }
    
    for (int i = min_len; i < len1; i++) {
        result[pos++] = word1[i];
    }
    
    for (int i = min_len; i < len2; i++) {
        result[pos++] = word2[i];
    }
    
    result[pos] = '\0';
    
    return result;
}