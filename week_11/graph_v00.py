class node:
    
    def __init__(self,name:str) ->None :
        self.name = name
        self.friends = []


class edge:

    def __init__(self , s:node , d:node , w:float=1) -> None :
        self.src = s
        self.dst = d
        self.wt  = w

class graph:

    def __init__(self) ->None :
        self.nodes = []
    
    def insert(self,name:str) -> None:
        new_node = node(name)
        self.nodes.append(new_node)

    def make_friends(self , name1:str , name2:str) ->None:
        node1 = self.find_node(name1)
        node2 = self.find_node(name2)
        new_edge_1 = edge(node1,node2)
        new_edge_2 = edge(node2,node1)
        node1.add_edge(new_edge_1)
        node2.add_edge(new_edge_2)

myGraph = graph()
myGraph.insert("Iyad")
myGraph.insert("Joe")
myGraph.insert("Bai")
myGraph.insert("Helferty")

myGraph.make_friends("Iyad","Joe")