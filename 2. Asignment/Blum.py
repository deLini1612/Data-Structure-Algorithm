def isPrime(n):
    """Function to check if n is a prime number"""
    if n < 2:
        return 0
    if n == 2:
        return 1
    for i in range (2, n):
        if n % i == 0:
            return 0
    return 1

def isBlum(n):
    """Function to check if n is a blum number"""
    if n < 6:
        return 0
    for i in range (2, n):
        if n % i == 0 and isPrime(i) and isPrime(int(n/i)) and i != n/i:
            print("{} = {} * {}".format(n,i,int(n/i)))
            return 1
    return 0

def blumInList(A):
    """Function print all blum number in given list A"""
    for x in A:
        isBlum(x)


def blumInRange(n):
    """Function print all blum number < n"""
    for x in range(n):
        isBlum(x)

def main():
    n = 161
    A = [1, 2, 4, 5, 7, 8, 9, 12, 4, 6423, 64, 62, 375, 23, 67, 2, 17074]
    print("Exe1: Find blum number in given list ==========")
    blumInList(A)
    print("\nExe2: Find blum number < n ====================")
    blumInRange(n)

if __name__ == '__main__':
    main()