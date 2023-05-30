import re
import csv

from sys import argv, exit


# to check for correct number of args
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# to open files
with open(argv[1],newline="") as csvfiles:
    reader_dbs =csv.reader(csvfiles,delimiter=",",quotechar="|")
    for k, row in enumerate(reader_dbs):  # Read databases data
        
        #to search for the match
        #initialize counter all values to zero
        if k == 0:
            with open(argv[2], "r") as file:
                line = next(file)
                the_longest_strs = [] #str sequence header 
                
                for k in range(1, len(row)):
                    pattern = row[k]
                    matches = (
                        match[0] for match in re.finditer(fr"(?:{pattern})+", line)
                    )
                    
                    try:
                        longest = int(len(max(matches, key=len)) / len(pattern))
                        the_longest_strs.append(longest)
                        
                    except ValueError:
                        the_longest_strs.append(0)
                        
        else:
            # Search target in database, if match, return target's name;
            dbs_list_strs = list(map(int, row[1:]))
            if dbs_list_strs == the_longest_strs:
                print(row[0])
                break
    else:
        # otherwise return "no match"
        print("No match\n")
        
#reference:- https://github.com/Mayconpm/CS50x_2021/blob/master/pset6/dna/dna.py  line:19-35
