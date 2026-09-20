#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int start = 0; start <= discount.size() - 10; start++){
        map<string, int> sale;
        bool isPossible = true; // ★ 조건이 틀릴 때 바로 break 하기 위한 변수 선언 
        
        for(int i = start; i < start + 10; i++){
            sale[discount[i]]++;
        }
        
        for(int j = 0; j < want.size(); j++){
            if(sale[want[j]] == number[j]) continue;
            else {
                isPossible = false;
                break;
            }
        }
        if(isPossible) answer++;
    }
    return answer;
}