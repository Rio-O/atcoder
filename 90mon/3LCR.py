#道路を新設する前では閉路はできていない
#閉路をもたない木構造のグラフに対して最大の長さを探す問題に帰着できそう

#適当な点からの最遠点をとる
#最遠点からの最遠点をとる
import numpy as np

N = int(input())

edges = []
dist = np.zeros(N)
dist.fill(-1)
print(dist)

for i in range(N):
    edges.append(map(int, input().split()))

fst_piv = 0

tedge1 = edges

#i番目をiで走査
while tedge1 != []:
    for i in range(len(tedge1)):