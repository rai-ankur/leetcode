class Solution {
public:
    bool dfs(vector<int> adj[],int s,int d,vector<bool> &visited)
    {
        if(s==d)
            return true;
        for(auto j:adj[s])
        {
            if(!visited[j])
            {
                visited[j]=true;
                if(dfs(adj,j,d,visited))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        int sz=edges.size();
        for(int i=0;i<sz;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        if(dfs(adj,source,destination,visited))
            return true;
        return false;
    }
};