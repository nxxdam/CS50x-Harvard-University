from cs50 import get_int

def get_height(min=1, max=8):
    """For the value of the height"""
    
    while True:
        height = get_int("Enter the height: ")
        if height >= min and height <= max:
            return height

def print_pyramid(p):
    """To print (p) height, which is half-pyramid"""
    for i in range(1, p+1):
        print(" "*(p-i) + "#"*i)

def main():
    height = get_height()
    print_pyramid(height)

if __name__=="__main__":
    main()
    
#reference : chinhungtseng : https://github.com/chinhungtseng/cs50x2021/tree/master/week6/pset6/mario/less line 3-9
