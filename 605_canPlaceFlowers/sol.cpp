#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            
            bool left_ok = (i == 0) || (flowerbed[i - 1] == 0);
            
            bool right_ok = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
            
            if (left_ok && right_ok) {
                flowerbed[i] = 1;
                count++;
                
                if (count >= n) {
                    return true;
                }
            }
        }
        
        return count >= n;
    }
};