class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorFlip = start ^ goal;
        int count = 0;

        while (xorFlip != 0) {
            xorFlip = xorFlip & (xorFlip - 1);
            count++;
        }

        return count;
    }
};