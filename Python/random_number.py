import sys
import random

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <n>")
        return
    
    try:
        n = int(sys.argv[1])
        if n < 1 or n > 100:
            raise ValueError
    except ValueError:
        print("Please provide a positive integer between 1 and 100.")
        return
    
    random_numbers = [random.random() for _ in range(n)]
    
    print("生成的随机数:", random_numbers)
    
    sorted_numbers = sorted(random_numbers)
    
    print("排序后的随机数:", sorted_numbers)

if __name__ == "__main__":
    main()
