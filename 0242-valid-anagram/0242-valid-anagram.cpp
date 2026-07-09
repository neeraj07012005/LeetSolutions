class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        // Count characters in s
        for (char c : s) {
            mp[c]++;
        }

        // Remove characters using t
        for (char c : t) {
            mp[c]--;
        }

        // Check if every frequency became 0
        for (auto p : mp) {
            if (p.second != 0)
                return false;
        }

        return true;
    }
};