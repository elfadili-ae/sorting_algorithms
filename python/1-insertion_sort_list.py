#!/usr/bin/python3

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
            new_node.prev = current

    def prepend(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node

    def delete(self, key):
        current = self.head
        while current:
            if current.data == key:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next

                if current.next:
                    current.next.prev = current.prev

                return
            current = current.next

    def display_forward(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

    def display_backward(self):
        current = self.head
        while current and current.next:
            current = current.next
        while current:
            print(current.data, end=" ")
            current = current.prev
        print()

#--------------------

def sort_backward(list, node):
    if node is None or node.prev is None:
        return

    if node.data < node.prev.data:
        tmp = node.prev
        tmp.next = node.next
        node.prev = tmp.prev
        node.next = tmp
        tmp.prev = node
        tmp.next.prev = tmp
        if node.prev:
                node.prev.next = node
        else:
            list.head = node

        list.display_forward()
        if node.prev:
            sort_backward(list, node)
    else:
        return

def insertion_sort_list(list):
    """sort a doubly linked list using Insertion sort algorithm

    args:
        list: doubly linked list
    """

    if list is None or list.head.next is None:
        return

    current = list.head
    while current.next:
        if current.data > current.next.data:
            tmp = current.next
            current.next.prev = current.prev
            current.next = tmp.next
            current.prev = tmp
            tmp.next = current
            if tmp.prev:
                tmp.prev.next = tmp
            else:
                list.head = tmp

            if current.next:
                current.next.prev = current

            list.display_forward()
            sort_backward(list, tmp)
        else:
            current = current.next

if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.append(5)
    dll.append(4)
    dll.append(3)
    dll.append(2)
    dll.append(1)

    dll.display_forward()
    print()
    
    insertion_sort_list(dll)

    print()
    dll.display_forward()
