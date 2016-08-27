# Reorder entries of an array so that even numbers appear first, without changing the order in which they appear

def reorder_array(A):
    n = len(A)
    for i in xrange(0, n):
        print i
        if (A[i] % 2 != 0):
            flag = 0
            for j in xrange(i+1, n):
                if (A[j] % 2 == 0):
                    temp = A[j]
                    flag = 1
                    break
            if flag == 0:
                break
            for k in xrange(j, i, -1):
                A[k] = A[k-1]
            A[i] = temp

    return A

A = [1, 3, 2, 5, 8, 7, 9, 4, 6]
print reorder_array(A)
