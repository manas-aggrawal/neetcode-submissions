#include<cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        for(int i=0; i<s.size(); i++){
            s[i] = tolower(s[i]);
        }
        while(i<j){
            if(!isalnum(s[i])) {
                i++;
                continue;
            }else if(!isalnum(s[j])){
                --j;
                continue;
            }
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
