from collections import defaultdict
import copy


def solution(info, edges):
    tree = defaultdict(list)
    for a, b in edges:
        tree[a].append(b)
    sheep = 0
    total_sheep = len(info) - sum(info)
    stack = [[0, 0, 0, set()]]
    while stack:
        now, s, w, visited = stack.pop()
        visited.add(now)
        if info[now]:
            w += 1
        else:
            s += 1
        if s <= w:
            continue
        sheep = max(sheep, s)
        for v in visited:
            for c in tree[v]:
                if c not in visited:
                    stack.append([c, s, w, copy.deepcopy(visited)])

    return sheep