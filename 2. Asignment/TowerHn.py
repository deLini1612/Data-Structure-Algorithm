""" Hanoi Tower Problem
Given n dishes in A, 3 tower A, B, C. Move dishes from A to C"""

def TowerHN(n, start, others, end):
    """Function to move n dishes from start to end"""
    if n==1:
        print(start, "--->", end)
        return
    TowerHN(n - 1, start, end, others)
    TowerHN(1, start, others, end)
    TowerHN(n - 1, others, start, end)

def main():
    n = int(input("Enter n: "))
    TowerHN(n, "A", "B", "C")

if __name__ == '__main__':
    main()