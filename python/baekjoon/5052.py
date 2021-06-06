import sys

input = sys.stdin.readline


class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur_node = self.head
        for char in string:
            if char not in cur_node.children:
                cur_node.children[char] = Node(char)
            cur_node = cur_node.children[char]
        cur_node.data = string

    def search(self, string):
        cur_node = self.head
        for char in string:
            cur_node = cur_node.children[char]
        if cur_node.children:
            return False
        else:
            return True


t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    flag = True
    trie = Trie()
    for _ in range(n):
        s = input().rstrip()
        arr.append(s)
        trie.insert(s)

    for string in arr:
        if not trie.search(string):
            flag = False
            break
    if flag:
        print('YES')
    else:
        print('NO')
