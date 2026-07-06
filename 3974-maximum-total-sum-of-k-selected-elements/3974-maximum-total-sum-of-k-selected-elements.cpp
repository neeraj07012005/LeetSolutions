class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(),greater<>());
        long long sum = 0;
        for(long long i = 0 ; i < k; i++){
            if(mul <= 0){
                sum += nums[i]*1;
            }
            else{
                sum += (long long)nums[i] * mul;
                mul--;
            }
            
            
        }
        return sum;
    }
};