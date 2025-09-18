
using int2=pair<int , int>; 
int2 mp[100001];// taskID->(prioity, userId)
class TaskManager {
    int maxI=-1;
    priority_queue<int2> pq; //(priority, taskID)
public:
    TaskManager(vector<vector<int>>& tasks) {
     //   fill(mp, mp+100001, make_pair(-1, -1));
        for(auto& t: tasks){
            int  u=t[0], i=t[1], p=t[2];
            maxI=max(maxI, i);
            mp[i]={p, u};
            pq.emplace(p, i);
        }
    }
    ~TaskManager(){
        memset(mp, -1, 8*(maxI+1));
    }
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp[i].first==p) {
                pq.pop();
                int u=mp[i].second;
                mp[i]={-1, -1}; // Remove task after execution
                return u;
            }
            pq.pop(); // Remove
        }
        return -1; // No valid tasks to execute
        
    }
};
