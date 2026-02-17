class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        long long low = 0;
        long long high= 0;
        
        for (int x : arr) {
            if (x > low) low = x;
            high += x;
        }
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            
            if (canPaint(arr, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return (int)low;
    }

private:
    bool canPaint(const vector<int>& arr, int k, long long limit) {
        int count = 1;
        long long current_sum = 0;
        
        for (int x : arr) {
            if (current_sum + x <= limit) {
                current_sum += x;
            } else {
                count++;
                current_sum = x;
                if (count > k) return false;
            }
        }
        return true;
    }
};