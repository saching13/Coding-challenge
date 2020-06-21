from collections import deque

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        
        if not len(grid): return -1
        rows = len(grid)
        cols = len(grid[0])
        
        pathGrid = [[float('inf') for i in range(cols)] for j in range(rows)]    
        totalvisits = [[0 for i in range(cols)] for j in range(rows)]
        numberOfBuildings = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    numberOfBuildings += 1
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    # print(f"grif index = {i}, {j}")
                    ispathExists = bfs(grid, i, j, pathGrid, totalvisits, numberOfBuildings)
                    pathGrid[i][j] = float('inf')
                    if not ispathExists:
                        return -1
        minval = float('inf')
        for i in range(rows):
            for j in range(cols):
                if numberOfBuildings == totalvisits[i][j]:
                    minval = min(minval, pathGrid[i][j])
        print(pathGrid)
        if minval == float('inf'): return -1
        return minval
    
def actionSpace(r, c, maxRow, maxCol, visiting):
    # if 0 <= r < maxRow and 0 <= c < maxCol:
      
    actions = []
    
    if r - 1 >= 0 and not visiting[r - 1][c]:
        actions.append((-1, 0))
    if r + 1 < maxRow and not visiting[r + 1][c]:
        actions.append((1, 0))
    if c - 1 >= 0 and not visiting[r][c - 1]:
        actions.append((0, -1))
    if c + 1 < maxCol and not visiting[r][c + 1]:
        actions.append((0, 1))
    
    return actions
        
        
def bfs(grid, r, c, pathGrid, totalvisits, numberOfBuildings):
    nodeStack = deque([(r,c),None])
    # nodeStack.append()
    dist = 0
    rows = len(grid)
    cols = len(grid[0])
    
    visiting = [[False for i in range(cols)] for j in range(rows)]
    buildingsCount = 0
    while nodeStack:
        currlevel = len(nodeStack)
        
        for i in range(currlevel):
            currNode = nodeStack.popleft()

            if not currNode:
                continue

            r, c = currNode
            # print(r,c)
            if pathGrid[r][c]== float('inf'):
                pathGrid[r][c] = dist
            else:
                pathGrid[r][c] += dist
            
            totalvisits[r][c] += 1

            # print(pathGrid[r][c])


            actions = actionSpace(r, c, len(grid), len(grid[0]), visiting)
            # print(f"actions = {actions}")
            # print(visiting)
            for del_r, del_c in actions:
                if grid[r + del_r][c + del_c] == 0:
                    nodeStack.append((r + del_r, c + del_c))
                    
                elif grid[r + del_r][c + del_c] == 1 and not visiting[r + del_r][c + del_c]:
                    buildingsCount += 1
                visiting[r + del_r][c + del_c] = True
        
        dist += 1
    # print(buildingsCount)
    return buildingsCount == numberOfBuildings
        
        
        
        
        
    