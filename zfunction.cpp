#include<bits/stdc++.h>
using namespace std;

vector<int> zfunct(string s) {
    int n = s.size();
    int l = 0;
    int r = 0;
    vector<int>z(n,0);
    for(int i = 1;i<n;i++) {
        if(i<r) {
            z[i] = z[i-l];
    
        if(i+z[i]>r) {
            z[i] = r-i;
        }
    }
        while(i+z[i]<n&&(s[z[i]]==s[z[i]+i])) z[i]++;
        if(z[i] + i>r) {
            l = i;
            r = i + z[i];    
        }
   }
   return z;
}

int main() {
    string s;
    string p;
     cin >> s >> p;
    int n = s.size();
    string dummy  = s + '$' + p;
	vector<int> z = zfunct(dummy);
    vector<int>ans;
	for(int i = 0;i<z.size();i++) {
        if(z[i]==n) ans.push_back(i-(n+1));
    }
    for(int i = 1;i<ans.size();i++) cout<< ans[i] << " ";
	cout << endl;
	return 0;
}