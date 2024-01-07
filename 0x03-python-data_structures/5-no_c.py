#!/usr/bin/bash
def no_c(my_string):
    if my_string[:]:
        first_string = my_string.translate({ord("c"): None})
        second_string = first_string.translate({ord("C"): None})
        return second_string
    return my_string
