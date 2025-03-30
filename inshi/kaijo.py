def kaijo(k,s):
    if k < 1:
        return s
    else:
        return kaijo(k-1,k*s)

print(kaijo(3,1))
