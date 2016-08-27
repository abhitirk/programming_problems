grid = [[1, 2, 3],[3, 4, 5], [5, 6, 7]]
pattern_array = [1, 2, 4, 5]

def pattern_in_grid(grid, pattern_array):
    pattern_array_size = len(pattern_array)
    grid_rows = len(grid)
    grid_cols = len(grid[0])
    size = grid_rows * grid_cols
    A = [[-1 for x in range(size)] for y in range(pattern_array_size)]
    B = [[-1 for x in range(size)] for y in range(pattern_array_size)]

    y = 0
    for j in xrange(0, grid_rows):
        for k in xrange(0, grid_cols):
            if grid[j][k] == pattern_array[0]:
                A[0][y] = j
                B[0][y] = k
                y += 1

    for i in xrange(1, pattern_array_size):
        j = 0
        k = 0
        while (A[i-1][j] != -1):
            x = A[i-1][j]
            y = B[i-1][j]
            if x - 1 >= 0:
                if grid[x-1][y] == pattern_array[i]:
                    A[i][k] = x - 1
                    B[i][k] = y
                    k += 1
            if x + 1 < grid_rows:
                if grid[x+1][y] == pattern_array[i]:
                    A[i][k] = x + 1
                    B[i][k] = y
                    k += 1
            if y - 1 >= 0:
                if grid[x][y-1] == pattern_array[i]:
                    A[i][k] = x
                    B[i][k] = y - 1
                    k += 1
            if y + 1 < grid_cols:
                if grid[x][y+1] == pattern_array[i]:
                    A[i][k] = x
                    B[i][k] = y + 1
                    k += 1
            j += 1

    if A[pattern_array_size-1][0] != -1:
        print "Pattern found"
    else:
        print "Pattern not found"

pattern_in_grid(grid, pattern_array)

