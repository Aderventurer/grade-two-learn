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
    
    with open("random.txt", "w") as f:
        for num in random_numbers:
            f.write(f"{num}\n")
    
    print(f"生成的随机数已保存到 random.txt 文件.")
    
    with open("random.txt", "r") as f:
        random_numbers_from_file = [float(line.strip()) for line in f.readlines()]
    
    print(f"从 random.txt 文件中读取的随机数: {random_numbers_from_file}")
    
    sorted_numbers = sorted(random_numbers_from_file)
    
    with open("sorted.txt", "w") as f:
        for num in sorted_numbers:
            f.write(f"{num}\n")
    
    print(f"排序后的随机数已保存到 sorted.txt 文件.")

if __name__ == "__main__":
    main()
