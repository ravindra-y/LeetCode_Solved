class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);

        for (auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int x = update[2];

            arr[start] += x;
            if (end + 1 < length) arr[end + 1] -= x;
        }

        for (int i = 1; i < length; i++) {
            arr[i] = arr[i-1] + arr[i];
        }

        return arr;
    }
};
