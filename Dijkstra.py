# link to question: https://codeforces.com/problemset/problem/20/C



import heapq

INF = float('inf')

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

visited = [(INF, -1) for _ in range(n + 1)]  # (distance, previous_node)
visited[1] = (0, 0)

pq = []
heapq.heappush(pq, (0, 1))  # (distance, node)

while pq:
    dist, node = heapq.heappop(pq)
    if dist > visited[node][0]:
        continue
    for nxt, weight in graph[node]:
        new_dist = visited[node][0] + weight
        if new_dist < visited[nxt][0]:
            visited[nxt] = (new_dist, node)
            heapq.heappush(pq, (new_dist, nxt))

if visited[n][1] == -1:
    print(-1)
else:
    path = []
    node = n
    while node != 0:
        path.append(node)
        node = visited[node][1]
    print(' '.join(map(str, reversed(path))))
