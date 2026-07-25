class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string s ="11";
        int count = 1;
        string result ="";
        for(int i =2 ; i < n ; i++){
            for(int j = 1 ; j<s.size();j++){
                if(s[j-1]==s[j]){
                    count++;
                }else{
                    result=result+to_string(count);
                    result=result+s[j-1];
                    count =1;
                }
            }
            result= result+to_string(count);
            result=result+s[s.size()-1];
            count =1;
            s=result;
            result ="";
        }
        return s;
        

    }
};