#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> position;
    
    for(int i = 0; i<s.length(); i++){
        char current = s[i];
        
        // 만약 처음 나온 글자라면 
        if( position.find(current) == position.end()){
            position[current] = i;
            answer.push_back(-1);
        }
        // 이미 나온 글자라면 
        else{
            answer.push_back(i-position[current]);
            position[current] = i;
        } 
        
    }
    
    return answer;
}