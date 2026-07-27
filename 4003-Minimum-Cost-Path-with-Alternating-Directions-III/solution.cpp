class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        vector<vector<vector<ll>>> dist(
            m,
            vector<vector<ll>>(n, vector<ll>(2, INF))
        );

        using T = tuple<ll,int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][0] = 1;
        pq.push({1,0,0,0});

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};

        while(!pq.empty()){

            auto [d,x,y,p]=pq.top();
            pq.pop();

            if(d!=dist[x][y][p]) continue;

            if(x==m-1 && y==n-1)
                return d;

            // wait
            if(d + penalty[x][y] < dist[x][y][p^1]){
                dist[x][y][p^1]=d+penalty[x][y];
                pq.push({dist[x][y][p^1],x,y,p^1});
            }

            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>=m||ny<0||ny>=n) continue;

                bool allowed=false;

                if(p==0){ // odd action
                    if((dx[k]==0&&dy[k]==1)||(dx[k]==1&&dy[k]==0))
                        allowed=true;
                }else{ // even action
                    if((dx[k]==0&&dy[k]==-1)||(dx[k]==-1&&dy[k]==0))
                        allowed=true;
                }

                ll nd=d+(ll)(nx+1)*(ny+1);

                if(!allowed)
                    nd+=penalty[x][y];

                if(nd<dist[nx][ny][p^1]){
                    dist[nx][ny][p^1]=nd;
                    pq.push({nd,nx,ny,p^1});
                }
            }
        }

        return -1;
    }
};