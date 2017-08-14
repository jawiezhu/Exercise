#!/usr/bin/python
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

import sys
import re

"""Baby Names exercise

Define the extract_names() function below and change main()
to call it.

For writing regex, it's nice to include a copy of the target
text for inspiration.

Here's what the html looks like in the baby.html files:
...
<h3 align="center">Popularity in 1990</h3>
....
<tr align="right"><td>1</td><td>Michael</td><td>Jessica</td>
<tr align="right"><td>2</td><td>Christopher</td><td>Ashley</td>
<tr align="right"><td>3</td><td>Matthew</td><td>Brittany</td>
...

Suggested milestones for incremental development:
 -Extract the year and print it
 -Extract the names and rank numbers and just print them
 -Get the names data into a dict and print it
 -Build the [year, 'name rank', ... ] list and print it
 -Fix main() to use the extract_names list
"""

def extract_names(filename):
  """
  Given a file name for baby.html, returns a list starting with the year string
  followed by the name-rank strings in alphabetical order.
  ['2006', 'Aaliyah 91', Aaron 57', 'Abagail 895', ' ...]
  """
    # +++your code here+++
  try:
    baby_file = open(filename, 'rU')
  except IOError:
    print "no %s file! " % (filename)
    sys.exit(0)

  line = baby_file.read()

  male_name_rank_dic = {}
  female_name_rank_dic = {}
      #print line
  match = re.search(r'Popularity in \d\d\d\d',line)
  if match:
    year = match.group()[-4:]

  match_name = re.findall(r"<tr align=\"right\"><td>\d+</td><td>\w+</td><td>\w+</td>",line)
  if match_name:
    for ele in match_name:
      match_no = re.search(r"\d+",ele)
      match_male_name = re.search(r'</td><td>\w+</td><td>',ele)
      match_female_name = re.search(r'</td><td>\w+</td>$',ele)

      if match_no and match_male_name:
        male_name = match_male_name.group()[9:-9]
        female_name = match_female_name.group()[9:-5]
        rank = match_no.group()
#                print rank, male_name, female_name

        male_name_rank_dic [male_name] = rank
        female_name_rank_dic [female_name] = rank

          
  name_list = []

  for key in male_name_rank_dic:
                #print key,male_name_rank_dic[key]
    name_str = '%s %s' %(key, male_name_rank_dic[key])
    name_list.append(name_str)
  for key in female_name_rank_dic:
    name_str = '%s %s' %(key, female_name_rank_dic[key])
    name_list.append(name_str)

  name_list_sorted = sorted(name_list, key = lambda x : x[0])
  name_list_sorted.insert(0,year)
  return name_list_sorted
          #print len(name_list_sorted)


def main():
  # This command-line parsing code is provided.
  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
    args = sys.argv[1:]

    if not args:
        print 'usage: [--summaryfile] file [file ...]'
        sys.exit(1)

  # Notice the summary flag and remove it from args if it is present.
    summary = False
    if args[0] == '--summaryfile':
        summary = True
        del args[0]
    #print args

    for filename in args:
        #print args
        #print filename
        names = extract_names(filename)

        text = '\n'.join(names)

        if summary:
            outf = open(filename+'.summary', 'w')
            outf.write(text+ '\n')
            outf.close()
        else:
            print text

        #extract_names(args)
  # +++your code here+++
  # For each filename, get the names, then either print the text output
  # or write it to a summary file
  
if __name__ == '__main__':
  main()
