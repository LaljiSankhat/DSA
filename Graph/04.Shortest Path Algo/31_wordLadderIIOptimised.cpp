#include <bits/stdc++.h>
using namespace std;


// previos solution will give the memory limit excceded(MLE) or Time Limit Exceded(TLE) 
// for large cases so we have to optimise it 

// step 1 : apply wordLadder 1 and store the word with level where it is occured in map
// s2 : now backTrack in map 
// in backtraking we put only that word which has low then our currnt word


// declare globally
vector<vector<string>> ans;
unordered_map<string, int> mpp;
string b;

void dfs(string word, vector<string> &seq){
    if(word == b){
        reverse(seq.begin(), seq.end()); // because ans is stored end to begin 
        ans.push_back(seq);
        // now we have to further reverse the seq becuase we are doing backtracking so seq is disturbed by
        // reversing so we have to convert it into original seq
        reverse(seq.begin(), seq.end());
        return;
    }

    int sz = word.size();

    int steps = mpp[word];
    for(int i = 0; i < sz; i++){
        char original = word[i];
        for(char c = 'a'; c <= 'z'; c++){
            word[i] = c;
            if(mpp.find(word) != mpp.end() && mpp[word] == steps - 1){
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back(); // backtrak
            }
        }
        word[i] = original;
    } 
}


vector<vector<string>> wordLadderII(string startWord, string endWord, vector<string> wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    queue<string> q;
    q.push(startWord);
    b = startWord;
    

    mpp[startWord] = 1;
    int sz = startWord.size();

    while(!q.empty()){
        string word = q.front();
        int steps = mpp[word];
        q.pop();

        if(word == endWord) break; // to optimise

        for(int i = 0; i < sz; i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(st.count(word) > 0){
                    q.push(word);
                    st.erase(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        } 
    }

    // now we need to backtrack
    if(mpp.find(endWord) != mpp.end()){
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }

    return ans;
}

int main(){
    string startWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};

    vector<vector<string>> ans = wordLadderII(startWord, endWord, wordList);

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}