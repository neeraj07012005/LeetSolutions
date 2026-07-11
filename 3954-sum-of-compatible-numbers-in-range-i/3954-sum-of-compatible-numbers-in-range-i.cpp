class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= 200; i++){
            if((n & i) == 0){
                nums.push_back(i);
            }
        }

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(abs(n - nums[i]) <= k){
                sum = sum + nums[i];
            }
        }

        return sum;
    }
};