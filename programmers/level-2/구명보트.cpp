#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() -1;
    
    while(left<=right){
        // 가장 무게가 많이 나가는 사람이 가장 무게가 적은 사람과도 함께 못 탄다면 그 사람은 다른 누구와도 함께 탈 수 없음
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        
        answer++;
    }
    return answer;
}