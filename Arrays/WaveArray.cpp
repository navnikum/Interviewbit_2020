// Wave Array
Asked in:  
Google
Adobe
Amazon

vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 1; i < n ; i++){
        if(i % 2 == 1)
            swap(A[i], A[i-1]);
    }
    return A;
}
