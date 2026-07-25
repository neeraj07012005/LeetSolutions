class Solution {
public:
    int maxProduct(int n) {
        int a=1;
        vector<int> ans;
        while(n>0){
            ans.push_back(n%10);
            n=n/10;
        }
        sort(ans.begin(),ans.end());
        a=ans[ans.size()-1]*ans[ans.size()-2];
        return a;
    }
};