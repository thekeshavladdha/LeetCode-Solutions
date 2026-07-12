class Solution {
public:
    string getHint(string secret, string guess) {
        int mp[10]={0};
        int bulls=0,cows=0;
        for(auto ch:secret){
            mp[ch-'0']++;
        }
        for(int i =0;i<guess.size();i++){
            if(guess[i]==secret[i]){ 
                bulls++;
                mp[guess[i]-'0']--;
            }
        }
        for(int i=0;i<guess.size();i++){
            
            if(guess[i]!=secret[i] && mp[guess[i]-'0']>0){
                cows++;
                mp[guess[i]-'0']--;
            }
        }
        
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};