#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    for(int i = 0; i < 26; i++){
        string s(1, 'A' + i); // string 객체 생성자
        dict[s] = i+1;
    }
    
    
    int next_idx = 27;
    
    for(int i = 0; i < msg.length();){ // i 를 내가 직접 조정 
        string word(1, msg[i]);
        int j = i + 1; // 다음 위치 
        
        while(j < msg.length()){
            string next_word = word + msg[j];
            
            if(dict.find(next_word) != dict.end()){
                word = next_word;
                j++;
            }
            else{
                dict[next_word] = next_idx;
                next_idx++;
                break;
            }
        }
        answer.push_back(dict[word]);
        i = j;
    }
    return answer;
}