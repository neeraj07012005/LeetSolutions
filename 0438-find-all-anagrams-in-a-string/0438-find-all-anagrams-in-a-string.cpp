class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        // If p is longer than s, no anagrams are possible
        if (p.size() > s.size()) {
            return ans;
        }

        vector<int> pFreq(26, 0);

        // Count frequency of characters in p
        for (int i = 0; i < p.size(); i++) {
            char ch = p[i];
            pFreq[ch - 'a']++;
        }

        // Try every possible substring of length p.size()
        for (int i = 0; i <= s.size() - p.size(); i++) {

            vector<int> currFreq(26, 0);

            // Count frequency of the current substring
            for (int j = i; j < i + p.size(); j++) {
                char ch = s[j];
                currFreq[ch - 'a']++;
            }

            // If frequencies match, it's an anagram
            if (currFreq == pFreq) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};