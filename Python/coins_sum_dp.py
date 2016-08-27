V = [2, 3, 5]

def minimum_no_coins(sum, V):
    n = len(V)
    s, h = sum+1, n
    A = [[0 for x in range(s)] for y in range(h)]

    for i in range(0, n):
        A[i][0] = 0
        print "\n %d" % A[i][0],
        for j in range(1, s):
            if j - V[i] >= 0 and A[i][j - V[i]] != -1:
                A[i][j] = A[i][j - V[i]] + 1
            elif i != 0:
                A[i][j] = A[i - 1][j]
            else:
                A[i][j] = -1
            print A[i][j],
        print
    return A[i][j]


print minimum_no_coins(10, V)
