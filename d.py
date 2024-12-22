


from collections import deque

def is_valid(x, y, M, N, grid):
    return 0 <= x < M and 0 <= y < N and grid[x][y] == 0

def bfs(grid, source, destination, move_rule):
    M, N = len(grid), len(grid[0])
    visited = [[False for _ in range(N)] for _ in range(M)]
    queue = deque([(source[0], source[1], 0)])

    while queue:
        x, y, moves = queue.popleft()

        if (x, y) == destination:
            return moves

        visited[x][y] = True

        # Forward
        new_x, new_y = x + move_rule[0], y + move_rule[1]
        if is_valid(new_x, new_y, M, N, grid) and not visited[new_x][new_y]:
            queue.append((new_x, new_y, moves + 1))

        # Right
        new_x, new_y = x + move_rule[1], y - move_rule[0]
        if is_valid(new_x, new_y, M, N, grid) and not visited[new_x][new_y]:
            queue.append((new_x, new_y, moves + 1))

        # Left
        new_x, new_y = x - move_rule[1], y + move_rule[0]
        if is_valid(new_x, new_y, M, N, grid) and not visited[new_x][new_y]:
            queue.append((new_x, new_y, moves + 1))

        # Backward
        new_x, new_y = x - move_rule[0], y - move_rule[1]
        if is_valid(new_x, new_y, M, N, grid) and not visited[new_x][new_y]:
            queue.append((new_x, new_y, moves + 1))

    return -1  # Destination unreachable

M, N = map(int, input().split())

grid = []
for _ in range(M):
    grid.append(list(map(int, input().split())))

source_x, source_y = map(int, input().split())
destination_x, destination_y = map(int, input().split())
move_rule_x, move_rule_y = map(int, input().split())

source = (source_x, source_y)
destination = (destination_x, destination_y)
move_rule = (move_rule_x, move_rule_y)

min_moves = bfs(grid, source, destination, move_rule)
print(min_moves)

