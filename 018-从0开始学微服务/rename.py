# -*-coding:utf-8-*- 
import os 

def main():
    for root,dirs,files in os.walk("./"): 
        for f in files:
            print(f)
            if f.startswith('8.'):
                os.rename(f,'18{}'.format(f[1:]))
            pass

if __name__=='__main__':
    main()