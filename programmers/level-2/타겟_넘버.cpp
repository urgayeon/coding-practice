#include <string>
#include <vector>

using namespace std;

// answer는 외부 함수에서 정의된 변수이므로 copy-value가 아닌 address-value로 받아올 것. 

//DFS : 모든 부호 조합을 빠짐없이 탐색하는 문제. DFS는 한 가지 조합을 끝까지 만든 뒤 돌아와 다음 조합을 확인하므로 코드가 자연스럽고, 별도의 방문 처리도 필요 X => 재귀 이용 
void DFS(const vector<int>& numbers, int target, int index, int sum, int& answer){
    if(index == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    DFS(numbers, target, index+1, sum + numbers[index], answer);
    DFS(numbers, target, index+1, sum - numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, 0, 0, answer); 
    // 배열, 타겟, 시작 인덱스, 현재 합계, 정답 도달 가짓수 
    return answer;
}