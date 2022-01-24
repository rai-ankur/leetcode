class Solution {
public:
    int *par;
    int *rank;
    int find(int x)
    {
        if(par[x] == x)
            return x;
        int temp=find(par[x]);
        par[x]=temp;
        return temp;
    }
    bool union1(int x,int y)
    {
        int lx=find(x);
        int ly=find(y);
        if(lx!=ly)
        {
            if(rank[lx]>rank[ly])
            {
                par[ly]=lx;
            }else if(rank[lx]<rank[ly])
            {
                par[lx]=ly;
            }else{
                par[lx]=ly;
                rank[ly]++;
            }
            return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n=edges.size();
        par = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            int x=edges[i][0]-1;
            int y=edges[i][1]-1;
            if(union1(x,y))
            {
                ans=edges[i];
                break;
            }
        }
        return ans;
    }
};