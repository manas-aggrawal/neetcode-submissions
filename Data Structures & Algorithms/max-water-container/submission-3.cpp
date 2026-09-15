class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0;
        int j=h.size()-1;
        int mxA = j*(min(h[j], h[i]));
        while(i<j){
            if(h[i]>h[j]){
                --j;
                mxA = max(mxA, (j-i)*(min(h[i],h[j])));
            }else if(h[j]>h[i]){
                ++i;
                mxA = max(mxA, (j-i)*(min(h[i],h[j])));
            }else{
                ++i;
                --j;
                mxA = max(mxA, (j-i)*(min(h[i],h[j])));
            }
        }
        return mxA;
    }
};
