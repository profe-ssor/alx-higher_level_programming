class Square:
    """
    Represents a square.

    Attributes:
        __size (float or int): The size of the square.
    """

    def __init__(self, size=0):
        """
        Initializes a square with a specified size.

        Parameters:
            size (float or int): The size of the square. Defaults to 0.
        """
        self.size = size

    @property
    def size(self):
        """Getter method to retrieve the size of the square."""
        return self.__size

    @size.setter
    def size(self, value):
        """
        Setter method to set the size of the square.

        Parameters:
            value (float or int): The size of the square.

        Raises:
            TypeError: If size is not a number (float or integer).
            ValueError: If size is less than 0.
        """
        if not isinstance(value, (float, int)):
            raise TypeError("size must be a number")
        elif value < 0:
            raise ValueError("size must be >= 0")
        else:
            self.__size = value

    def area(self):
        """Calculates the area of the square."""
        return self.__size ** 2

    def __eq__(self, other):
        """Equality comparator based on the square area."""
        return self.area() == other.area() if isinstance(other, Square) else False

    def __ne__(self, other):
        """Inequality comparator based on the square area."""
        return not self.__eq__(other)

    def __gt__(self, other):
        """Greater than comparator based on the square area."""
        return self.area() > other.area() if isinstance(other, Square) else False

    def __ge__(self, other):
        """Greater than or equal to comparator based on the square area."""
        return self.area() >= other.area() if isinstance(other, Square) else False

    def __lt__(self, other):
        """Less than comparator based on the square area."""
        return self.area() < other.area() if isinstance(other, Square) else False

    def __le__(self, other):
        """Less than or equal to comparator based on the square area."""
        return self.area() <= other.area() if isinstance(other, Square) else False
