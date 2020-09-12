// Hotel Bookings Possible
Asked in:  
Goldman Sachs
Microsoft

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size(), m = depart.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int rooms = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(arrive[i] < depart[j]){
            rooms++;
            i++;
        }
        else {
            rooms--;
            j++;
        }
        if(rooms > K)   
            return false;
    }
    return true;
}
