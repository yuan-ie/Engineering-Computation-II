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
        # for-loop, go through all of the node (nd)'s names and see if the name matches with argument name
        for nd in self.nodes:
            if nd.name == name:
                # if match, return this node
                return nd
        # otherwise, node does not exist    
        return None

    def make_friends(self , name1:str , name2:str) ->None:

        # find the nodes with these names associated to it through find_node function
        node1 = self.find_node(name1)
        node2 = self.find_node(name2)

        # if the person does not exist
        if not node1:
            raise ValueError(f"{name1} not found")
        if not node2:
            raise ValueError(f"{name2} not found")

        # if both arguements are of the same person, return this message
        if node1==node2:
            raise ValueError("You can't be friends with yourself.")

        new_edge_1 = edge(node1,node2)
        new_edge_2 = edge(node2,node1)

        # append new edges to the graph's master list of edges
        self.edges.append(new_edge_1)
        self.edges.append(new_edge_2)

        node1.add_edge(new_edge_1)
        node2.add_edge(new_edge_2)

    def print_all_nodes(self , opt=0) -> None:
        for n in self.nodes:
            n.display(opt)

def main():

    myGraph = graph()
    myGraph.insert("Iyad")
    myGraph.insert("Joe")
    myGraph.insert("Bai")
    myGraph.insert("Helferty")
    myGraph.insert("Student R")
    myGraph.insert("Student S")
    myGraph.insert("Student T")

    # this creates an association between the two people
    myGraph.make_friends("Iyad","Joe")
    myGraph.make_friends("Iyad","Bai")
    myGraph.make_friends("Bai","Helferty")
    myGraph.make_friends("Bai","Joe")
    # iyad has 2 associations: joe and bai
    # joe has 2 associations: iyad and bai
    # etc.

    myGraph.make_friends("Student R" , "Student T")
    myGraph.make_friends("Student S" , "Student T")


    myGraph.print_all_nodes(opt=1)

main()