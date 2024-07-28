#include <bits/stdc++.h>
using namespace std;


/*
    Alien Dictionary
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language. Note: Many orders may be possible for a particular test case, 
thus you may return any valid order and output will be 1 if the order of string returned by the function is correct 
else 0 denoting incorrect string returned. 

Example 1:
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Example 2:
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders. 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  
the string array dict[], its size N and the integer K as input parameter and returns a string denoting the 
order of characters in the alien language.

Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)
*/

// here we have to observe that somthing before somthing so we can apply topological sort here
// so int k will state no of alphabets of dictionary so we have k nodes in graph
// we can number them in 0 to 4


vector<int> topoSort(int v, vector<int> adj[]){
    int indegree[v] = {0};

    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < v; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto adjacentNode : adj[node]){
            indegree[adjacentNode]--;
            if(indegree[adjacentNode] == 0){
                q.push(adjacentNode);
            }
        }
    }

    return ans;
}


string alianDictionaryOrder(int n, int k, string dict[]){
    vector<int> adj[k];

    for(int i = 0; i < n - 1; i++){
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int m = min(s1.length(), s2.length());

        for(int ptr = 0; ptr < m; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    // now simple topo sort

    vector<int> ans = topoSort(k, adj);

    string res = "";

    for(int i = 0; i < ans.size(); i++){
        res = res + (char)('a' + ans[i]);
    }

    return res;
}


int main(){
    int n = 5;
    int k = 4;
    string dict[] = {"baa","abcd","abca","cab","cad"};

    string ans = alianDictionaryOrder(n, k, dict);

    cout << ans << endl;
    return 0;
}