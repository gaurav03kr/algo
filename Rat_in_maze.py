def findPath(maze, n):
    curr_path = ''
    all_path = []
    visited = [[False] * n for _ in range(n)]
    
    def isSafe(i,j):
        return 0 <= i < n and 0 <=j < n and maze[i][j] and not visited[i][j]
    def helper(i,j,curr_path):
        if (i==n-1) and j == n-1:
            all_path.append(curr_path)
            return 
        visited[i][j] = True

        if isSafe(i+1,j):
            helper(i+1,j,curr_path+'D')
        if isSafe(i,j-1):
            helper(i,j-1,curr_path+'L')
        if isSafe(i,j+1):
            helper(i,j+1,curr_path+'R')
        if isSafe(i-1,j):
            helper(i-1,j,curr_path+'U')
        
        visited[i][j] = False

    if maze[0][0] == 1:
        helper(0,0,'')

    if all_path:
        return sorted(all_path)
    else:
        return [-1]