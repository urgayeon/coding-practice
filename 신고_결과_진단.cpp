#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> singo_map;
    map<string, int> count;
    
    // 스스로 
    for(string repo : report){
        stringstream ss(repo);
    
        string user;
        string sin_go;
        
        ss >> user >> sin_go;
        
            
        // map 자료구조에서 value 가 존재하는지 find() 로 확인 
        if (find(singo_map[user].begin(), singo_map[user].end(), 
            sin_go) == singo_map[user].end()) {
            singo_map[user].push_back(sin_go);
            count[sin_go]++; // 개인에서만 중복이 안 되는 거니까 
        }   
    }
    
    // 방향성 제시 받음 ㅜㅜ
    for(string id : id_list){
        int mail = 0;
        
        for(string reported : singo_map[id]){
            if(count[reported] >= k){
                mail++;
            }
        }
        answer.push_back(mail);
    }

    return answer;
}