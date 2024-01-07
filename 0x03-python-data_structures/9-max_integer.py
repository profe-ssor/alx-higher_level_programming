#!/usr/bin/python
def max_integer(my_list=[]):
    if len(my_list) <= 0:
        return None
    else:
        maximum = my_list[0]
    for num in range(len(my_list)):
        if my_list[num] > maximum:
            maximum = my_list[num]
    return maximum
