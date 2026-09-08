class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        long long threshold = 1000;

        while (threshold <= n) {
            count += n - threshold + 1;
            threshold *= 1000;
        }
        
        return count;
    }
};