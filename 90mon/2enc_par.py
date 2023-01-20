from itertools import product

N = int(input())

def check(S):
    score = 0
    bool = True

    for c in S:        
        if c == '(':
            score += 1
        if c == ')':
            score -= 1
        
        if score < 0:
            bool = False
    
    return bool & (score == 0)

for S in product(['(', ')'], repeat=N):
    if(check(S)):
        print(*S, sep = '')


