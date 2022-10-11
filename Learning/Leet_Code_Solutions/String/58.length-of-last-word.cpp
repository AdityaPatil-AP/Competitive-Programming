class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool letterFound = false;
        for(int i = s.size() - 1;i >= 0;i--){
            if(s[i] == ' ' && letterFound){
                break;
            }
            else if(s[i] != ' '){
                letterFound = true;
                ans++;
            }
        }
        return ans;
    }
};