
# leetcode 3394. Check if Grid can be Cut into Sections


def checkValidCuts(n, rectangles):
    # extract x and y coordinates
    x = [(r[0], r[2]) for r in rectangles]
    y = [(r[1], r[3]) for r in rectangles]

    x.sort()
    y.sort()

    def count_non_overlapping(intervals):
        count = 0 
        prev_end = -1

        for start, end in intervals:
            if prev_end <= start:
                count += 1
            prev_end = max(end, prev_end)

        return count



    return max(count_non_overlapping(x), count_non_overlapping(y)) >= 3


n = 5
rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
print(checkValidCuts(n, rectangles))