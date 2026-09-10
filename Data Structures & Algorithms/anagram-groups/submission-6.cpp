class Solution {
   private:
    string formString(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }
        string res = "";
        for(int i=0; i<v.size(); i++){
            res+=v[i];
        }
        
        return res;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 1) {
            return {{""}};
        } else if (strs.size() == 1)
            return {{strs[0]}};

        unordered_map<string, vector<string>>um;

        for (int i = 0; i < strs.size(); i++) {
            string s = formString(strs[i]);
            if(um.find(s)==um.end()) um.insert({s, {strs[i]}});
            else um[s].push_back(strs[i]);
            
        }
        vector<vector<string>>v;
        for(auto i=um.begin(); i!=um.end(); i++){
            v.push_back(i->second);
        }
        return v;
    }
};
