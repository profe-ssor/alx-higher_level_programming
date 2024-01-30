#!/usr/bin/python3

def safe_print_integer_err(value):
    try:
        integer_value = int(value)
        print("{:d}".format(integer_value))
        return True
    except ValueError as e:
        import sys
        print("Exception:", e, file=sys.stderr)
        return False
