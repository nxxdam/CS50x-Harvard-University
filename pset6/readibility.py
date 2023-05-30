import re
import string
from cs50 import get_string

def main():

    text = get_string("Enter Text: ") 
    #input text

    count_letters = len(re.findall('[a-zA-Z]', text))  #to count letters
    count_words = len(text.split());            #to count words
    count_sentences = len(re.findall(r'[.!?]+', text))  #to count words

    index = readability_index(count_letters, count_words, count_sentences)

    print_grade(index)

#Coleman-Liao-Index
def readability_index(count_letters, count_words, count_sentences):

    count_words_per_100 = count_words / 100
    L = count_letters / count_words_per_100
    S = count_sentences / count_words_per_100
    
    index = round(0.0588 * L - 0.296 * S - 15.8)

    return index

def print_grade(index):
    if index < 1:
        print("Before Grade 1") #numbers between 15 to 1
    elif index >= 16:
        print("Grade 16+") #to print grade 16+
    else:
        print(f"Grade {index}") #to print b4 grade 1

main()

#reference: https://github.com/Mayconpm/CS50x_2021/blob/master/pset6/readability/readability.py line 7-16
