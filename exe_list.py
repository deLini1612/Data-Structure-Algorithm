def split(group, total_exe):
    return {"Vanh":[exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+0*6],
            "Duong": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+1*6], 
            "Hieu": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+2*6], 
            "Linh": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+3*6]}
def show(A: dict):
    for exe in A:
        print ('\t', exe,'\t',A[exe])

def main():
    # group = int(input("Group: "))
    GROUP = 2
    EXE = {"Array": 156, "Backtracking": 16,
           "Binary": 37, "Binary Tree": 54,
           "BST": 16, "Divide & Conquer": 30,
           "Dynamic Programming": 59, "Graphs": 37,
           "Heap": 16, "Linked List": 37, "Matrix": 43,
           "Queue": 26, "Sorting": 47, "Stack": 17,
           "String": 83, "Trie": 9, "Greedy": 7, "Puzzles": 30}
    
    for topic in EXE:
        print(topic)
        show(split(GROUP, EXE[topic]))
        print("================================================")
if __name__ == "__main__":
    main()