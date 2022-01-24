class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=n+1;
        int in[m];
        int out[m];
        for(int i=0;i<m;i++)
        {
            in[i]=0;
            out[i]=0;
        }
        int sz=trust.size();
        for(int i=0;i<sz;i++)
        {
            in[trust[i][1]]++;
            out[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(in[i]==n-1 and out[i]==0)
                return i;
        }
        return -1;
    }
};