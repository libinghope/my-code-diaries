import os,sys

def printHeader(headerEnd,arr,file):
    for i in range(0,headerEnd):
        file.write(arr[i]+"\n")

def printBody(start,arr,file):
    quotemark = 34
    for i in range(len(arr)):
        file.write(arr[start] + chr(quotemark) + arr[i] + chr(quotemark) + ','+"\n")

def printFooter(start,arr,file):
    for i in range(start,len(arr)):
        file.write(arr[i]+"\n")


def createNextFileName():
    generation = -1
    for filename in os.listdir("."):
        if os.path.isfile(filename):
            generation += 1

    return "self_reference" + str(generation) + ".py"

headerEnd = 12

def calculate_line_number():
    back_frame = sys._getframe().f_back
    back_filename = os.path.basename(back_frame.f_code.co_filename)

    headerStart = 0
    i=0
    with  open(back_filename,'r') as f:

        line = f.readline()
        while(line):
            i+=1
            print(line)
            if line == '        "from functions import *",\n':
                headerStart = i
            if line==('        "    body = [",\n'):
                break
            line = f.readline()
    return i-headerStart+1