# 関数オブジェクトを用いた高階関数の例
def add(a, b):
    return a + b

def multiply(a, b):
    return a * b

def calculate(operation, a, b):
    return operation(a, b)

add_func = add
multiply_func = multiply

result1 = calculate(add_func, 2, 3)  # 結果: 5
result2 = calculate(multiply_func, 2, 3)  # 結果: 6

print(result1, result2)