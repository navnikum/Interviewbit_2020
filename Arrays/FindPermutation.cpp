// Find Permutation
Asked in:  
Goldman Sachs
Amazon

// Using stack
vector<int> Solution::findPerm(const string A, int B) {
    // len(A) = B-1
    vector<int> v;
    stack<int> s;
    for(int i = 0; i <= A.size(); i++){
        s.push(i+1);
        if(i == A.size() || A[i] == 'I'){
            while(!s.empty()){
                v.push_back(s.top());
                s.pop();
            }
        }
    }
    return v;
}

// Using small and big two pointer
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    vector<int> v;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(A[i]=='I') 
            v.push_back(cnt++);
        else 
            v.push_back(B--);
    }
    v.push_back(cnt);
    return v;
}
