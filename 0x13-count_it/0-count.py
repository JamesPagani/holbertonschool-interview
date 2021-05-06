#!/usr/bin/python3
"""Count it.

Write a recursive function that queries the Reddit API, parses the title of
all hot articles, and prints a sorted count of given keywords.
"""

import requests


def sortRules(item):
    """Sort rules for the sorted method."""
    keyword = item[0]
    count = item[1]
    return (count, keyword)


def setKeywords(word_list):
    """Convert the word list into a list of tuples.

    Tuple format: (keyword, count, increment)
    """
    keywords = []
    if type(word_list[0]) is not list:
        word_list.sort()
        lastWord = None
        for word in word_list:
            if word == lastWord:
                keywords[len(keywords) - 1][2] += 1
            else:
                keywords.append([word, 0, 1])
            lastWord = word
    else:
        keywords = word_list
    return keywords


def count_words(subreddit, word_list):
    """count_words.

    Count the amount of times keywords appear in the hot articles
    of a subreddit and prints the results.


    args:
    - subreddit (string): Name of the subreddit to check.
    - word_list (list): A list of strings filled with keywords.
    """
    req_info = subreddit.split()
    print(req_info)
    keywords = setKeywords(word_list)
    count = 0

    # Making the Request
    url = "https://www.reddit.com/r/{}/hot.json".format(req_info[0])
    headers = {
        "user-agent": "Linux:1fmuwOiskMHGTQ:v0.0.5 (by /u/JamesWulfgaro)"
        }
    params = {"limit": 100}
    if len(req_info) > 1:
        params["after"] = req_info[1]
        params["count"] = int(req_info[2])
        count = params["count"]
    sub_info = requests.get(
        url,
        allow_redirects=False,
        headers=headers,
        params=params
        )

    # If the subreddit does not exist, don't even continue
    if sub_info.status_code != 200:
        return

    # Keyword counting
    next_page = sub_info.json().get('data').get('after', None)
    articles = sub_info.json().get('data').get('children')
    count += len(articles)
    for article in articles:
        for word in article.get('data').get('title').split():
            for keyword in keywords:
                if word.lower() == keyword[0].lower():
                    keyword[1] += keyword[2]

    # Print the results if there's no more pages
    if next_page is None:
        sorted_keywords = sorted(keywords, key=sortRules, reverse=True)
        for keyword in sorted_keywords:
            if keyword[1] > 0:
                print("{}: {}".format(keyword[0], keyword[1]))
        return

    # Preparing the next request
    subreddit = "{} {} {}".format(req_info[0], next_page, count)
    count_words(subreddit, keywords)
