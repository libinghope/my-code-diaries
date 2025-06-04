from functions import *

def freedom_function():
    print("I am free")

header_end = calculate_line_number()
def quine():
    freedom_function()
    fileName = createNextFileName()
    file = open(fileName, 'w')
    quotemark = 34
    body = [
        "from functions import *",
        "",
        "def freedom_function():",
        "    print('I am free')",
        "",
        "header_end = calculate_line_number()",
        "",
        "def quine():",
        "    fileName = createNextFileName()",
        "    file = open(fileName, 'w')",
        "    quotemark = 34",
        "    body = [",
        "        ",
        "    ]",
        "    printHeader(header_end,body,file)",
        "    printBody(header_end,body,file)",
        "    printFooter(header_end+1,body,file)",
        "    file.close()",
        "quine()",
    ]
    printHeader(header_end,body,file)
    printBody(header_end,body,file)
    printFooter(header_end+1,body,file)
    file.close()
quine()
