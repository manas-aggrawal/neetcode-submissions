class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int len = 0;
        map<char, int> seen;
        while (r < s.size()) {
            if (seen.find(s[r]) != seen.end()) {
                l = max(seen[s[r]]+1, l);
            } 
            seen[s[r]] = r;
            len = max(r-l+1, len);
            r++;
        }
        return len;
    }
};
