#include <bits/stdc++.h>
using namespace std;

void prefix_function(string s, int* pi) {
    pi[0] = 0;
    int j = 0, n = s.size();
    for (int i = 1; i < n; i++) {
        j = pi[i-1];
        while (j && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}
int main() {
	string p, t;
	cin >> p >> t;
    int pi[100005];
    prefix_function(p, pi); 
    int j = 0, lp = p.size(), cnt = 0;
    for(int i = 0; i < t.size(); i++) {
        while(j && t[i] != p[j])
            j = pi[j-1];
        if(t[i] == p[j])
            j++;
        if(j == lp){
            j = pi[j-1];
            cnt++; // idx of t of patr begin = i-lp+1
        }
    }
	cout << cnt << endl;		
}

// Exercise:
https://www.spoj.com/problems/NAJPF/
#include <bits/stdc++.h>
using namespace std;

void prefix_function(string s, int* pi){
	pi[0] = 0;
	int j = 0;
	for(int i = 1; i < s.size(); i++){
		j = pi[i-1];
		while(j && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
}

int main() {
	int t; cin>>t;
	while(t--){
		int pi[1000005];
		string p, t;
		cin>> t>> p;
		vector<int> idx;
		prefix_function(p, pi);
		int j=0, lp = p.size(), cnt = 0;
		for(int i = 0; i < t.size(); i++){
			while(j && t[i] != p[j])
				j = pi[j-1];
			if(t[i] == p[j])
				j++;
			if(j == lp){
			        idx.push_back(i-j+2);
			        cnt++;
			        j = p[j-1];
			}
		}
		if(cnt == 0)
		    cout<<"Not Found";
		else{
		    cout<< cnt<<endl;
		    for(auto x:idx)
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
