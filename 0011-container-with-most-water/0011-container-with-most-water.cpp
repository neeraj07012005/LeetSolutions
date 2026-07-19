class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r =height.size()-1;
        int ans=INT_MIN;
        while(l<r){
            int width = r-l;
            int h = min(height[l],height[r]);
            ans = max(ans,width*h);
           if(height[l]<height[r]){
            l++;
           }
           else{
            r--;
           }
        }
        return ans;
    }
};