s1 = "Orchestra"
s2 = "Carthorse"

def levenshtein(s1, s2):
    l1 = len(s1)
    l2 = len(s2)
    A = [[0 for x in range(l2+1)] for y in range(l1+1)]

    for i in range(0, l1+1):
        A[i][0] = i
    for j in range(0, l2+1):
        A[0][j] = j

    for i in range(1, l1+1):
        for j in range(1, l2+1):
            if s1[i-1] == s2[j-1]:
                A[i][j] = A[i-1][j-1]
            else:
                A[i][j] = min(A[i-1][j-1], A[i-1][j], A[i][j-1]) + 1
    return A[i][j]

print levenshtein(s1, s2)