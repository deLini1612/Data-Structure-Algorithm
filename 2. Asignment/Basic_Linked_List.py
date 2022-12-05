class Date:
    """day,month,year"""
    def __init__(self, dd: int, mm: int, yy: int):
        self.dd = int(dd)
        self.mm = int(mm)
        self.yy = int(yy)
    def toStringNgay(self):
        """Save day in string format dd/mm/yy"""
        res = str(self.dd) + "/" + str(self.mm) + "/" + str(self.yy)
        return res
    
class Student:
    """A student"""
    def __init__(self, ID: str, name: str, sex: str, birth: Date, address: str, s_class: str, major: str):
        self.ID = int(ID)
        self.name = name
        self.sex = sex
        self.birth = birth
        self.address = address
        self.s_class = s_class
        self.major = major

class Node:
    """A linked list node"""
    def __init__(self, std = None, next = None):
        self.std = std
        self.next = next

def addStudent(head, std: Student):
    """Add a student to a sorted list of student (in increasing order of ID) """
    temp = Node()
    current = temp
    element = Node(std)

    if head is None:
        head = element
        return head
    else:
        temp.next = head
        """Find the node having smaller ID"""
        while current.next and current.next.std.ID < element.std.ID:
            current = current.next
        element.next = current.next
        current.next = element
    return temp.next

def createListStudent():
    """Create a list of student with input from terminal"""
    n = int(input("Number of students:"))
    head = None
    for i in range(n):
        print("===========Enter student {} information===========".format(i+1))
        ID = input("Ma so SV: ")
        name = input("Ho va ten: ")
        sex = input("Gioi tinh: ")
        ngay, thang, nam = input("Ngay sinh (dd/mm/yy): ").split("/")
        birth = Date(ngay, thang, nam)
        address = input("Dia chi: ")
        s_class = input("Lop: ")
        major = input("Khoa: ")
        std = Student(ID, name, sex, birth, address, s_class, major)
        head = addStudent(head, std)
    return head

def PrintStudent(std):
    """Print data of a student"""
    row_format ="{:<9} {:<25} {:<5} {:<15} {:<15} {:<7} {:<5}"
    data = []
    data.append(std.ID)
    data.append(std.name)
    data.append(std.sex)
    data.append(std.birth.toStringNgay())
    data.append(std.address)
    data.append(std.s_class)
    data.append(std.major)
    print(row_format.format(*data))

def printList(head):
    """Print list of students"""
    p = head
    row_format ="{:<9} {:<25} {:<5} {:<15} {:<15} {:<7} {:<5}"
    properties = ["ID", "Name", "Sex", "Birth", "Address", "Class", "Major"]
    print(row_format.format(*properties))
    while p:
        PrintStudent(p.std)
        p = p.next

def dupBirth(head):
    """Return a list of duplicated birth"""
    list_of_birth = []
    dup = []
    p = head
    while p:
        if p.std.birth.toStringNgay() not in list_of_birth:
            list_of_birth.append(p.std.birth.toStringNgay())
        elif p.std.birth.toStringNgay() not in dup:
            dup.append(p.std.birth.toStringNgay())
        p = p.next
    return dup

def printDupBirth(head):
    dup = dupBirth(head)
    if len(dup) == 0:
        print("There is no student has the same date of birth")
        return -1

    row_format ="{:<9} {:<25} {:<5} {:<15} {:<15} {:<7} {:<5}"
    properties = ["ID", "Name", "Sex", "Birth", "Address", "Class", "Major"]
    print(row_format.format(*properties))

    for i in range(len(dup)):
        p = head
        while p:
            if p.std.birth.toStringNgay() == dup[i]:
                PrintStudent(p.std)
            p = p.next
    
def delDupBirth(head):
    """Delete students have duplicate birth from the list"""
    if head is None:
        return None
    dup = dupBirth(head)
    if len(dup) == 0:
        return head
    p = head
    while p:
        if p.next.std.birth.toStringNgay() in dup:
            if p.next.next:
                p.next = p.next.next
            else:
                p.next = None
                break
        else:
            p = p.next
    if head.std.birth.toStringNgay() in dup:
        head = head.next
    return head

def main():
    head = createListStudent()
    print("\n"+"========List of student sorted by ID"+"========")
    printList(head)
    print("\n"+"========List of student have same birth"+"========")
    printDupBirth(head)
    
    head = delDupBirth(head)
    print("\n"+"========List of student after remove duplicated birth"+"========")
    printList(head)

if __name__ == "__main__":
    main()