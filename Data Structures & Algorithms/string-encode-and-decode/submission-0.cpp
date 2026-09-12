#include <cctype>

class Solution {
   public:
    string encode(vector<string>& strs) {
        string en = "";
        for (const string& s : strs) {
            en += to_string(s.size()) + "#" + s;
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            int hashPos = s.find('#', i);
            int len = stoi(s.substr(i, hashPos - i));
            v.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }
        return v;
    }
};
