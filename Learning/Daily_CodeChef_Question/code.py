from collections import defaultdict

def shortestPath(N, X, Y):
    graph = defaultdict(list)

    for i in range(1, N+1):
        for j in range(i+1, N+1):
            graph[i].append(j)
            graph[j].append(i)
    
    X, Y = min(X, Y), max(X, Y)
    distances = [0] * (N-1)
    visited = [False] * (N+1)
    queue = [(X, 0)]
    visited[X] = True
    
    while queue:
        node, distance = queue.pop(0)
        for neighbor in graph[node]:
            if visited[neighbor]:
                continue
            if neighbor == Y:
                distances[distance] += 1
            else:
                queue.append((neighbor, distance+1))
                visited[neighbor] = True
    
    return distances