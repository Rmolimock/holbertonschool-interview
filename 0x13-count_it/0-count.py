#!/usr/bin/python3
""" algo practive """
import requests


def recursive_helper(subreddit, word_list, titles, after=''):
    """ count given words """
    url = f'https://www.reddit.com/r/{subreddit}/hot.json?after={after}'
    response = requests.get(url,
                            headers={'User-agent': 'product'},
                            allow_redirects=False)
    if after is None:
        return titles
    if response.status_code != 200:
        return None
    for child in response.json().get('data').get('children'):
        title_str = child.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_str]:
                if titles.get(word):
                    titles[word] += 1
                else:
                    titles[word] = 1
    after = response.json().get('data').get('after')
    recursive_helper(subreddit, word_list, titles, after)
    return titles


def count_words(subreddit, word_list):
    """ count of given words in subreddit """
    titles = recursive_helper(subreddit, word_list, {})
    if not titles:
        return None
    sort_titles = sorted(titles.items(),
                         key=lambda each: each[1],
                         reverse=True)
    for key, value in sort_titles:
        if value != 0:
            print('{}: {}'.format(key, value))
