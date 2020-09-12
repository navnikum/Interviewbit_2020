// Largest Number
Asked in:  
Amazon
Goldman Sachs
Microsoft

bool custom_sort(const string &a, const string &b){
    return a+b > b+a;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> s;
    int i;
    for(i = 0; i < A.size(); i++)
        s.push_back(to_string(A[i]));
    sort(s.begin(), s.end(), custom_sort);
    string ans = "";
    for(i = 0; i < A.size(); i++)
        ans+= s[i];
        
    for(i = 0; i < ans.size(); i++)
        if(ans[i] != '0')
            return ans.substr(i);
    if(i == ans.size() && ans[ans.size()-1] == '0')
        return "0";
    return ans;
}
