class Solution {
public:
    void dfs(vector<vector<int>> &isconnected,vector<bool> &visited,int st,int n)
    {
        visited[st]=true;
        for(int i=0;i<n;i++)
        {
            if(isconnected[st][i] and !visited[i] and i!=st)
                dfs(isconnected,visited,i,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
            if(visited[i]==false)
            {
                dfs(isconnected,visited,i,n);
                count++;
            }
        return count;
    }
};