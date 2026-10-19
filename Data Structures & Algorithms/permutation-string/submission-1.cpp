class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>s1f(26,0);
        vector<int>s2f(26,0);
        for(int i=0; i<s1.size(); i++){
            s1f[s1[i]-'a']++;
            s2f[s2[i]-'a']++;
        }
        if(s1f==s2f) return true;
        int l=1;
        int r=s1.size();
        while(r<s2.size()){
            s2f[s2[l-1]-'a']--;
            s2f[s2[r]-'a']++;
            if(s1f==s2f) return true;
            l++;
            r++;
        }
        return false;
    }
};
