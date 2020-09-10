// N/3 Repeat Number
Asked in:  
Google
// count all occurence in count array in O(n^2) or O(nlogn)
// Time complexity : O(n)
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int c1 = 0, c2 = 0, x1 = -1, x2 = -1;
    for(auto x:A){
        if(x1 == x)  c1++;
        else if(x2 == x)    c2++;
        else if(c1 == 0)    c1++, x1 = x;
        else if(c2 == 0)    c2++, x2 = x;
        else    c1--, c2--;
    }
    // x1, x2 are recorded count their occurrence
    c1 = 0, c2 = 0;
    for(auto x:A)
        if(x1 == x) c1++;
        else if(x2 == x)    c2++;
        
    return c1 > n/3 ? x1 : ((c2 > n/3) ? x2 : -1);
}
