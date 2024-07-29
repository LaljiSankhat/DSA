#include <bits/stdc++.h>
using namespace std;


/*
    126. Word Ladder II
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of 
words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation 
sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be 
returned as a list of the words [beginWord, s1, s2, ..., sk]. 

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/

// so have to return the path by we reach to endWord from startWord

vector<vector<string>> wordLadderII(string startWord, string endWord, vector<string> wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});
    // to store which words we are usign at level so we can remove after all work has been done 
    // of that word at that level
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // if we get new level then we erase words that has been used previos level
        if(vec.size() > level){
            level++;
            for(auto it : usedOnLevel){
                st.erase(it);
            }
        }

        string word = vec.back();

        if(word == endWord){
            // the first sequence we get
            if(ans.size() == 0){
                ans.push_back(vec);
            } else if(ans[0].size() == vec.size()){ // all sequences which are same size as minimum sequence
                ans.push_back(vec);
            }
        }

        // trying all possible word and take which are possible or in the wordList
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // exist
                if(st.count(word) > 0){ // if it is in the wordList
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited
                    usedOnLevel.push_back(word);
                    vec.pop_back(); // backtraking 
                }
            }
            word[i] = original;
        }
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