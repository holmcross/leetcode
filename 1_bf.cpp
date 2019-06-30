class Solution {
public:
    //brute force
    std::vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target){
                    std::vector<int> vect{i,j};
                    return vect;
                }
            }
        }
        std::vector<int> blah{0,0};
        return blah; //required for compiler, will never reach because we always find a target.
    }
};
