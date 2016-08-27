stock_prices_yesterday = [10, 7, 5, 4, 3, 1]

def get_max_profit(A):
    n = len(A)
    minval, maxval = A[0], float("-inf")
    for i in range(0, n-1):
        print maxval
        if A[i] < minval:
            minval = A[i]
        if A[i+1] - minval > maxval:
            maxval = A[i+1] - minval
    return maxval
        

print get_max_profit(stock_prices_yesterday)