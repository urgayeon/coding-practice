#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue <char> parentheses;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            parentheses.push(s[i]);
        }
        else{
            if(parentheses.empty()){
                answer=false;
                break;
            }
            parentheses.pop();
        }
    }
    
    if(!parentheses.empty()) answer = false;

    return answer;
}