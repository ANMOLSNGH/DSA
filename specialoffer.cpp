#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<vector<int>,int>mpp;
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mpp.count(needs)) return mpp[needs];
        int min_cost = 0;

        for(int i = 0;i<needs.size();i++) {
            min_cost += price[i]*needs[i];
        }

        for(auto &offer:special) {
            vector<int>remaining = needs;
            bool isvalid = true;
            for(int j = 0;j<needs.size();j++) {
                if(offer[j]>needs[j]) {
                    isvalid = false;
                    break;
                }
                remaining[j] -= offer[j];
            }
            if(isvalid) {
                int min_cost_so_far = offer.back() + dfs(price,special,remaining);
                min_cost = min(min_cost,min_cost_so_far);
            }
        }
        return  mpp[needs] = min_cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
          return dfs(price,special,needs);
    }
};