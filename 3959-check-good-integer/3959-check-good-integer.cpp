class Solution {
public:
    bool checkGoodInteger(int n) {
        int squaresum=0;
        int digitsum = 0;
        while(n!=0){
            int a = 0;
            a = n%10;
            squaresum += a*a;
            digitsum += a;
            n=n/10;
        }
        if((squaresum-digitsum)>=50){
            return true;
        }
        else{
            return false;
        }
    }
};