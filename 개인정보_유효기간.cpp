#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int dateTonum(string today){
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8,2));
    
    int num = year*12*28 + month*28 + day;
    return num;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> term_map;
    
    int today_num = dateTonum(today);
    
    // 약관 종류 -> 기간 매핑 
    for(string term : terms){
        stringstream ss(term);
        
        string type;
        int month;
        
        ss >> type >> month;
        term_map[type]=month;
    }
    
    for(int i=0; i<privacies.size(); i++){
        stringstream ss(privacies[i]);
        
        string startDays;
        string privaciy_type;
        
        // 개인정보 하나 날짜, 약관종류 분리
        ss >> startDays >> privaciy_type;
        
        // 수집 날짜 -> 숫자로 변환 
        int startDays_num = dateTonum(startDays);
        
        // startDays_num + 종류별 약관기간 < today_num 비교
        int days_num = term_map[privaciy_type] * 28;
        if(startDays_num + days_num <= today_num){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}