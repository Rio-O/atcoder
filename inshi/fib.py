def fib(s,pre,prepre):
    if s < 1:
        return pre
    else:
        return fib(s-1, pre+prepre, pre)

print(fib(5,1,0))
