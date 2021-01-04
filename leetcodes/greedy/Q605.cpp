#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        const int len = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (len + 1) / 2;
        } else {
            count += (len - prev - 1) / 2;
        }
        return count >= n;
    }
};
