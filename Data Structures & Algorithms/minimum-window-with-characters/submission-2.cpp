class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> vs(128);
        vector<int> vt(128);
        int l = 0;
        int r = t.size() - 1;
        int missing = t.size();
        for (char c : t) vt[c]++;
        for (int i = 0; i <= r; i++) {
            if (vs[s[i]] < vt[s[i]]) missing--;
            vs[s[i]]++;
        }
        int bestLen = INT_MAX;
        pair<int, int> res;
        while (r < s.size()) {
            if (missing == 0) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    res = {l, r};
                };
                vs[s[l]]--;
                if (vs[s[l]] < vt[s[l]]) missing++;
                l++;
            } else {
                r++;
                if (r >= s.size()) break;
                if (vs[s[r]] < vt[s[r]]) missing--;
                vs[s[r]]++;
            }
        }
        return bestLen < INT_MAX ? s.substr(res.first, res.second - res.first + 1) : "";
    }
};
