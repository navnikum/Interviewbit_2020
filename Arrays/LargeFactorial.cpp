// Large Factorial
Problem Constraints
                   1 <= A <= 100


string multiply(string l1, string l2){
    int n1 = l1.size(), n2 = l2.size();
    string res(n1+n2, '0');
    for(int i = n1-1; i>=0; i--){
        for(int j = n2-1; j>=0; j--){
            int p = ((l1[i]-'0')*(l2[j]-'0')) + (res[i+j+1]-'0');
            res[i+j+1] = p%10 +'0';
            res[i+j] += p/10;
        }
    }
    for(int i = 0; i<res.size(); i++)
        if(res[i]!='0')
            return res.substr(i);

    return "0";
}

string Solution::solve(int A) {
    string s = "1";
    for(int i = 2; i<= A; i++){
        s = multiply(s, to_string(i));
    }
    return s;
}
