''' lab_06.py

    YOUR NAME HERE
    YOUR EMAIL ADDRESS
    DATE

    Description:
    This file creates a hash table of <student>s and tests performance
    with some simple inserts and lookups in <main>.

    Usage:
    python lab_06.py
    
'''

#################################################################
class student:

    def __init__(self,last,first,zip,gpa):
        self.last  = last
        self.first = first
        self.zip   = zip
        self.gpa   = gpa

    def display(self):
        print(self.last, " ", self.first , " " , self.gpa , " " , self.zip)

#################################################################
class hash_table:

    # constructor
    def __init__(self,buff_len=10):
        self.buff_len = buff_len
        self.buffer = [None]*self.buff_len

    # all-important hash-function
    def hash_function(self , std=None , last=None , first=None):

        # if a student is provided as input, use names in student
        # for the hash function. otherwise use the provided first
        # and last names
        if std: last,first = std.last, std.first
        
        # concatenate the names
        total_name = last+first

        s = 0
        for c in total_name:
            s += ord(c)         # ord(c) converts c into ascii value
        
        index = s % self.buff_len
        return index
    
    # insert student into buffer
    def insert(self,std):
        index = self.hash_function(std=std)
        self.buffer[index] = std

    # look up a student in the hash table by, 'student' or 'first' and 'last'
    def lookup(self,last,first,display=False):
        target_student = None
        
        # display results if user requests it
        if display: 
            print("\n")
            print("Search result:" ,end=" ")
            if target_student: target_student.display()
            else: print(last,first, "not found")
            print("\n")

        return target_student

    # display contents of the buffer
    def display(self):
        print("\n")
        print("Displaying complete contents of hash table:")
        for i,s in enumerate(self.buffer):
            print(i,end=" ")
            if s:
                s.display()
            else:
                print("")            
        print("\n")

def main():

    # create the hash table
    my_table = hash_table(buff_len = 15)

    # create two new students and insert them into the hash table
    my_table.insert( student( "Obeid" , "Iyad" , 19143 , 3.99) )
    my_table.insert( student( "Obeid" , "Timmy", 19147 , 3.14) )

    # look up a student and display results
    my_table.lookup("Obeid","Iyad",display=True)

    # display contents of hash table
    my_table.display()


if __name__=="__main__":
    main()
