
# leetcode 2685. Count the Number of Complete Components

class UnionFind:

    def __init__(self, n):
        self.size = [1] * n
        self.parent = list(range(n))

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x != y:
            if self.size[x] > self.size[y]:
                self.parent[y] = x
                self.size[x] += self.size[y]
            else:
                self.parent[x] = y
                self.size[y] += self.size[x]
            return True
        return False
    


def countCompleteComponents(n, edges):

    res = 0

    uf = UnionFind(n)

    noOfEdges = [0] * n

    for u, v in edges:
        uf.union(u, v)
        noOfEdges[u] += 1
        noOfEdges[v] += 1

    component_edges = {}

    for u in range(n):
        p = uf.find(u)
        if p not in component_edges:
            component_edges[p] = list([noOfEdges[u], 1])  # [edges, nodes]
        else:
            component_edges[p][0] += noOfEdges[u]
            component_edges[p][1] += 1
    
    for root, l in component_edges.items():
        e = l[0]
        nodes = l[1]
        if e // 2 == (nodes * (nodes - 1)) // 2:
            res += 1


    return res


n = 6
edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]

print(countCompleteComponents(n, edges))