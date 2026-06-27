class Solution {
public:
    int numSteps(string s) {
        int n=s.size()-1,i=0,steps=0,carry=0;
        for(i=n;i>0;i--){
            if((s[i]-'0'+carry)%2!=0){
                steps+=2;
                carry=1;
            }
            else{
                steps+=1;
            }

        }
        return steps+carry;
    }
};