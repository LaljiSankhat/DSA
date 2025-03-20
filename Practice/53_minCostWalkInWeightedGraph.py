
# leetcode 3108. Minimum Cost Walk in Weighted Graph

class UnionFind:

    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        # find the parent of x
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x: int, y: int) -> bool:
        # connect the edge
        x = self.find(x)
        y = self.find(y)

        if x != y: 
            if self.size[x] < self.size[y]:
                self.parent[x] = y
                self.size[y] += self.size[x]
            else:
                self.parent[y] = x
                self.size[x] += self.size[y]
            return True
        return False
    
def minimumCost(n, edges, query):
    uf = UnionFind(n)

    for u, v, w in edges:
        uf.union(u, v)

    # now getting cost of each component
    component_cost = {} # root -> cost

    for u, v, w in edges:
        root = uf.find(u)
        if root not in component_cost:
            component_cost[root] = w
        else:
            component_cost[root] &= w

    # now queries 
    res = []

    for src, dest in query:
        r1, r2 = uf.find(src), uf.find(dest)
        if r1 != r2:
            res.append(-1)
        else:
            res.append(component_cost[r1])

    return res

n = 5
edges = [[0,1,7],[1,3,7],[1,2,1]]
query = [[0,3],[3,4]]

print(minimumCost(n, edges, query))

