class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int oneDel = 0;
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            oneDel = max(noDel, oneDel + arr[i]);
            noDel = max(arr[i], noDel + arr[i]);
            result = max({result, noDel, oneDel});
        }

        return result;
    }
};