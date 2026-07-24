class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>=1){
            int x=pq.top();
            pq.pop();
            if(pq.empty()) return x;
            int y=pq.top();
            pq.pop();
            if(x-y!=0) pq.push(x-y);
        }
        return 0;
    }
};