#!/usr/bin/python3
"""Log Parsing
Read from STDIN line by line and compute metrics from 'HTTP Requests'.
"""
# Imports
from sys import stdin


# Status code and file size report function
def status_report(total_size, status_codes):
    """Print a report of the last ten HTTP requests recieved"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))

# Variables
total_size = 0
status_codes = {}
count = 0

try:
    for line in stdin:
        # Take the last two items, which are the status code and file size...
        metrics = line.split()[-2:]

        # Create a new key-pair value, if it doesn't exist yet.
        if metrics[0] not in status_codes:
            status_codes[metrics[0]] = 1
        else:
            status_codes[metrics[0]] += 1
        total_size += int(metrics[1])
        count += 1

        # Each ten lines, report the total file size and amount of status codes
        if count % 10 == 0:
            status_report(total_size, status_codes)
except KeyboardInterrupt:
    status_report(total_size, status_codes)
finally:
    pass
