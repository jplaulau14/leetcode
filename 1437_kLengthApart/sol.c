bool kLengthApart(int* nums, int numsSize, int k) {
    int flag = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (flag != -1) {
                int distance = i - flag - 1;
                if (distance < k) {
                    return false;
                }
            }
            flag = i;
        }
    }

    return true;
}