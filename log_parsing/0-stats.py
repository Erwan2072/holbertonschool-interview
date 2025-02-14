#!/usr/bin/python3
"""
Log Parsing Script
"""
import sys
import signal

if __name__ == "__main__":
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    total_size = 0
    line_count = 0

    def print_stats():
        """
        Prints the accumulated statistics.
        """
        print(f"File size: {total_size}")
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")

    def signal_handler(sig, frame):
        """
        Handles keyboard interruption (CTRL + C)
        """
        print_stats()
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()

            if len(parts) < 9:
                continue
            try:
                file_size = int(parts[-1])
                total_size += file_size
                status_code = int(parts[-2])
                if status_code in status_codes:
                    status_codes[status_code] += 1
            except ValueError:
                continue
            if line_count % 10 == 0:
                print_stats()

    except KeyboardInterrupt:
        print_stats()
        sys.exit(0)
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0
line_count = 0


def print_stats():
    """
    Prints the accumulated statistics.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


def signal_handler(sig, frame):
    """
    Handles keyboard interruption (CTRL + C)
    """
    print_stats()
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        if len(parts) < 9:
            continue
        try:
            file_size = int(parts[-1])
            total_size += file_size
            status_code = int(parts[-2])
            if status_code in status_codes:
                status_codes[status_code] += 1
        except ValueError:
            continue
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    sys.exit(0)
