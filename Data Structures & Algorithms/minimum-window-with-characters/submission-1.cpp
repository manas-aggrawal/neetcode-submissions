class Solution {
   private:
    bool match(const vector<int>& vs, const vector<int>& vt) {
        for (int i = 0; i < 128; i++) {
            if (vt[i] > vs[i]) {
                return 0;
            }
        }
        return 1;
    }

   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> vs(128);
        vector<int> vt(128);
        int l = 0;
        int r = t.size() - 1;
        for (int i = 0; i <= r; i++) {
            vs[s[i]]++;
            vt[t[i]]++;
        }
        int bestLen = INT_MAX;
        pair<int, int> res;
        while (r < s.size()) {
            if (match(vs, vt)) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    res = {l, r};
                };
                vs[s[l]]--;
                l++;
            } else {
                r++;
                if (r >= s.size()) break;
                vs[s[r]]++;
            }
        }
        return bestLen < INT_MAX ? s.substr(res.first, res.second - res.first + 1) : "";
    }
};
