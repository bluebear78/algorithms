class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = 0;
        int pre = -2e8;
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            if(pre < cur) {
                nums[size++] = cur;
            }
            pre = cur;
        }   
        
        return size;
    }
};