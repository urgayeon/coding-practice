#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int timeTonum(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    
    return hour*60 + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car_start;
    map<string, int> car_total;
    map<string, int> car_fee;
    int basic_time = fees[0];
    int basic_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    
    // 차량별 입차시간 & 누적시간 계산
    for(string record : records){
        stringstream ss(record);
        
        string time;
        string car_num;
        string in_out;
        
        ss >> time >> car_num >> in_out;
        
        if(in_out == "IN"){
            car_start[car_num] = timeTonum(time);
        }
        else if(in_out == "OUT"){
            car_total[car_num] += timeTonum(time) - car_start[car_num];
            car_start.erase(car_num);
        }  
    }
    
    // 끝까지 OUT 이 안 돼서 erase 안 된 애들의 누적 시간 
    for(auto &car: car_start){
        car_total[car.first] += timeTonum("23:59") - car.second;
    }
    
    // 금액 계산하기 
    for(auto car : car_total){
        if(car_total[car.first] <= basic_time ) 
            car_fee[car.first] = basic_fee;
        
        else{
            int extra_time = car.second - basic_time;
            int unit = extra_time/unit_time;
            if(extra_time%unit_time == 0) car_fee[car.first] = basic_fee + unit*unit_fee;
            else car_fee[car.first] = basic_fee + (unit + 1)*unit_fee;
        }
    }
    
    // map은 key 기준으로 오름차순으로 정렬함 
    for(auto car : car_fee){
        answer.push_back(car.second);
    }
    return answer;
}