N, L = map(int, input().split())
K = int(input())

A = list(map(int, input().split()))

def check(x):
    num = 0
    pre = 0

    for i in range(N):
        if (A[i] - pre >= x):
            num += 1
            pre = A[i]

    if(L - pre >= x):
        num += 1
    
    return(num >= K + 1)
        
(left,right) = (-1,L+1)

while(right-left>1):
    if(check((left + right)//2)):
        left = (left + right) // 2
    else:
        right = (left + right) // 2

print(left)