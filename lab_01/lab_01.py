'''
Lab 01

Description

Yuan Nghiem
tul16619@temple.edu
September 3, 2023

Example:
    This file can be run by typing
'''


import math
import sys

def main(argv):

    # don't mess with this part
    filename = "/data/courses/ece_3822/current/lab_01/data.txt"
    if len(argv) > 1:
        filename = argv[1]

    # This is some demo code to show you how to read an integer out of a text
    # file. There are other ways to do this and those are fine too if you prefer
    
    x = [] #empty list
    with open(filename) as f:
        for line in f:
            x.append(int(line)) #stores values in a list
    
    #for value in x:
    #    print(value)

    #find SUM

    i = 0
    sum = 0

    while(i < len(x)):
        sum = sum + x[i]
        i = i + 1

    #---------------find average-------------------------------------
    avg = sum / len(x)
    avg_2dec = "{:.2f}".format(avg)

    print("the average is",avg_2dec)


    #--------------find sqrt of product of 1st and 2nd max-----------

    max1 = max(x)

    max2 = 0

    for i in x:
        if max2 < i and i < max1:
            max2 = i

    print("max1 =", max1) #CHECK
    print("max2 =", max2) #CHECK

    s = math.sqrt(max1 * max2)
    s_2dec = "{:.2f}".format(s)

    print("the squareroot of the product of the two largest values=", s_2dec)


if __name__=="__main__":
    main(sys.argv)