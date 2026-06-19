#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.length();
    vector<int> lps(m, 0); // lps[0] is always 0 because a single char has no proper prefix
    
    int len = 0; // Length of previous longest prefix suffix
    int i = 1;   // Start evaluating from the second character

    while (i < m) {
        if (pat[i] == pat[len]) {
            // Rule 1: Match
            len++;
            lps[i] = len;
            i++;
        } else { 
            // Mismatch
            if (len != 0) {
                // Rule 3: Fallback using the array itself
                len = lps[len - 1]; 
                // Notice we do NOT increment i here. We re-test the same i against the new len.
            } else {
                // Rule 2: Ground zero
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}