class Solution {
public:
    bool isPalindrome(string s) {
        string S;

        for (char ch : s) {
            if (isalnum(ch))
                S.push_back(tolower(ch));
        }

        int l = 0;
        int r = S.size() - 1;

        while (l < r) {
            if (S[l] != S[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};