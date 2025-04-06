# leetcode 763. Partition Labels

def partitionLabels(s):
    res = []

    last_index = [0] * 26

    for i, ch in enumerate(s):
        last_index[ord(ch) - ord('a')] = i


    i = 0
    while i < len(s):
        j = last_index[ord(s[i]) - ord('a')]
        k = i + 1
        while k < j:
            j = max(j, last_index[ord(s[k]) - ord('a')])
            k += 1
        res.append(j - i + 1)
        i = j + 1


    return res


s = "ababcbacadefegdehijhklij"
print(partitionLabels(s))
