#!/usr/bin/python -tt
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

"""Wordcount exercise
Google's Python class

The main() below is already defined and complete. It calls print_words()
and print_top() functions which you write.

1. For the --count flag, implement a print_words(filename) function that counts
how often each word appears in the text and prints:
word1 count1
word2 count2
...

Print the above list in order sorted by word (python will sort punctuation to
come before letters -- that's fine). Store all the words as lowercase,
so 'The' and 'the' count as the same word.

2. For the --topcount flag, implement a print_top(filename) which is similar
to print_words() but which prints just the top 20 most common words sorted
so the most common word is first, then the next most common, and so on.

Use str.split() (no arguments) to split on all whitespace.

Workflow: don't build the whole program at once. Get it to an intermediate
milestone and print your data structure and sys.exit(0).
When that's working, try for the next milestone.

Optional: define a helper function to avoid code duplication inside
print_words() and print_top().

"""

import sys

def word_count_dict(filename):
    word_count = {}
    input_file = open(filename, 'r')
    for line in input_file:
        words = line.split()
        for word in words:
            word = word.lower()
            if not word in word_count:
                word_count[word] = 1
            else:
                word_count[word] = word_count[word] + 1
    input_file.close()
    return word_count

def openfile(filename):
    myfile = open(filename, 'r')
    lines = myfile.readlines()
    return lines

def getWordDic(filelines):
    dic = {}
    for line in filelines:
        line = line.strip('\n').lower()
        for word in line.split(' '):
            #print word
            if word < 'z' and word > 'a':
                if dic.get(word) is None:
                    dic[word] = 1
                else:
                    dic[word] = dic[word] + 1  
    return dic


def print_words(filename): 
    filelines = openfile(filename)
    dic = getWordDic(filelines) 
    keys = dic.keys()
    keys.sort()
    for key in keys:
        print key, dic[key]

def get_count(word_count_tuple):
    return word_count_tuple[1]


def print_top(filename):
    filelines = openfile(filename)
    dic = getWordDic(filelines)
    items = dic.items()
    backitems = [[v[1], v[0]] for v in items]
    backitems.sort(reverse=True)
    for i in range(0, len(backitems)): 
        print backitems[i][1], backitems[i][0]

    #items = sorted(word_count.items(), key=get_count, reverse=True)


# +++your code here+++
# Define print_words(filename) and print_top(filename) functions.
# You could write a helper utility function that reads a file
# and builds and returns a word/count dict for it.
# Then print_words() and print_top() can just call the utility function.

###

# This basic command line argument parsing code is provided and
# calls the print_words() and print_top() functions which you must define.
def main():
  if len(sys.argv) != 3:
    print 'usage: ./wordcount.py {--count | --topcount} file'
    sys.exit(1)

  option = sys.argv[1]
  filename = sys.argv[2]
  if option == '--count':
    print_words(filename)
  elif option == '--topcount':
    print_top(filename)
  else:
    print 'unknown option: ' + option
    sys.exit(1)

if __name__ == '__main__':
  main()