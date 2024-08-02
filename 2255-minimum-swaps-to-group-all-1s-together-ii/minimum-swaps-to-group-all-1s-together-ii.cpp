class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        
        // Count total number of 1's in the array
        for(int num : nums) {
            if(num == 1) totalOnes++;
        }
        
        // Handle edge case where there are no 1's or the array is already optimal
        if(totalOnes == 0 || totalOnes == n) return 0;
        
        // Create an extended array to simulate the circular nature
        vector<int> extended(nums.begin(), nums.end());
        extended.insert(extended.end(), nums.begin(), nums.end());
        
        // Initialize the window
        int currentZeros = 0;
        for(int i = 0; i < totalOnes; ++i) {
            if(extended[i] == 0) currentZeros++;
        }
        
        // Minimum swaps needed (initially the number of 0's in the first window)
        int minSwaps = currentZeros;
        
        // Slide the window over the extended array
        for(int i = totalOnes; i < 2 * n; ++i) {
            if(extended[i] == 0) currentZeros++;
            if(extended[i - totalOnes] == 0) currentZeros--;
            minSwaps = min(minSwaps, currentZeros);
        }
        
        return minSwaps;
    }
};
