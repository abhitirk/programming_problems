# Compute number of ways to traverse a 2D array

def num_ways_traverse(n, m):
    A = [[0 for x in range(m)] for y in range(n)]
    A[0][0] = 1
    for i in range(1, m):
        A[0][i] = 1

    for i in range(1, n):
        A[i][0] = 1

    for i in range(1, n):
        for j in range(1, m):
            A[i][j] =  A[i][j-1] + A[i-1][j]

    return A[n-1][m-1]

print num_ways_traverse(5, 6)
