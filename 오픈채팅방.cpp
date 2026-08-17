#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // {uid, option} pair 형태로 vector 에 저장해둔다는 것이 key point 
    vector<pair<string, string>> history;
    map<string, string> nickname; // uid -> nickname 매핑 
    
    for(string rec : record){
        stringstream ss(rec);
        
        string option;
        string uid;
        string name;
        
        ss >> option >> uid;
        
        if(option == "Enter"){
            ss >> name;
            history.push_back({uid, option});
            nickname[uid] = name;
        }
        else if(option == "Leave"){
            history.push_back({uid, option});
        }
        else{
            ss >> name;
            nickname[uid] = name;
        }
    }
    
    for(auto& h : history){
        if(h.second == "Enter"){
            answer.push_back(nickname[h.first] + "님이 들어왔습니다.");
        }
        else if(h.second == "Leave"){
            answer.push_back(nickname[h.first] + "님이 나갔습니다.");
        }
    }
    return answer;
}