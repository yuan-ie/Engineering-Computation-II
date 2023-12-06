from time import time

def load_grid(fname):
    
    # load grid
    with open(fname) as f:
        lines = f.readlines()
    
    # convert to numbers 
    grid = [ [ ord(c)-ord('a') for c in line[:-1]] for line in lines]
    
    # find start and end points
    for i in range(len(grid)):
        if -14 in grid[i]:
            i_start,j_start = i , grid[i].index(-14)
        if -28 in grid[i]:
            i_end,j_end = i , grid[i].index(-28)

    # replace start/end points with appropriate value
    grid[i_start][j_start] = 0
    grid[i_end][j_end]     = 25

    return grid , (i_start,j_start) , (i_end,j_end)

def djk(grid , loc_start , loc_end):


    n_rows,n_cols = len(grid) , len(grid[0])
    INF = int(1e6)

    # init dictionaries
    d_incomplete,d_complete = {} ,{}

    # add all nodes to the <incomplete> dictionary
    t1 = time()
    for i in range(n_rows):
        for j in range(n_cols):
            d_incomplete[(i,j)] = (INF,(99,99))

    # move <start> to <complete> list with distance 0
    d_complete[loc_start] = (0 , (99,99))
    del d_incomplete[loc_start]

    loc_curr = loc_start
    dist_curr = 0
    t_init = time() - t1

    # helper functions - will revisit in a second
    def get_val(loc):
        return grid[loc[0]][loc[1]]

    def reachable(loc_curr , loc_dst):
        return get_val(loc_curr) - get_val(loc_dst) >= -1

    def valid_loc(loc):
        return 0 <= loc[0] < n_rows and 0<=loc[1]< n_cols

    t_update = 0
    t_find_min = 0
    t_cleanup = 0

    while loc_curr != loc_end:

        # is there <up>
        # is up incomplete
        # is up reachable
        # is dist_curr+1 < up current distance
        incomplete_keys = d_incomplete.keys()

        t1 = time()
        # update all 4 neighbors of current node
        for delta in [(-1,0) , (1,0) , (0,-1) , (0,1)]:
            loc_neighbor = (loc_curr[0] + delta[0] , loc_curr[1] + delta[1])
            if valid_loc(loc_neighbor):
                if loc_neighbor in incomplete_keys:
                    if reachable(loc_curr , loc_neighbor):
                        if (dist_curr + 1) <= d_incomplete[loc_neighbor][0]:
                            d_incomplete[loc_neighbor] = (dist_curr+1 , loc_curr)
        t_update += time() - t1

        # find minimum incomplete node
        t1 = time()
        loc_next = None
        min_dist = INF
        for k in incomplete_keys:
            if d_incomplete[k][0] < min_dist:
                min_dist = d_incomplete[k][0]
                loc_next = k
        t_find_min += time() - t1

        t1 = time()        
        # make min node the new current node
        dist_curr = min_dist
        loc_curr = loc_next
        # move new current node from incomplete
        # to complete dictionary
        d_complete[loc_next] = d_incomplete[loc_next]
        del d_incomplete[loc_next]
        t_cleanup += time() - t1

    print("\nDijsktra-only times:")
    print(f"{'init'    :8s} = {t_init    :0.4f}s")
    print(f"{'update'  :8s} = {t_update  :0.4f}s")
    print(f"{'find min':8s} = {t_find_min:0.4f}s")
    print(f"{'cleanup' :8s} = {t_cleanup :0.4f}s")

    return d_complete[loc_end][0]

t1 = time()
grid , loc_start, loc_end = load_grid('aoc_2.txt')
t2 = time()
n = djk(grid,loc_start,loc_end)
t3 = time()

print("\nshortest path: " , n)

print(f"\nload time: {t2-t1:0.4f}s")
print(f"dijkstra time: {t3-t2:0.4f}s")
print("\n")