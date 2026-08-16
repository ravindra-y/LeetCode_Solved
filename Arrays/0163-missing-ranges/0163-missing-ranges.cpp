class Solution {
public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                        int upper) {
    vector<vector<int>> result;
    int next = lower;

    for (int num : nums) {
      // If there is a gap between 'next' and 'num'
      if (num > next) {
        result.push_back({next, num - 1});
      }
      // Move 'next' to the element immediately following the current 'num'
      next = num + 1;
    }

    // Check if there is a gap between the last element and 'upper'
    if (next <= upper) {
      result.push_back({next, upper});
    }

    return result;
  }
};
