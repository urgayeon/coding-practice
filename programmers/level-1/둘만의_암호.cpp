#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0 ; i<s.length(); i++){
        char change = s[i];
        int count = 0;
        
        while(count < index){
            change++; // 알파벳 하나씩 이동 
            
            if(change > 'z') change = 'a';
            
            // skip 에서 change 를 찾았다면 
            if(skip.find(change) != string::npos)
                continue; // 이 턴의 반복문은 끝내고 다음 반복문으로 넘어감 
            
            count++;
        }
        answer += change;
    }
    return answer;
}