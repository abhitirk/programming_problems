def get_products_of_all_ints_except_at_index(A):
    # write the body of your function here
    n = len(A)
    B = [None] * n
    for i in xrange(0, n):
        prod = 1
        for j in xrange(0, n):
            if(i!=j):
                prod *= A[j]
        B[i] = prod
    return B

print get_products_of_all_ints_except_at_index([0,7,3,4])
