#!/usr/bin/python3
def new_in_list(my_list, idx, element):
    swp = my_list[:]
    if idx < 0:
        return swp
    if idx >= len(my_list):
        return swp
    swp[idx] = element
    return swp
