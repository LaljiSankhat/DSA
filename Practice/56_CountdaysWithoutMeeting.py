

# leetcode 3169. Count Days Without Meetings

def countDays(days, meetings):
    # remainingDays = 0
    # meetings = sorted(meetings)
    # remainingDays += meetings[0][0] - 1
    # for i in range(1, len(meetings)):
    #     r = meetings[i][0] - meetings[i - 1][1] - 1
    #     if r > 0:
    #         remainingDays += r
    # remainingDays += days - meetings[-1][1]
    # return remainingDays
    meetings.sort()
    prev_end = 0
    for start, end in meetings:
        start = max(start, prev_end + 1)
        length = end - start + 1
        days -= max(length, 0)
        prev_end = max(prev_end, end)
    return days


days = 57
meetings = [[3,49],[23,44],[21,56],[26,55],[23,52],[2,9],[1,48],[3,31]]

print(sorted(meetings))
print(countDays(days, meetings))