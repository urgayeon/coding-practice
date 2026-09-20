#include <string>
#include <vector>

using namespace std;

int timeTosecond(string time){
    int minute = stoi(time.substr(0,2));
    int second = stoi(time.substr(3,2));
    
    return minute*60 + second;
}

string secondTominute(int time){
    string mm = to_string(time/60);
    string ss = to_string(time%60);
    
    if(mm.length() == 1) mm = "0" + mm;
    if(ss.length() == 1) ss = "0" + ss;
    
    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int current_pos = timeTosecond(pos);
    int total_ss = timeTosecond(video_len);
    
    if(current_pos <= timeTosecond(op_end) && current_pos >= timeTosecond(op_start))
        current_pos = timeTosecond(op_end);
    
    for(string cmd : commands){
        if(cmd == "prev"){
            current_pos -= 10;
            if(current_pos < 0) current_pos = 0;
            if(current_pos <= timeTosecond(op_end) && current_pos >= timeTosecond(op_start))
        current_pos = timeTosecond(op_end);
        }
        else if(cmd == "next"){
            current_pos += 10;
            if(total_ss < current_pos) current_pos = total_ss;
            if(current_pos <= timeTosecond(op_end) && current_pos >= timeTosecond(op_start))
        current_pos = timeTosecond(op_end);
        }
    }
    
    answer = secondTominute(current_pos);
    return answer;
}