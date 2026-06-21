#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&pages,int m,int mid) {
    int people  = 0;
    int sum = 0;
    int i = 0;
    int n = pages.size();
    while(i<n) {
        if(pages[i]>mid) return false;
        if(sum+pages[i]>mid) {
           people++;
           sum = 0;
           i--;
        } 
        else if(sum+pages[i]==mid) {
            people++;
            sum = 0;
        }
        else {
            sum += pages[i];
        }
        i++;
    }
    if(sum>0) people++;

    return people<=m;
}     
int allocatebooks(vector<int>&pages,int m,int n) {
   int low = *max_element(pages.begin(),pages.end());
   int high = accumulate(pages.begin(),pages.end(),0);
   int res = -1;
   while(low<=high){
     int mid = low + (high-low)/2;
     if(isvalid(pages,m,mid)) {
        res = mid;
        high = mid-1;
     }
     else low = mid +1;
   }
   return res;
}

int main() {
    int n;
    int m;
    cout << "ENter n and m" << "\n";
    cin >> n >> m;
    vector<int>nums(n);
    cout << "Enter pages of each books" << "\n";
    for(int i = 0;i<n;i++) cin >> nums[i];
    int val = allocatebooks(nums,m,n);
    cout << "Maximum minimum page allocated are" << " " << val;
    return 0;

}