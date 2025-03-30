def add(a,b):
    c = []
    for i in range(min(len(a), len(b))):
        c.append(a[i]+b[i])
    if len(a) > len(b):
        for i in range(len(a)-len(b)):
            c.append(a[len(b) + i])
    if len(b) > len(a):
        for i in range(len(b)-len(a)):
            c.append(b[len(a) + i])
    return c

print(add([1,2,3,4,5], [5,4,3]))


def imul(l,k):
    c = []
    for i in range(len(l)):
        c.append(l[i]*k)
    return l

def mult(a,b):
    c = []
    for i in range(len(a)):
        d = imul(b,a[i])
        for k in range(i):
            d.insert(0,0)
        c = add(c,d)
    return c

a = [1,1]
b = [1,2,3]
print(mult(a,b))


