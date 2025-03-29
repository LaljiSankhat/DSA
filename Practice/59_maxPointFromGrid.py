# 2503. Maximum Number of Points From Grid Queries

from heapq import heappop, heappush


def maxPoints(grid, queries):
    ROWS, COLS = len(grid), len(grid[0])

    q = [(n, i) for i, n in enumerate(queries)]
    q.sort()

    min_heap = [(grid[0][0], 0, 0)] # val, r, c
    res = [0] * len(queries)
    visit = set([(0, 0)])
    points = 0

    for limit, index in q:
        while min_heap and min_heap[0][0] < limit:
            val, r, c = heappop(min_heap)
            points += 1
            neighbors = [[r + 1, c], [r - 1, c], [r, c + 1], [r, c - 1]]
            for nr, nc in neighbors:
                if ( 0 <= nr < ROWS and 0 <= nc < COLS and (nr, nc) not in visit):
                    heappush(min_heap, (grid[nr][nc], nr, nc))
                    visit.add((nr, nc))
        res[index] = points
    return res


grid = [[1,2,3],[2,5,7],[3,5,1]]
queries = [5,6,2]

print(maxPoints(grid, queries))