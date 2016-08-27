A = [9, 9, 7]

def increment(A):
    n = len(A) - 1
    if A[0] == 9:
        digit = A[n]
        A.append(digit)
        for i in xrange(n, 0, -1):
            A[i] = A[i-1]
        A[0] = 0
        n += 1
    print A
    while(n >= 0):
        if A[n] < 9:
            A[n] += 1
            break
        else:
            A[n] = 0
            n -= 1
    print A

increment(A)
