// Add One To Number
Asked in:  
Google
Microsoft

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 1;
    for(int i = n-1; i>=0; i--){
        A[i]+=carry;
        carry = A[i]/10;
        A[i] = A[i]%10;
    }
    if(carry == 1)
        A.insert(A.begin(), 1);
        
    for(int i = 0; i < n; i++){
        if(A[i] != 0){
            vector<int> ans(A.begin()+i, A.end());
            return ans;
        }
    }
        
    return A;
}
