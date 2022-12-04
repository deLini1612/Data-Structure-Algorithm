"""Declare plus (+) operator for 2 polynomials"""

def addPoly(P1, P2):
    """Fuction to add 2 polynomial P1 and P2"""
    p = P2
    while p:
        P1 = addDec(P1, p.coef, p.exp)
        p = p.next
    return P1

from Poly import *
def main():
    print("================Enter the first polynomial================")
    P1 = createPoly()
    print("================Enter the first polynomial================")
    P2 = createPoly()
    print("P1 =", end=" ")
    printPoly(P1)
    print("P2 =", end=" ")
    printPoly(P2)
    print("P1 + P2 =", end=" ")
    printPoly(addPoly(P1, P2))

if __name__ == "__main__":
    main()