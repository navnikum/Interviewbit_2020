// First Missing Integer

//M1 : sorting
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    auto itr = upper_bound(A.begin(), A.end(), 0);
    vector<int> v(itr, A.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i + 1)
            return (i + 1);
    }
    return v.size()+1;
}

//M2 : using range [1, N] and bring to correct pos
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i=0; i < n; i++){
        if(A[i] > 0 && A[i] <= n){
            int pos = A[i] - 1;
            if(A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1)
            return (i + 1);
    }
    return n+1;
}
