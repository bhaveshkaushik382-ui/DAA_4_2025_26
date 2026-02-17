class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        long long low = 0;
        long long high = 0;
        for (int x : arr) {
            if (x > low) low = x; 
            high += x;           \
        }
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;      
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return (int)ans;
    }
private:
    bool isPossible(const vector<int>& arr, int k, long long max_workload) {
        int painters_count = 1;
        long long current_sum = 0;
        for (int board : arr) {
            if (current_sum+board<= max_workload){
                current_sum += board;
            }else{
                painters_count++;
                current_sum=board;
                if (painters_count > k) return false;
            }
        }
        return true;
    }
};