def binary_to_decimal(binary_string):
    decimal_number = 0
    length = len(binary_string)
    
    for i in range(length):
        bit = int(binary_string[length - 1 - i]) 
        decimal_number += bit * (2 ** i)  
    
    return decimal_number

if __name__ == "__main__" :
    binary_string = '1101'
    result = binary_to_decimal(binary_string)
    print(result) 