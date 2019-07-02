#include <iostream>
#include <string>
#include <map>


int lengthOfLongestSubstring(std::string s) {
    std::map<char, bool> hash;
    int starting_index;
    int current_length;
    int longest_length = 0;

    for(int i = 0; i < s.size(); i++){
        hash[ s.at(i) ] = 1;
        current_length = 1;
        for(int j = i+1; j < s.size(); j++){
            if(hash[s.at(j)] != 1){
                hash[ s.at(j) ] = 1;
                current_length++;
            }
            else{
                if(longest_length < current_length){
                    longest_length = current_length;
                }
                break;
            }
        }
        if(longest_length < current_length){
            longest_length = current_length;
        }
    }
    return longest_length;
}


int main(int argc, char const *argv[])
{

    return 0;
}
