class edge:pass     # poor-person's prototype

class node:
    
    def __init__(self,name:str) ->None :
        self.name = name        # name of node
        self.friends = []       # list of <edges>

    def add_edge(self , e:edge) ->None:
        self.friends.append(e)

    def display(self , opt=0) ->None:

        if opt==0:
            print(self.name , " has " , len(self.friends) , " friend(s)")
            return
        
        if opt==1:
            print(self.name, end=": ")
            for f in self.friends:
                print(f.dst.name, end=" ")
            print()
            return

class edge:

    '''
    Each edge has <src> , <dst> (both of type <node>)
    and a weight (wt <float>)
    '''

    def __init__(self , s:node , d:node , w:float=1) -> None :
        self.src = s
        self.dst = d
        self.wt  = w

class graph:

    def __init__(self) ->None :
        self.nodes = []
        self.edges = []
    
    def insert(self,name:str) -> None:
        new_node = node(name)
        self.nodes.append(new_node)

    def find_node(self , name:str) -> node:
        for nd in self.nodes:
            if nd.name == name:
                return nd
        return None

    def make_friends(self , name_src:str , name_dst:str , weight = 1) ->None:

        node_src = self.find_node(name_src)
        node_dst = self.find_node(name_dst)

        if not node_src:
            raise ValueError(f"{name_src} not found")
        if not node_dst:
            raise ValueError(f"{name_dst} not found")

        if node_src==node_dst:
            raise ValueError("You can't be friends with yourself.")

        new_edge = edge(node_src,node_dst,weight)

        # append new edges to the graph's master list of edges
        self.edges.append(new_edge)

        node_src.add_edge(new_edge)

    def print_all_nodes(self , opt=0) -> None:
        for n in self.nodes:
            n.display(opt)

    def djk(self, n_src , n_dst, grid = None):
        INF = int(1e6)

        unvisited_nodes = {}
        visited_nodes   = {}

        # init unvisited nodes
        for nd in self.nodes:
            unvisited_nodes[nd] = [INF , None]

        curr_node = n_src
        curr_dist = 0
        
        visited_nodes[n_src] = [curr_dist , n_src]
        del unvisited_nodes[curr_node]

        while curr_node != n_dst:

            # update best path to each neighbor of curr_node
            for e in curr_node.friends:
                new_dist = curr_dist + e.wt

                if e.dst in unvisited_nodes.keys():
                    if new_dist < unvisited_nodes[e.dst][0]:
                        unvisited_nodes[e.dst] = [new_dist , curr_node]

            # find the node with min path, make it the next curr_node
            best_dist = INF
            best_node = None
            for nd in unvisited_nodes.keys():
                if unvisited_nodes[nd][0] < best_dist:
                    best_node = nd
                    best_dist = unvisited_nodes[nd][0]

            best_dist = unvisited_nodes[best_node][0]
            best_prev = unvisited_nodes[best_node][1]
            
            curr_node = best_node
            curr_dist = best_dist

            visited_nodes[best_node] = [ best_dist , best_prev  ]
            del unvisited_nodes[best_node]                

        # all done - now package everything up for return

        # best distance between src and dst
        n = visited_nodes[n_dst][0]

        #  create a list of nodes from dst back to src
        p = []
        p.append(nd := n_dst)
        while nd != n_src:
            nd = visited_nodes[nd][1]
            p.append(nd)

        # extract the node names from each node in the path; reverse order so its
        # src to dst
        pstr = [pp.name for pp in p[::-1]]

        #  return all
        return n,pstr

    def best_path(self , name1:str, name2:str , disp:int = 0 , grid = None):

        #  find nodes corresponding to src and dst
        node_src = self.find_node(name1)
        node_dst = self.find_node(name2)

        #  conduct dijkstras
        n,p = self.djk(node_src , node_dst, grid=grid)

        # display results if so requested
        if disp==1:

            print("\nbest path" ,  name1 , " --> " , name2 , "is" , str(n) , "units")
            print(p[0],end="")
            for pp in p[1:]:
                print(" ->" , pp , end='')
            print("")

        #  return all
        return n,p

def load_data(fname , disp=0):
    with open(fname) as f:
        # <lines> is a list of rows, each row is a list of characters
        lines = f.readlines()
    
    # convert each character to a number
    # the (-1) strips the newline character at the end of each line
    grid = [ [ord(c) - ord('a') for c in line[:-1]] for line in lines]

    # pad the top and bottom with 99's
    n_cols = len(grid[0])
    n_rows = len(grid)

    grid = [[99 for _ in range( n_cols )]] + grid
    grid = grid + [[99 for _ in range( n_cols )]]

    # # pad left and right with 99's
    grid = [[199] + g + [199] for g in grid]

    # pretty-print grid
    if disp == 1:   
        for g in grid:
            for x in g:
                print(f"{x:4d}",end="")
            print("")

    def node_name(i,j):
        return "nd" + f"{(i-1)*n_cols + (j-1):04d}"


    # iterate through all nodes and create the graph
    grph = graph()
    for i in range(1,1+n_rows):
        for j in range(1,1+n_cols):

            grph.insert( node_name (i,j) )

            if grid[i][j] == -14:
                start_node = node_name(i,j)
                grid[i][j] = 0
            if grid[i][j] == -28:
                end_node = node_name(i,j)
                grid[i][j] = 25

    # create all edges
    for i in range(1 , 1+n_rows):
        for j in range(1,1+n_cols):

            if (grid[i][j] - grid[i-1][j]) >= -1:
                grph.make_friends(node_name(i,j) , node_name(i-1,j) )
            if (grid[i][j] - grid[i+1][j]) >= -1:
                grph.make_friends(node_name(i,j) , node_name(i+1,j) )
            if (grid[i][j] - grid[i][j+1]) >= -1:
                grph.make_friends(node_name(i,j) , node_name(i,j+1) )
            if (grid[i][j] - grid[i][j-1]) >= -1:
                grph.make_friends(node_name(i,j) , node_name(i,j-1) )

    return grph , start_node , end_node, grid

def color_in_grid(grid,pathway):
    # strip off padded edge
    grid = grid[1:]  # remove top
    grid = grid[:-1] # remove bottom
    grid = [ gr[1:-1] for gr in grid]  # remove left/right
    
    num_rows = len(grid)
    num_cols = len(grid[0])

    def decode_name(p):
        nonlocal num_cols,num_rows
        num = int(p[2:])
        
        j = num % num_cols
        i = num // num_cols
        return i,j
    
    for p in pathway:
        i,j = decode_name(p)
        grid[i][j] = -1

    return np.array(grid)

import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors
import matplotlib.cm as cm
from time import time

def main():

    t1 = time()
    print("Starting data load-in and graph creation")
    myGraph , start_node_name , end_node_name , grid = load_data('aoc_1.txt',disp=0)

    t2 = time()
    print("Starting dijkstras")
    n,p = myGraph.best_path(start_node_name,end_node_name,disp=0)

    t3 = time()
    print("Done")

    print (f"{'Data loading time':18s} : {t2-t1:0.2f}s")
    print (f"{'Dijkstra time'    :18s} : {t3-t2:0.2f}s")

    # uncomment this to create a png image of the route
    # grid = color_in_grid(grid,p)
    # print("\n")

    # cmap = plt.cm.get_cmap("plasma")
    # custom_cm = {-1:(1.0,1.0,1.0,1.0)}
    # for i in range(26):
    #     custom_cm[i] = cmap(i/26)
    # grid2 = [ [custom_cm[g] for g in gr] for gr in grid]


    # plt.imshow(grid2)
    # plt.savefig("foo.png")

main()
