#!/usr/bin/python3
"""
Prime Game: determine overall winner across x rounds.
Maria starts, both play optimally.
"""


def isWinner(x, nums):

    """Determines the winner of the prime game"""
    if not nums or x <= 0:
        return None

    rounds = min(x, len(nums))
    max_n = max(nums) if rounds > 0 else 0

    if max_n < 2:
        """
        Aucun premier dans toutes les manches
        Maria ne peut jamais jouer en premier
        Ben gagne tout
        (sauf si x=0 / nums vide, déjà géré)
        """

        ben = sum(1 for i in range(rounds) if nums[i] >= 1)
        maria = 0
        if maria > ben:
            return "Maria"
        if ben > maria:
            return "Ben"
        return None

    # Crible d'Ératosthène jusqu'à max_n
    is_prime = [False, False] + [True] * (max_n - 1)
    p = 2
    while p * p <= max_n:
        if is_prime[p]:
            for m in range(p * p, max_n + 1, p):
                is_prime[m] = False
        p += 1

    # prefix_primes[i] = nb de premiers ≤ i
    prefix_primes = [0] * (max_n + 1)
    cnt = 0
    for i in range(1, max_n + 1):
        if is_prime[i]:
            cnt += 1
        prefix_primes[i] = cnt

    maria_wins = 0
    ben_wins = 0
    for i in range(rounds):
        n = nums[i]
        moves = prefix_primes[n] if n <= max_n else 0
        if moves % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
