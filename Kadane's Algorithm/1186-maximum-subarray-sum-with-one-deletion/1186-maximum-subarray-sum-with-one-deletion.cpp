class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        // noDel: Max subarray sum ending at 'i' with 0 deletions (Standard Kadane's)
        int noDel = arr[0];
        
        // oneDel: Max subarray sum ending at 'i' with 1 deletion
        int oneDel = 0; 
        
        // Tracks global maximum sum seen so far
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            // 1. Delete arr[i] NOW (uses prev noDel) OR keep arr[i] (already deleted before)
            oneDel = max(noDel, oneDel + arr[i]);
            
            // 2. Standard Kadane's: Start fresh at arr[i] OR extend previous subarray
            noDel = max(arr[i], noDel + arr[i]);
            
            // 3. Update overall maximum
            result = max({result, noDel, oneDel});
        }

        return result;
    }
};