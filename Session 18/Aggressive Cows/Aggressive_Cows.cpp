class Solution {
  private:
    bool canPlace(vector<int> &stalls, int k, int mid) {
        int count = 1; 
        int lastPos = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= mid) {
                count++;
                lastPos = stalls[i];
            }
            if (count >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int low = 1; 
        int high = stalls[n - 1] - stalls[0]; 
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(stalls, k, mid)) {
                res = mid;     
                low = mid + 1;
            } else {
                high = mid - 1; }
        }
        return res;
    }
};