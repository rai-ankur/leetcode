class Solution {
public:
    int *par;
    int *rank;
    int count;
    int find(int x)
    {
        if(par[x] == x)
            return x;
        int temp=find(par[x]);
        par[x]=temp;
        return temp;
    }
    void union1(int x,int y)
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
        }else{
            count++;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int dots = n+1;
        count=1;
        par = new int[dots*dots];
        rank = new int[dots*dots];
        for(int i=0;i<dots*dots;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int cell = i*(n+1)+j;
                if(i==0 || j == 0 || i == n || j==n)
                {
                    if(cell != 0)
                    {
                        union1(0,cell);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int x=(i+1)*(n+1)+j;
                    int y=i*(n+1)+(j+1);
                    union1(x,y);
                }
                else if(grid[i][j] == '\\')
                {
                    int x=i*(n+1)+j;
                    int y=(i+1)*(n+1)+j+1;
                    union1(x,y);
                }
            }
        }
        return count;                
    }
};