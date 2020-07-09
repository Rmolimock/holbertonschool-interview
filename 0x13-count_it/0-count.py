#!/usr/bin/python3
"""Count it problem
"""
import requests


def recursive_query(subreddit, word_list, titles, after=''):
    """ Query the reddit api and return a count of given words """
    url = "https://www.reddit.com/r/{}/hot.json?after={}".format(subreddit,
                                                                 after)
    response = requests.get(url,
                            headers={'User-agent': 'product'},
                            allow_redirects=False)
    if response.status_code != 200:
        return None
    if after is None:
        return titles
    for each in response.json().get('data').get('children'):
        title_string = each.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_string]:
                if not titles.get(word):
                    titles[word] = 1
                else:
                    titles[word] += 1
    after = response.json().get('data').get('after')
    recursive_query(subreddit, word_list, titles, after)
    return titles


def count_words(subreddit, word_list):
    """ Query the reddit api and return a count of given words """
    titles = recursive_query(subreddit, word_list, {})
    if not titles:
        return None
    sorted_titles = sorted(titles.items(),
                           key=lambda each: each[1],
                           reverse=True)
    for key, value in sorted_titles:
        if value != 0:
            print('{}: {}'.format(key, value))
