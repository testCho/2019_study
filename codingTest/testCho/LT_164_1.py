def main():
    points = [[1,1],[3,4],[-1,0]]
    print(sol(points))
    return

def sol(points):
    total_time = 0
    num = len(points)

    for i,pt in enumerate(points): 
        next_pt = points[i]
        if i+1 < num:
            next_pt = points[i+1]

        x_diff = abs(next_pt[0] - pt[0])
        y_diff = abs(next_pt[1] - pt[1])

        total_time += max(x_diff, y_diff)

    return total_time

if __name__ == "__main__":
    main()

