// Next Permutation
Asked in:  
Microsoft
Amazon

vector<int> Solution::nextPermutation(vector<int> &A) {
    next_permutation(A.begin(), A.end());
    return A;
}


vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    // find i, j pointers
    int i, j;
    for(i = n-2; i >= 0; i--)
        if(A[i] < A[i+1])
            break;
    
    if(i == -1){
        reverse(A.begin(), A.end());
        return A;
    }
    
    for(j = n-1; j >= 0; j--)
        if(A[i] < A[j])
            break;
    //
    swap(A[i], A[j]);
    // rev A[i+1 .... n-1] since j comes first and hence first permutation with j
    // should start low
    reverse(A.begin()+i+1, A.end());
    return A;
}

