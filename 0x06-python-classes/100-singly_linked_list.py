class Node:
    """
    Represents a node of a singly linked list.

    Attributes:
        __data (int): The data stored in the node.
        __next_node (Node): The reference to the next node.
    """

    def __init__(self, data, next_node=None):
        """
        Initializes a node with the given data and next_node.

        Parameters:
            data (int): The data to be stored in the node.
            next_node (Node): The reference to the next node. Defaults to None.
        """
        self.data = data
        self.next_node = next_node

    @property
    def data(self):
        """Getter method to retrieve the data of the node."""
        return self.__data

    @data.setter
    def data(self, value):
        """
        Setter method to set the data of the node.

        Parameters:
            value (int): The data to be set.

        Raises:
            TypeError: If value is not an integer.
        """
        if not isinstance(value, int):
            raise TypeError("data must be an integer")
        self.__data = value

    @property
    def next_node(self):
        """Getter method to retrieve the reference to the next node."""
        return self.__next_node

    @next_node.setter
    def next_node(self, value):
        """
        Setter method to set the reference to the next node.

        Parameters:
            value (Node or None): The reference to the next node.

        Raises:
            TypeError: If value is not a Node object or None.
        """
        if value is not None and not isinstance(value, Node):
            raise TypeError("next_node must be a Node object")
        self.__next_node = value


class SinglyLinkedList:
    """
    Represents a singly linked list.

    Attributes:
        head (Node): The head node of the list.
    """

    def __init__(self):
        """Initializes an empty singly linked list."""
        self.head = None

    def sorted_insert(self, value):
        """
        Inserts a new Node into the correct sorted position in the list (increasing order).

        Parameters:
            value (int): The value to be inserted into the list.
        """
        new_node = Node(value)
        if self.head is None or self.head.data >= value:
            new_node.next_node = self.head
            self.head = new_node
        else:
            current = self.head
            while current.next_node is not None and current.next_node.data < value:
                current = current.next_node
            new_node.next_node = current.next_node
            current.next_node = new_node

    def __str__(self):
        """Returns a string representation of the singly linked list."""
        if self.head is None:
            return "Empty list"
        else:
            result = ""
            current = self.head
            while current is not None:
                result += str(current.data) + "\n"
                current = current.next_node
            return result.strip()
