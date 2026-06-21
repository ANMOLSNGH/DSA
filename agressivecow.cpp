#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to check if 'mid' distance is valid
    bool canPlaceCows(const vector<int>& stalls, int k, int min_dist) {
        int cows_placed = 1;
        int last_position = stalls[0]; // Always place the first cow at the first stall
        
        for (int i = 1; i < stalls.size(); i++) {
            // If the distance from the last placed cow is sufficient
            if (stalls[i] - last_position >= min_dist) {
                cows_placed++;
                last_position = stalls[i];
                
                // If we placed all cows, this minimum distance works
                if (cows_placed == k) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int aggressiveCows(vector<int>& stalls, int k) {
        // 1. Sort the array (Crucial for calculating distances left-to-right)
        sort(stalls.begin(), stalls.end());
        
        // 2. Define the search space
        int low = 1; 
        int high = stalls.back() - stalls.front();
        int best_distance = 0;
        
        // 3. Binary Search on the Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canPlaceCows(stalls, k, mid)) {
                // If valid, save it and try to push the cows even further apart
                best_distance = mid;
                low = mid + 1; 
            } else {
                // If invalid, the required distance is too strict, shrink it
                high = mid - 1;
            }
        }
        
        return best_distance;
    }
};