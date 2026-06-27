class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int res = arr[0];
        int v1=0;
        for (int i = 1; i < arr.size(); i++) {
            if(onedelete==INT_MIN) v1=arr[i];
            else  v1=onedelete+arr[i];
            onedelete = max(v1, nodelete);
            nodelete = max(nodelete + arr[i], arr[i]);

            res = max(res,max(nodelete, onedelete));
        }
        return res;
    }
};