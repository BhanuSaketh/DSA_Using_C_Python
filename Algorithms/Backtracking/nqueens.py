def is_safe(Q, row, col, n):
    for i in range(row):
        if Q[i][col] == 1:
            return False
    i, j = row, col
    while i >= 0 and j >= 0:
        if Q[i][j] == 1:
            return False
        i -= 1
        j -= 1
    i, j = row, col
    while i >= 0 and j < n:
        if Q[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True

def nqueens(Q, n, row):
    if row == n:
        for r in Q:
            print(" ".join(str(x) for x in r))
        print("\n")
        return

    for col in range(n):
        if is_safe(Q, row, col, n):
            Q[row][col] = 1
            nqueens(Q, n, row + 1)
            Q[row][col] = 0  # Backtrack

n = int(input("Enter No of Queens: "))
Q = [[0] * n for _ in range(n)]
nqueens(Q, n, 0)
