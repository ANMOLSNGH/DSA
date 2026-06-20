#include <iostream>
#include <string>

using namespace std;

// 'd' is the number of characters in the input alphabet (ASCII)
#define d 256

void rabinKarpSearch(string pattern, string text, int q) {
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the current text window
    int h = 1;

    // Calculate the value of h: pow(d, m-1) % q
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the initial hash value of the pattern and the first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one character at a time
    for (i = 0; i <= n - m; i++) {
        
        // If the hash values match, verify the characters exactly
        if (p == t) {
            bool match = true;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            // If the hash matched and all characters matched, we found the pattern
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            // Remove the leading digit, add the trailing digit
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // In C++, the modulo operator can return negative values for negative dividends.
            // We convert it to a positive equivalent here.
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    
    // A prime number used to evaluate the hash to prevent overflow
    int q = 101; 
    
    rabinKarpSearch(pattern, text, q);
    
    return 0;
}