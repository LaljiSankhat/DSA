#include <bits/stdc++.h>
using namespace std;


// leetocode 30. Substring with Concatenation of All Words


// this will give TLE for last test case
vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string,int> freq,curr;
    for(string& word: words)
        freq[word]++;
    
    int len = s.size();
    int n = words.size();
    int wordSize = words[0].size();
    int windowSize = wordSize * n;

    vector<int> ans;
    for(int startPos = 0; startPos < wordSize; ++startPos){//Try all starting positions
        int start = startPos;
        do {
            curr = freq;    //Make a copy of freq map to edit
            string currWord;
            bool matched = true;    //presume that match happened
            for(int i = 0; i < n; ++i){   //Find each word
                currWord = s.substr(start + i * wordSize, wordSize); //Extract current word
                if(!curr.count(currWord) or curr[currWord] == 0){ //Match word
                    matched = false;    //current word did not match
                    break;
                }
                curr[currWord]--;           //Remove word after having found
            }
            if(matched == true)               //Found match
                ans.push_back(start);
            start += wordSize;                //Sliding Window
        }while(start + windowSize - 1 < len);     //Bound check
    }
    return ans;
}


// optimized

vector<int> findSubstring2(string s, vector<string>& words) {
    unordered_map<string, int> freq;
    for (string& word : words)
        freq[word]++;

    int len = s.size();
    int n = words.size();
    int wordSize = words[0].size();
    int windowSize = wordSize * n;

    if (len < windowSize) return {};

    vector<int> ans;

    // Try all possible alignments
    for (int offset = 0; offset < wordSize; ++offset) {
        unordered_map<string, int> curr;
        int left = offset, count = 0;

        for (int right = offset; right + wordSize <= len; right += wordSize) {
            string word = s.substr(right, wordSize);

            // If word is part of the pattern
            if (freq.count(word)) {
                curr[word]++;
                count++;

                // Shrink window if word appears too many times
                while (curr[word] > freq[word]) {
                    string leftWord = s.substr(left, wordSize);
                    curr[leftWord]--;
                    left += wordSize;
                    count--;
                }

                // All words matched
                if (count == n) {
                    ans.push_back(left);
                    // Slide window forward
                    string leftWord = s.substr(left, wordSize);
                    curr[leftWord]--;
                    left += wordSize;
                    count--;
                }
            } else {
                // Reset window
                curr.clear();
                count = 0;
                left = right + wordSize;
            }
        }
    }

    return ans;
}




int main(){
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> ans = findSubstring(s, words);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}