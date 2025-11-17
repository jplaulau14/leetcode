int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minOperations(int* nums, int numsSize) {
    int countOnes = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) countOnes++;
    }
    
    if (countOnes > 0) {
        return numsSize - countOnes;
    }
    
    int minLen = numsSize + 1;
    
    for (int i = 0; i < numsSize; i++) {
        int g = nums[i];
        for (int j = i; j < numsSize; j++) {
            g = gcd(g, nums[j]);
            if (g == 1) {
                int len = j - i + 1;
                if (len < minLen) minLen = len;
                break;
            }
        }
    }
    
    if (minLen == numsSize + 1) {
        return -1;
    }
    
    return minLen - 1 + numsSize - 1;
}