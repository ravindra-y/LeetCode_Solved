class Solution {
public:
    unordered_map<string, string> mp;
    int n = 0;
    string base = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string id = to_string(n++);
        mp[id] = longUrl;
        return base + id;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl.substr(base.length())];
    }
};