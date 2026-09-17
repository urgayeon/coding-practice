#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> howclick;
    
    for(string key : keymap){
        for(int i=0; i<key.length(); i++){
            if(howclick.find(key[i]) == howclick.end()){
                howclick[key[i]] = i+1;
            }
            else{
                howclick[key[i]] = min(howclick[key[i]], i+1);
            }
        }
    }
    
    for(string word : targets){
        int ans = 0;
        for(int i=0; i<word.length(); i++){
            // word의 문자열 속 keymap 과 일치하는 게 없을 때 처리 
            if(howclick.find(word[i]) == howclick.end()){
                ans = -1;
                break;
            }
            ans += howclick[word[i]];
        }
        answer.push_back(ans);
    }
    return answer;
}