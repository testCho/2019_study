def main():
    grid = [[1,0,0,1,0],[0,0,0,0,0],[0,0,0,1,0]]
    print(sol(grid))
    return

def sol(grid):
    link_count = 0
    n = len(grid)
    m = len(grid[0])
    visited = [[False for i in range(m)] for j in range(n)]

    for r in range(n):
        row_count = 0
        row_ind = []
        
        for c in range(m):
            if grid[r][c] == 0:
                continue
            row_count += 1
            row_ind.append(c)

        if row_count >= 2:
            link_count += row_count
            for ind in row_ind:
                visited[r][ind] = True

    for c in range(m):
        col_count = 0
        col_ind = []
        
        for r in range(n):
            if grid[r][c] == 0:
                continue
            col_count += 1
            col_ind.append(r)

        if col_count >= 2:
            for ind in col_ind:
                if visited[ind][c] == False:
                    link_count += 1
            
    return link_count

if __name__ == "__main__":
    main()
