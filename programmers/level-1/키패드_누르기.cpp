#include <string>
#include <vector>
#include <utility> // pair 헤더 

using namespace std;

// 최단 거리 -> 맨해튼 거리 공식 이용 
int manhatton(const pair<int,int>& current, const pair<int, int>& target){
    int row = abs(current.first - target.first);
    int col = abs(current.second - target.second);
    
    return row + col;
}

string LR(string hand){
    if(hand == "right") return "R";
    return "L";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = {3, 0};   
    pair<int, int> right = {3, 2}; 
    pair<int,int> target;
    string hand_type = LR(hand);
    
    for(int num : numbers){
        if(num == 0) target = {3,1};
        else target = {(num-1)/3,(num-1)%3};
        
        int left_len = manhatton(left, target);
        int right_len = manhatton(right, target);
        
        if(num == 1 || num == 4 || num == 7){
            answer += "L";
            left = target;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            right =  target;
        }
        else {
            if(left_len > right_len) {
                answer+="R";
                right = target;
            }
            else if(left_len < right_len) {
                answer += "L";
                left = target;
            }
            else {
                answer += hand_type;  
                if(hand_type == "R") right = target;
                else left = target;
            }
        }
    }
    return answer;
}