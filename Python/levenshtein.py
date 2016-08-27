s1 = "Orchestra"
s2 = "Carthorse"

def levenshtein(s1, s2):
    l1 = len(s1)
    l2 = len(s2)

    A = [[0 for x in range(l2)] for y in range(l1)]

    for i in range(0, l1):
        for j in range(0, l2):
            if s1[i] == s2[j]:
                A[i][j] = 1

    i, j = l1 - 1, l2 - 1
    count = 0
    while (j >= 0 and i >= 0):
        if A[i][j] == 0:
            count += 1
            A[i][j] = 'x'
        if i == 0:
            j -= 1
        elif A[i-1][j] == 1:
            i -= 1
        elif A[i-1][j-1] == 1:
            i -= 1
            j -= 1
        elif A[i][j-1] == 1:
            j -= 1
        else:
            i -= 1
            j -= 1

    for i in range(0, l1):
        print
        for j in range(0, l2):
            print A[i][j],
    print
    return count

print levenshtein(s1, s2)
