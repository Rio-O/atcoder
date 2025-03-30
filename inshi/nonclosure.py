a = 0

c = lambda x: x + a
def cal(x):
    return x + a

d = cal

a = 10

print(c(1))#11を返す#closureではない
print(cal(1))
print(d(1))

