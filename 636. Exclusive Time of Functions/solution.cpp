/*

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> stk;
        int preTime= 0;
        for(auto log: logs){
            
            //extract information from log, which function, start or end, happened time
            int found1= log.find(":"); //get index of function
            int found2= log.find_last_of(":"); //time frame
            int idx= stoi(log.substr(0, found1));
            string type= log.substr(found1+1, found2-found1-1); //"start" or "end"
            int time = stoi(log.substr(found2+1));
            
            if(!stk.empty()){
                res[stk.top()]+= time-preTime;
            }
            preTime = time;
            if(type == "start") stk.push(idx);
            else{
                auto tmp= stk.top(); stk.pop();
                ++res[tmp];
                ++preTime;
            }
        }
        return res;
    }
};
