class Solution {
public:
    void dfs(vector<vector<int>> &rooms,int st,vector<bool> &visited)
    {
        visited[st]=true;
        for(auto i : rooms[st])
            if(!visited[i])
                dfs(rooms,i,visited);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,0,visited);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
                return false;
        }
        return true;
    }
};