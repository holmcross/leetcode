#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    
    std::vector<std::vector<int>> result;
    
    if(nums.size() < 2){
        return result;
    }
    
    std::sort(nums.begin(), nums.end());

    int i = 0;
    int j = 0;
    int k = nums.size() -1; //index of last element
    std::vector<int> answer_vect{0,0,0};

    // [-4, -1, -1, -1, 0, 0, 0, 0, 0, 1, 2, 3, 4]
    // [-4, -1, -1, 0, 1, 2]
    // [-4, -1, -1, -1, 0, 0, 1, 1, 2, 3, 4]
    // [-5, -4, -2, -1, -1, -1, -1, 0, 0, 0, 1, 1, 2]
    
    while(i < nums.size() - 2){
        j = i + 1;
        k = nums.size() -1;
        while(j < k){        
            
            if( (nums[k] + nums[i] + nums[j]) > 0 ){ // move a pointer in such a way the sum becomes less positive
                k--;
                while(k > j && nums[k]==nums[k+1]){
                    k--;
                }
            }
            else if( (nums[k] + nums[i] + nums[j]) < 0 ){ // move a pointer in such a way the sum becomes less negative
                j++;
                while(k > j && nums[j]==nums[j-1]){
                    j++;
                }
            }
            else {
                std::vector<int> temp{nums[i], nums[j], nums[k]};
                result.push_back(temp);
                j++;
                while(k > j && nums[j]==nums[j-1]){
                    j++;
                }
            }
        }
        i++;
        while(i < nums.size() -1 && nums[i]==nums[i-1]){
                    i++;
                }
    }
    return result;
}



int main(int argc, char const *argv[])
{

    std::vector<int> vect{-5, -4, -2, -1, -1, -1, -1, 0, 0, 0, 1, 1, 2};
    //std::vector<int> vect{0,0,0};

    std::vector<std::vector<int>> result_vector = threeSum(vect);

    std::cout << "size is: ";
    std::cout << result_vector.size() << std::endl;

    for( auto i : result_vector){
        for( auto f : i){
            std::cout << f << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}
