// Repeat and Missing Number Array
Asked in:  
Amazon

// using visited , non-visited concept as A[i] is continuous 1 to N
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> v = A;
    int x = 0, y = 0;
    for(int i=0; i < n; i++){
        int pos = abs(v[i]) - 1;
        if(v[pos] > 0) // not visited mark visited
            v[pos] = -v[pos];
        else    // visited mark as duplicate
            x = abs(v[i]);
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > 0){ // not visited => missing
            y = (i + 1);
            break;
        }
    }
    return {x, y};
}

// Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2 
// Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N))(A + B).
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long n=A.size(), sum = 0, square = 0;
    for(int i=0; i<n; i++) {
        sum += A[i];
        square += (long)A[i] * (long)A[i];
    }
    long diff= n*(n+1)/2 - sum;
    long a = n*(n+1)*(2*n+1)/6 - square;
    long b = a/diff;
    return {(b-diff)/2, (b+diff)/2};
}
