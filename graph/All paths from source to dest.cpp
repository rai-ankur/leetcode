class Solution {
public:
    void dfs(int st,int n,vector<vector<int>> &graph,vector<vector<int>> &ans,vector<int> &curr)
    {
        if(st==n-1)
        {
            ans.push_back(curr);
            return ;
        }
        for(auto i:graph[st])
        {
            curr.push_back(i);
            dfs(i,n,graph,ans,curr);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = graph.size();
        curr.push_back(0);
        dfs(0,n,graph,ans,curr);
        return ans;
    }
};