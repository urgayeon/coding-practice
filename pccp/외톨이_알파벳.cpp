#include <string>
#include <vector>

using namespace std;

// 현재 문자와 이전 문자를 비교.
// 현재 문자가 이전 문자와 같다면 어떻게 처리해야 할까? => 넘어간다. 
//현재 문자가 이전 문자와 다른데, 과거에 이미 등장했던 문자라면? => 외톨이 알파벳 확정 

string solution(string input_string) {
    string answer = "";
    bool visited[26] = {false};
    bool isLonely[26] = {false};
    visited[input_string[0] - 'a'] = true;
    
    for(int i = 1; i<input_string.length(); i++){
        char current = input_string[i];
        char previous = input_string[i-1];
        
        if(!visited[current - 'a']) visited[current - 'a'] = true;
        else{
            if(current == previous) continue; 
            else isLonely[current - 'a'] = true; 
        }
    }
    
    for(int i = 0; i<26; i++){
        if(isLonely[i]) answer += 'a' + i;
    }
    
    if(answer == "") return "N";
    
    
    return answer;
}