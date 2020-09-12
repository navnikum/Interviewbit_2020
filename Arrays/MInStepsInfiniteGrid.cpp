// Min Steps In Infinite Grid

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();
    if(n1 <= 1) return 0;
    assert(n1 == n2);
    int steps = 0;
    for(int i=1; i < n1; i++){
        steps += max(abs(A[i]-A[i-1]), abs(B[i]-B[i-1]));
    }
    return steps;
}
