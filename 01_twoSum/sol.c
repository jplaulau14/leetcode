#define HASH_SIZE 10000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize hash table
    Node* hashTable[HASH_SIZE] = {NULL};
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hash = abs(complement) % HASH_SIZE;
        
        Node* curr = hashTable[hash];
        while (curr != NULL) {
            if (curr->key == complement) {
                int* res = malloc(2 * sizeof(int));
                res[0] = curr->value;
                res[1] = i;
                *returnSize = 2;
                
                for (int j = 0; j < HASH_SIZE; j++) {
                    Node* node = hashTable[j];
                    while (node != NULL) {
                        Node* temp = node;
                        node = node->next;
                        free(temp);
                    }
                }
                return res;
            }
            curr = curr->next;
        }
        
        hash = abs(nums[i]) % HASH_SIZE;
        Node* newNode = malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = hashTable[hash];
        hashTable[hash] = newNode;
    }
    
    for (int j = 0; j < HASH_SIZE; j++) {
        Node* node = hashTable[j];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    
    *returnSize = 0;
    return NULL;
}