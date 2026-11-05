#include <string>
#include <vector>

using namespace std;

// answer는 외부 함수에서 정의된 변수이므로 copy-value가 아닌 address-value로 받아올 것. 
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