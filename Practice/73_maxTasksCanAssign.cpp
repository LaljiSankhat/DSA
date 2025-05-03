#include <bits/stdc++.h>
using namespace std;


// leetcode 2071. Maximum Number of Tasks You Can Assign


bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength){
    multiset<int> workerSet;
    int n = workers.size();

    // Get the strongest k workers
    for (int i = n - k; i < n; ++i)
        workerSet.insert(workers[i]);

    // Assign the k hardest tasks
    for (int i = k - 1; i >= 0; --i) {
        int task = tasks[i];

        // Try assigning directly to a strong enough worker
        auto it = workerSet.lower_bound(task);
        if (it != workerSet.end()) {
            workerSet.erase(it);
            continue;
        }

        // Try assigning with a pill: find weakest worker >= task - strength
        if (pills > 0) {
            it = workerSet.lower_bound(task - strength);
            if (it != workerSet.end()) {
                workerSet.erase(it);
                pills--;
                continue;
            }
        }

        return false; // No suitable worker
    }

    return true;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    int n = tasks.size();
    int m = workers.size();

    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int low = 0, high = min(n, m);
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canAssign(mid, tasks, workers, pills, strength)){
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}


int main(){
    vector<int> tasks = {3,2,1};
    vector<int> workers = {0, 3, 3};
    int pills = 1;
    int strength = 1;
    cout << maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}