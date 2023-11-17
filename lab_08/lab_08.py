from argparse import ArgumentParser
import os

def load_graph(opt:int) -> list :
    '''Loads the graph from file. The first <size> values
    in the array show all the nodes that the first node (A) can
    connect to. The second <size> values show all the nodes that the
    second node (B) can connect to, etc.
    Assume that Connections are unidirectional and unweighted.

    @params: opt    select graph number to load from file
    '''

    #  pick the file
    if opt==0:
        size , fname = 3 , "file_0.txt"
    elif opt==1:
        size , fname = 6 , "file_1.txt"
    elif opt==2:
        size , fname = 10 , "file_2.txt"

    # prepend directory
    fullfilename = os.path.join(os.environ['SHARE'],'lab_08',fname)

    # init the graph with zeros
    graph = [[0 for _ in range(size)] for _ in range(size)]

    # read the values from the file into the graph
    with open(fullfilename) as f:
        for i in range(size):
            for j in range(size):
                graph[i][j] = int(f.readline())

    # return the graph
    return graph

def are_connected(graph:list, src:int , dst:int , disp:bool=False) ->bool:
    '''Determine whether there is a pathway from node <src> to
    node <dst>. Edge weights are either 0 (no connection) or 1 (connection).
    Optional input variable <disp> prints the result if True.
    Returns True if there is a pathway from src to dst.
    '''
    
    # init return value
    connected = False
    
    # nodes to be checked
    visited_src = [src]
    # nodes already checked
    handled_src = {}

    while (len(visited_src) > 0):
        # pop the first index of visited and put into handled
        current_src = visited_src.pop(0)
        handled_src[current_src] = True

        # if they match, break out of loop bc connected
        if current_src == dst:
            connected = True
            break

        # go through the whole source (column)
        for row in range(len(graph)):
            # only visit the nodes if they are = 1
            if graph[row][current_src] == 1:
                # if the row = dst, break out of loop bc connected
                if row == dst:
                    connected = True
                    break
                # if this specific row is not in handled, store in visited to be checked later
                if row not in handled_src:
                    visited_src.append(row)



    if disp:
        print(f"Node {src} {'is' if connected else 'isn''t'} connected to Node {dst}")

    #  return connection status (true/false)
    return connected

def display(graph:list) -> None:
    '''Displays the graph as a matrix. Column 0 shows all the places that 
    the 0th node (A) can connect to. Column 1 shows all the places that the 1th
    node (B) can connect to (etc).
    
    You don't need this function to solve the lab but you might find it helpful
    to visualize the matrix.
    '''

    s = len(graph)
    for i in range(s):
        for j in range(s):
            print(graph[i][j],end=" ")
        print("")

def get_opts() -> int:
    '''Retrieve commandline argument -> specify either 0, 1, or 2
    to determine which matrix gets loaded from file
    '''
    sizes = [3,6,10]

    # set up parser
    parser = ArgumentParser()
    parser.add_argument("opt",help="Matrix Number")
    parser.add_argument("src",help="Source Node")
    parser.add_argument("dst",help="Destination Node")

    # retrieve commandline arguments
    opts = parser.parse_args()
    opt = int(opts.opt)
    src = int(opts.src)
    dst = int(opts.dst)

    # check that commandline arguements are in appropriate ranges
    if not opt in [0,1,2]:
        raise ValueError("Specify matrix 0, 1, or 2")
    if not src in list(range(sizes[opt])):
        raise ValueError(f"Source node must be an integer between 0 and {sizes[opt]-1}")    
    if not dst in list(range(sizes[opt])):
        raise ValueError(f"Destination node must be an integer between 0 and {sizes[opt]-1}")    

    # return commandline arguements
    return opt , src , dst

def main():
    '''Main Function'''

    opt , src , dst = get_opts()
    graph = load_graph(opt)
    display(graph)
    are_connected(graph,src,dst,True)
    


main()
