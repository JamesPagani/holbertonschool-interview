#!/usr/bin/python3
"""UTF-8 Validation
Check if a data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """validUTF8
    Determine if a data set represents a valid UTF-8 encoding.

    Arguments:
    data -- a list of integers representing a UTF-8 encoded string.

    Return:
    True if the data represents a valid UTF-8 encoding.
    False if otherwise.
    """

    contBytes = 0
    for byte in data:
        # Checking the continuation bytes of 2 to 4 byte-long characters
        while (contBytes > 0):
            if byte not in range(128, 192):
                return False
            contBytes -= 1
        # Checking the bytes
        else:
            if byte in range(128, 192):  # Invalid character
                return False
            elif byte in range(192, 224):  # 2 byte character detected
                contBytes += 1
            elif byte in range(224, 240):  # 3 byte character detected
                contBytes += 2
            elif byte in range(240, 248):  # 4 byte character detected
                contBytes += 3
            else:  # 1 byte character detected
                pass
    return True
