#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> attendance(N);
    for (int i = 0; i < N; i++) {
        cin >> attendance[i];
    }

    unordered_map<int, int> mp;
    
    int prefixSum = 0;
    int maxLength = 0;

    // Important initialization
    mp[0] = -1;

    for (int i = 0; i < N; i++) {
        if (attendance[i] == 'P')
            prefixSum += 1;
        else if (attendance[i] == 'A')
            prefixSum -= 1;

        // If prefix sum already exists
        if (mp.find(prefixSum) != mp.end()) {
            int length = i - mp[prefixSum];
            maxLength = max(maxLength, length);
        } 
        // Store first occurrence
        else {
            mp[prefixSum] = i;
        }
    }

    cout << maxLength << endl;
    return 0;
}
