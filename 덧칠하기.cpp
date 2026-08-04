#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0; // 롤러가 칠한 마지막 번호가 어디인지
    
    for(int idx : section){
        if( idx > painted ){
            answer += 1;
            painted = idx + (m-1);
        }
    }
    return answer;
    
}