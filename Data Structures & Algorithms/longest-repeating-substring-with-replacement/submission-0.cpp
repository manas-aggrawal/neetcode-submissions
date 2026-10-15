class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> fmap;
        int maxf = 0;
        int res = 0;
        while (r < s.size()) {
            fmap[s[r]]++;
            maxf = max(maxf, fmap[s[r]]);
            while ((r - l + 1) - maxf > k) {
                fmap[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
