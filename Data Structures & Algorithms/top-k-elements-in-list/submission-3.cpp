class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        vector<pair<int, int>> v(um.begin(), um.end());
        sort(v.begin(), v.end(), [&](auto&a, auto&b){
            return a.second>b.second;
        });
        vector<int>ans;
        for(auto i = v.begin(); i!=v.end(); i++){
            if(k>0) ans.push_back(i->first);
            k--;
        }
        return ans;
    }
};
