//Maximum Unsorted Subarray
Asked in:  
Amazon

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size(), i, j, k;
    for(i = 0; i < n-1; i++){
        if(A[i] > A[i+1])
            break;
    }
    if(i == n-1) return {-1};
    for(j = n-1; j > 0; j--){
        if(A[j] < A[j-1])
            break;
    }
    // A[l .... r] min max element
    int max = *max_element(A.begin()+i, A.begin()+j+1);
    int min = *min_element(A.begin()+i, A.begin()+j+1);

    // min(A[l], ..., A[r]) >= max(A[0], ..., A[l-1]) 
    for(k = 0; k < i; k++){
        if(A[k] > min){
            i = k;
            break;
        }
    }
    // max(A[l], ..., A[r]) <= min(A[r+1], ..., A[N-1])
    for(k = n-1; k > j; k--){
        if(A[k] < max){
            j = k;
            break;
        }
    }
    return {i, j};
}
