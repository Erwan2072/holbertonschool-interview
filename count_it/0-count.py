#!/usr/bin/python3
import re
import requests
import sys


def count_words(subreddit, word_list, after=None, word_counts=None):
    """
    Fonction récursive qui compte les occurrences de mots-clés dans
    les titres des posts "hot" d'un subreddit.
    """
    if word_counts is None:
        # Initialize word counts with lowercase keywords
        word_counts = {}
        for word in word_list:
            key = word.lower()
            word_counts[key] = word_counts.get(key, 0)

    # Set up the API request
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'python:count_words:v1.0 (by /u/yourusername)'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    # Make the API request
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    # Check for invalid subreddit
    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    children = data.get('children', [])

    # Process each post title
    for child in children:
        title = child.get('data', {}).get('title', '')
        # Extract words using regex to avoid punctuation
        words = re.findall(r'\b\w+\b', title.lower())
        for word in words:
            if word in word_counts:
                word_counts[word] += 1

    # Check for more pages
    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, word_counts)
    else:
        # Filter out words with zero count
        filtered_counts = {k: v for k, v in word_counts.items() if v > 0}
        # Sort by count descending, then alphabetically
        sorted_words = sorted(filtered_counts.items(), key=lambda item:
                              (-item[1], item[0]))
        for word, count in sorted_words:
            print(f"{word}: {count}")
