using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // countMap: How many of each number are left to be used
        // endMap: How many subsequences currently end at a specific number
        unordered_map<int, int> countMap, endMap;

        // Fill the frequency map
        for (int x : nums) {
            countMap[x]++;
        }

        for (int x : nums) {
            // If this number has already been used in previous steps
            if (countMap[x] == 0)
                continue;

            // Option 1: Try to append x to an existing valid subsequence ending
            // at x-1
            if (endMap[x - 1] > 0) {
                countMap[x]--;
                endMap[x - 1]--;
                endMap[x]++;
            }
            // Option 2: Try to start a new subsequence of at least length 3:
            // [x, x+1, x+2]
            else if (countMap[x + 1] > 0 && countMap[x + 2] > 0) {
                countMap[x]--;
                countMap[x + 1]--;
                countMap[x + 2]--;
                endMap[x + 2]++;
            }
            // If it can't be appended or start a new group, it's impossible
            else {
                return false;
            }
        }

        return true;
    }
};