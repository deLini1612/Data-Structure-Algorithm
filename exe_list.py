def split(group, total_exe):
    return {"Vanh":[exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+0*6],
            "Duong": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+1*6], 
            "Hieu": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+2*6], 
            "Linh": [exe for exe in range(1, total_exe+1) if exe%24 == (group%6)+3*6]}


def main():
    # group = int(input("Group: "))
    GROUP = 2
    total_exe = int(input("Number of exercises: "))
    for exe in split(GROUP, total_exe):
        print (exe,'\t',split(GROUP, total_exe)[exe])


if __name__ == "__main__":
    main()