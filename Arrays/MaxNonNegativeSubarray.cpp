// Max Non Negative SubArray
Asked in:  Google

vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    vector<int> v, ans;
    long long sum = 0, maX = -1;
    for(int i = 0; i< n; i++){
        if(A[i]>=0){
            sum += A[i];
            v.push_back(A[i]);
        }
        if(A[i]<0 || i == n-1){
            if(sum > maX){
                maX = sum;
                ans = v;
            }
            sum = 0;
            v.clear();
        }
    }
    return ans;
}
