#include <iostream>
#include <string>
#include <vector>

bool isValid(std::string s) {
    std::vector<char> stack;
    for(auto c : s){
        if(c == '(' || c == '[' || c == '{'){
            stack.push_back(c);
        }
        else if(stack.size() == 0){
            return 0;
        }
        else if( c == ')' ){
            if(stack.back() == '('){
                stack.pop_back();
            }
            else{
                return 0;
            }
        }
        else if( c == ']' ){
            if(stack.back() == '['){
                stack.pop_back();
            }
            else{
                return 0;
            }
        }
        else if( c == '}' ){
            if(stack.back() == '{'){
                stack.pop_back();
            }
            else{
                return 0;
            }
        }
    }
    return(stack.size() == 0);
}

int main(){
    //add test cases
}