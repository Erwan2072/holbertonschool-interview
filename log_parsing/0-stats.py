#!/usr/bin/python3
"""
Log Parsing Script
"""
from sys import stdin

# Initialisation des variables
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0
line_count = 0

def print_stats():
    """
    Affiche les statistiques cumulées.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")
    sys.stdout.flush()  # Force l'affichage immédiat des résultats

def signal_handler(sig, frame):
    """
    Gère l'interruption du clavier (CTRL + C)
    """
    print_stats()
    sys.exit(0)

# Capture du signal d'interruption
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        try:
            parts = line.split()
            if len(parts) < 9:
                continue  # Ignore les lignes mal formatées

            file_size = int(parts[-1])
            status_code = int(parts[-2])

            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats()

        except ValueError:
            continue  # Ignore les lignes mal formatées

except EOFError:
    pass  # Gestion de la fin de fichier proprement

# Affichage final des statistiques
print_stats()
#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics
"""

from sys import stdin

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    list_status_codes = [
        "200", "301", "400", "401", "403", "404", "405", "500"]
    for status in list_status_codes:
        status_codes[status] = 0
    count = 0
    try:
        for line in stdin:
            try:
                args = line.split(" ")
                if len(args) != 9:
                    pass
                if args[-2] in list_status_codes:
                    status_codes[args[-2]] += 1
                if args[-1][-1] == '\n':
                    args[-1][:-1]
                total_size += int(args[-1])

            except (ValueError, IndexError):
                pass
            count += 1
            if count % 10 == 0:
                print("File size: {}".format(total_size))
                for status in sorted(status_codes.keys()):
                    if status_codes[status] != 0:
                        print("{}: {}".format(
                            status, status_codes[status]))
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))
    except KeyboardInterrupt as err:
        print("File size: {}".format(total_size))
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))
        raise
