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
