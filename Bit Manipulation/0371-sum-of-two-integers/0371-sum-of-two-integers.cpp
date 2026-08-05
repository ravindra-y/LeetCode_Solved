class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Find carry and shift it left
            unsigned carry = (unsigned)(a & b) << 1;

            // Add without carry
            a = a ^ b;

            // Use carry for next addition
            b = carry;
        }

        return a;
    }
};