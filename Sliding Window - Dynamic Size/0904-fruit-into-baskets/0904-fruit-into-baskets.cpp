class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;

        int left = 0;
        int result = 0;

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            int curr = right - left + 1;

            result = max(result, curr);
        }

        return result;
    }
};