class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>um;
        vector<vector<int>> v(nums.size() + 1);
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        // vector<pair<int, int>> v(um.begin(), um.end());
        // sort(v.begin(), v.end(), [&](auto&a, auto&b){
        //     return a.second>b.second;
        // });
        // vector<int>ans;
        // for(auto i = v.begin(); i!=v.end(); i++){
        //     if(k>0) ans.push_back(i->first);
        //     k--;
        // }
        // return ans;
        for(auto i = um.begin(); i!=um.end(); i++){
            v[i->second].push_back(i->first);
        }
        vector<int>ans;
        for(int i=v.size()-1; i>0; i--){
            for(int n: v[i]){
                ans.push_back(n);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
