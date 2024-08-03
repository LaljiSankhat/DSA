#include <bits/stdc++.h>
using namespace std;


/*
    721. Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] 
is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some 
common email to both accounts. Note that even if two accounts have the same name, they may belong to different 
people as people could have the same name. A person can have any number of accounts initially, but all of their 
accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is 
the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
            ["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
*/

// so here given the account holder and there emails
// if we saw two name are same and atleast one email both of them name are same then we can say that both 
// are same person so we have to merge them in to one person

class DisjoinSet{
    vector<int> rank, parent, size;

    public:
    DisjoinSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else { // rank are same
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    
    // so here we are doing path compression so rank will not tell about height so why not we use size istead of rank

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else { // if it is greater or same in both case we will be attach and increase size 
            // in same case we can attach any to any so no need for extra case
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        
    }
};


vector<vector<string>> accountMerge(vector<vector<string>> &accounts){
    int n = accounts.size();

    DisjoinSet ds(n);

    unordered_map<string, int> mapMailNode;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string mail = accounts[i][j];
            // not contains
            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            } else { // if contains then we union both the nodes
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    // now merge the mails to thier ultimate parents
    vector<string> mergedMail[n];
    for(auto it : mapMailNode){
        string mail = it.first;
        int node = ds.findUPar(it.second);

        mergedMail[node].push_back(mail);
    }

    // now create the answer
    vector<vector<string>> ans;

    for(int i = 0; i < n; i++){
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        // now put all elem of mergedMail[i] into temp
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    return ans;
}


int main(){
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com","johnnybravo@mail.com"}
    };

    vector<vector<string>> ans = accountMerge(accounts);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}