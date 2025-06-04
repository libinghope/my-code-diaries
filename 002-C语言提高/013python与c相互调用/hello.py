class Hello:
    def __init__(self, x):
        self.a = x
    def print(self, x=None):
        print(x)
def xprint():
    print("hello world")

if __name__ == "__main__":
    xprint()
    h = Hello(5)
    h.print()