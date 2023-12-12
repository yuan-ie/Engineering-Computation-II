from classes import movies, actors

class hash_table:

    # constructor
    def __init__(self,buff_len=50000):
        self.buff_len = buff_len

        # buffer is a list that contains other buffers(lists)
        self.buffer = [[] for _ in range(self.buff_len)]

    # all-important hash-function
    def hash_function(self, item=None):

        # note: checks if id exists before it sets a value to it
        if item: id = item.id

        i = 1
        s = 0

        # add all the characters together
        for c in id:
            # ord(c) converts each character into ascii value
            s += ord(c) * i
            i += 1

        # print(s) # check if the total sum is correct
        index = s % self.buff_len
        
        return index

    # insert data into buffer
    def insert(self,item=None):
        if item is not None:
            exist = False
            # get the index through the hash function
            index = self.hash_function(item)
            self.buffer[index].append(item)

            # # check if the item already exists in the list
            # for i in range(len(self.buffer[index])):
            #     if self.buffer[index].id == item.id:
            #         print("Info is already added to system with index:", index)
            #         exist = True
            #         break
            # if exist == False:
            #     self.buffer[index].append(item)

    # look up item in the hash table by, 'movie' or 'first' and 'last'
    def lookup_ID(self, id=None):
        tmp_list = []
        match = 0

        # reformat to lowercase
        id = id.lower()

        # create a temporary item with the same ID
        if id is not None:
            if id[0] == "t":
                item = movies(movie_ID=id)
            elif id[0] == "n":
                item = actors(actor_ID=id)

        # get the index for this ID
        index = self.hash_function(item)
        
        # look through the hash table with given index
        for i in range(len(self.buffer[index])):            
            # if it doesn't match, go to next index
            if self.buffer[index][i].id == item.id:
                match = 1
                self.buffer[index][i].display()
                tmp_list.append(self.buffer[index][i])

        # if there is no match, print not found
        if match == 0:
            print(item.id, "not found")

        return tmp_list  