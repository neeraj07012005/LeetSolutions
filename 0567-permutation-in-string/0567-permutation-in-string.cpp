class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp;
        unordered_map<char , int> need;
        for(char ch : s1){
            need[ch]++;
        }
        int l = 0 ;
        bool flag = true;
        for(int r = 0 ; r<s2.size(); r++){
            mpp[s2[r]]++;
            if(r-l+1>s1.size()){
                mpp[s2[l]]--;
                if(mpp[s2[l]]==0){
                    mpp.erase(s2[l]);
                }
                l++;
            }

            if(r-l+1 == s1.size()){
                if(mpp==need){
                    return true;
                }
            }
        }
        return false;
    }
};