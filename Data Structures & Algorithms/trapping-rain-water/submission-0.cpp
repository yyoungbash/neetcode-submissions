class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size(), maxL[n], maxR[n], currmax = 0;
       for(int i = 0; i < n; i++) {
        currmax = max(height[i], currmax);
        maxL[i] = currmax;
       }
       currmax = 0;

       for(int i = n - 1; i >= 0; i--) {
        currmax = max(height[i], currmax);
        maxR[i] = currmax;
       }
       
       int res = 0;

      for(int i = 0; i < n; i ++) {
        int curr = min(maxL[i], maxR[i]) - height[i];
        if (curr > 0) res += curr;
      }

      return res;
    }
};
