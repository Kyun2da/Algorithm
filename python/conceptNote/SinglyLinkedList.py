# Node 클래스 선언
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


# SinglyLinkedList 클래스 선언
class SinglyLinkedList(object):
    def __init__(self):
        self.head = None
        self.count = 0

    # 연결리스트의 끝에 새로운 노드를 추가한다.
    def append(self, node):
        if self.head is None:
            self.head = node
        else:
            cur = self.head
            while cur.next is not None:
                cur = cur.next
            cur.next = node

    # 연결리스트의 첫번째 인덱스를 리턴
    def getdataIndex(self, data):
        curn = self.head
        idx = 0
        while curn:
            if curn.data == data:
                return idx
            curn = curn.next
            idx += 1
        return -1

    # 주어진 인덱스에 새로운 노드를 삽입한다.
    def insertNodeAtIndex(self, idx, node):
        curn = self.head
        prevn = None
        cur_i = 0

        if idx == 0:
            if self.head:
                nextn = self.head
                self.head = node
                self.head.next = nextn
            else:
                self.head = node
        else:
            while cur_i < idx:
                if curn:
                    prevn = curn
                    curn = curn.next
                else:
                    break
                cur_i += 1
            if cur_i == idx:
                node.next = curn
                prevn.next = node
            else:
                return -1

    # 주어진 데이터 전에 새로운 노드를 삽입한다.
    def insertNodeAtData(self, data, node):
        index = self.getdataIndex(data)
        if 0 <= index:
            self.insertNodeAtIndex(index, node)
        else:
            return -1

    # 주어진 인덱스에 데이터를 삭제한다
    def deleteAtIndex(self, idx):
        curn_i = 0
        curn = self.head
        prevn = None
        nextn = self.head.next
        if idx == 0:
            self.head = nextn
        else:
            while curn_i < idx:
                if curn.next:
                    prevn = curn
                    curn = nextn
                    nextn = nextn.next
                else:
                    break
                curn_i += 1
            if curn_i == idx:
                prevn.next = nextn
            else:
                return -1

    # 링크리스트를 비운다
    def clear(self):
        self.head = None

    # 출력
    def print(self):
        curn = self.head
        string = ""
        while curn:
            string += str(curn.data)
            if curn.next:
                string += "->"
            curn = curn.next
        print(string)


if __name__ == "__main__":
    sl = SinglyLinkedList()
    sl.append(Node(1))
    sl.append(Node(2))
    sl.append(Node(3))
    sl.append(Node(5))
    sl.insertNodeAtIndex(3, Node(4))
    sl.print()
    print(sl.getdataIndex(1))
    print(sl.getdataIndex(2))
    print(sl.getdataIndex(3))
    print(sl.getdataIndex(4))
    print(sl.getdataIndex(5))
    sl.insertNodeAtData(1, Node(0))
    sl.print()
