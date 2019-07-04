/*

sliding window method?

*/

class Solution {
public:
    
int lengthOfLongestSubstring(std::string s) {

    const int n = s.size();
    
    std::map<char, char> my_map;
    
    int answer = 0;
    int i = 0;
    int j = 0;
    
    while (i < n && j < n){
        if(! my_map[ s.at(j) ]){
            my_map[ s.at(j) ] = s.at(j);
            j++;
            answer = std::max(answer, j - i);
        }
        else{
            my_map.erase( s.at(i) );
            i++;
        }
    }
    return answer;
}
};