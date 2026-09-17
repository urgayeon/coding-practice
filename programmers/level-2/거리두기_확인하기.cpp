#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int manhatton(const pair<int,int>& current, const pair<int, int>& target){
    int row = abs(current.first - target.first);
    int col = abs(current.second - target.second);
    
    return row + col;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pair<int, int>> people;
    
    for(int room = 0; room < 5; room++){
        vector<pair<int, int>> people;
        bool success = true;
        
        for(int row = 0; row < 5 && success; row++){
            for(int col = 0; col < 5 && success; col++){
                if(places[room][row][col] == 'P'){
                    pair<int, int> current = {row, col};
                
                    for(auto& person : people){
                        int distance = manhatton(current, person);
                    
                        if(distance >= 3) continue; // 거리두기 성공 -> 다음 P 와 거리 비교로 넘어감 
                        
                        else if(distance == 1){ // 거리두기 실패 -> 해당 대기실 바로 끝 
                            success = false;
                            break;
                        }
                        else if(distance == 2){ // 거리두기 실패 -> 해당 대기실 바로 끝
                            if(current.first == person.first){
                                int middle_col = (current.second + person.second) / 2;
                                if(places[room][row][middle_col] != 'X'){
                                    success = false;
                                    break;
                                }
                            }
                            else if(current.second == person.second){
                                int middle_row = (current.first + person.first) / 2;
                                if(places[room][middle_row][col] != 'X'){
                                    success = false;
                                    break;
                                }
                            }
                            else{
                                if(places[room][current.first][person.second] != 'X' || places[room][person.first][current.second] != 'X'){
                                    success = false;
                                    break;
                                }
                            }
                        }
                    }
                    people.push_back(current);
                }
            }
        }
        if(!success) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}