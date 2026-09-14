class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int, int>um;
        for(int i=0; i<n.size(); i++){
            if(um.find(t-n[i])!=um.end()) return {um[t-n[i]], i+1};
            um.insert({n[i], i+1});
            
        }
        return {};
    }
};
