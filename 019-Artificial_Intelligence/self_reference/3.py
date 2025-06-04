header_end = 5 #这里的5可以作为参数从'外部'传入

def quine():
    quotemark = 34
    body = [
        "header_end = 5 #这里的5可以作为参数从'外部'传入",
        "",
        "def quine():",
        "    quotemark = 34",
        "    body = [",
        "        ",
        "    ]",
        "    for header_lin in range(header_end):",
        "        print(body[header_lin])",
        "    for line in range(0,len(body)):",
        "        print(body[header_end] + chr(quotemark) + body[line] + chr(quotemark) + ',')",
        "    for footer_line in range(header_end+1,len(body)):",
        "        print(body[footer_line])",
        "quine()",
    ]
    for header_lin in range(header_end):
        print(body[header_lin])
    for line in range(0,len(body)):
        print(body[header_end] + chr(quotemark) + body[line] + chr(quotemark) + ',')
    for footer_line in range(header_end+1,len(body)):
        print(body[footer_line])
quine()