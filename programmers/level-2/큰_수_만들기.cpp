#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 숫자의 순서를 바꾸면 안 됨. 완전탐색 X, 정렬 X, 자료구조: stack 

string solution(string number, int k) {
    string answer = "";
    stack<char> biggest_num; 
    
    for(char current : number){
        while(!biggest_num.empty() && k>0 && biggest_num.top() < current){
            biggest_num.pop();
            k--;
        }
        biggest_num.push(current);
    }
    
    while(k>0){
        biggest_num.pop();
        k--;
    }

    while(!biggest_num.empty()){
        answer += biggest_num.top();
        biggest_num.pop();
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}