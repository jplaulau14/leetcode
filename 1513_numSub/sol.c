int numSub(char* s) {
    const int MOD = 1000000007;
    long long result = 0;
    int count = 0;
    
    while (*s) {
        count = (*s == '1') ? count + 1 : 0;
        result += count;
        s++;
    }
    
    return result % MOD;
}