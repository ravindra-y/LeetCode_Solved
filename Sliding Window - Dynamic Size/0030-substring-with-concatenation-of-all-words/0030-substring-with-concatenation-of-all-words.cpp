class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].size();
        int numWords = words.size();
        int n = s.size();

        if (n < wordLen * numWords) return result;

        unordered_map<string, int> target;
        for (auto& w : words) target[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> window;
            int count = 0;
            int left = offset;

            for (int j = offset; j + wordLen <= n; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (!target.count(word)) {
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                } else {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        window[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords)
                        result.push_back(left);
                }
            }
        }
        return result;
    }
};