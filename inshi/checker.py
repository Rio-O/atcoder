def kaijo(n):
    if n == 1:
        return 1
    else:
        return n* kaijo(n-1)


def kaijo2(n,sum):
    if n == 1:
        return sum
    else:
        return kaijo2(n-1, n*sum)

print(kaijo(3))
print(kaijo2(3,1))

x = ["1",2]
print(type(x),x)