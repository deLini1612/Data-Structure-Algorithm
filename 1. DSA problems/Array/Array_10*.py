def merge(X: list[int], Y: list[int]) -> [list, list]:
    n = len(X)
    m = len(Y)
    for i in range(n):
        if X[i] > Y[0]:
            temp = Y[0]
            Y[0] = X[i]
            X[i] = temp
        
        first = Y[0]
        j=1
        while j < m and first > Y[j]:
            Y[j-1] = Y[j]
            j = j + 1
        Y[j-1] = first
    return [X, Y]

def main():
    X = [ 1, 4, 8, 12, 19 ]
    Y = [ 3, 5, 9, 10, 21, 30 ]
    print("After merged: X = {} and Y = {}".format(*merge(X, Y)))

if __name__ == '__main__':
    main()