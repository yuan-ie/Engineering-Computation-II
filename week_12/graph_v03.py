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

    def djk(self, n_src : node , n_dst : node):

        # dictionary of node statuses statusi statums
        INF = int(1e6)
        d = {}
        for nd in self.nodes:
            d[nd.name] = [INF , False , '']

        # sets starting node completed-status to "true" with distance 0
        curr_node_name = n_src.name
        curr_node_dist = 0
        d[curr_node_name] = [0 , True , curr_node_name]

        # keep going until dictionary shows that destination node has been completed
        while d[n_dst.name][1] == False :

            # visit each neighbor of curr_node_name and update distance
            # if new distance is shorter than exisiting distance
            curr_node = self.find_node(curr_node_name)
            for edg in curr_node.friends:
                
                # new route to edg.dst
                dist = curr_node_dist + edg.wt

                # if new route is better than whatever we had before
                if dist < d[edg.dst.name][0]:
                    d[edg.dst.name][0] = dist
                    d[edg.dst.name][2] = curr_node_name


            # find the new curr_node by locating <incomplete> node with shortest
            # distance
            best_node_name , best_dist = '', INF
            for node_name in d.keys():
                if d[node_name][0] < best_dist and d[node_name][1] == False:
                    best_node_name = node_name
                    best_dist = d[node_name][0]

            curr_node_name = best_node_name
            curr_node_dist = best_dist
            d[curr_node_name][1] = True

        n = d[n_dst.name][0]
        p = []
        nm = n_dst.name
        p.append(nm)
        while (nm != n_src.name):

            # awesome way, not for losers
            # walrus notation
            p.append(nm := d[nm][2] )

            # lame way
            # prev = d[nm][2]
            # p.append(prev)
            # nm = prev            

        # reverse list front to back
        p = p[::-1]
        return n,p

    def best_path(self , name1:str, name2:str , disp:int = 0):

        #  find nodes corresponding to src and dst
        node_src = self.find_node(name1)
        node_dst = self.find_node(name2)

        #  conduct dijkstras
        n,p = self.djk(node_src , node_dst)

        # display results if so requested
        if disp==1:
            print("\nbest path" ,  name1 , " --> " , name2 , "is" , str(n) , "units")
            print(p)
        #  return all
        return n,p

def main():

    myGraph = graph()

    # create nodes a, b, c, ... x , y (25 in all)
    for i in range(25):
        myGraph.insert( chr(i+ord('a')) )

    '''
    a       b       c       d       e
    f       g       h       i       j
    k       l       m       n       o
    p       q       r       s       t
    u       v       w       x       y
    '''

    # load weights in from file and create edges
    with open("graph.txt","r") as f:
        lines = f.readlines()
    
    for line in lines:
        src, dst , wt = line.split()
        wt = int(wt)
        myGraph.make_friends(src,dst,wt)

    # n will be the numerical value of the shortest path
    # path will be a list of names of nodes
    myGraph.best_path("a","y" , disp=1)
    myGraph.best_path("y","a" , disp=1)
    print("\n")


main()