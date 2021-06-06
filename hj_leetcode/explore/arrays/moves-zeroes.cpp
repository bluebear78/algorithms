class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writePointer = 0;
        int size = nums.size();
        for(int readPointer = 0; readPointer < size; readPointer++) {
            if(nums[readPointer] != 0) {
                nums[writePointer++] = nums[readPointer];
            }
        }
        while(writePointer < size) {
            nums[writePointer++] = 0;
        }
    }
};