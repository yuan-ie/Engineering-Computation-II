''' lab_06.py

    Yuan Nghiem
    tul16619@temple.edu
    October 22, 2023

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

        # note: checks if std exists before it sets a value to it
        if std: last,first = std.last, std.first

        # checks for CAPS and return with all lowercase
        last, first = self.caps_check(std.last, std.first)
        
        # concatenate the names
        total_name = last+first

        s = 0
        for c in total_name:
            # ord(c) converts c into ascii value
            s += ord(c)        

        # print(s) # check if the total sum is correct
        
        index = s % self.buff_len
        return index
    
    # checks for CAPS and return with all lowercase
    def caps_check(self, last, first):
        last_checked = ""
        first_checked = ""

        for c in last:
            # ord(c) converts c into ascii value
            ascii = ord(c)

            # make it case insensitive
            # capital ascii starts from 65 (A) to 90 (Z)
            # if ascii value is between this range, add 32 to be lowercase equivalent
            if (ascii > 64 and ascii < 91):
                ascii = ascii + 32
            # convert the ascii value back to character
            last_checked += chr(ascii)
        for d in first:
            # ord(c) converts c into ascii value
            ascii = ord(d)

            # make it case insensitive
            # capital ascii starts from 65 (A) to 90 (Z)
            # if ascii value is between this range, add 32 to be lowercase equivalent
            if (ascii > 64 and ascii < 91):
                ascii = ascii + 32
            # convert the ascii value back to character
            first_checked += chr(ascii)
        return last_checked, first_checked

    # check if any collision when inserting student info
    def if_collision(self , key, std):
        k = 0 # flag
        while (self.buffer[key] is not None):
            
            # CAP check first and last names
            last1, first1 = self.caps_check(std.last, std.first)
            last2, first2 = self.caps_check(self.buffer[key].last, self.buffer[key].first)
            # if the names match, stay in the same index
            if ((first2==first1) and (last2==last1)):
                k = 1 # (do not enter new student if student exists)
                break # end loop and return index

            # otherwise, move onto next index
            key = (key + 1) % self.buff_len
        return key, k

    # insert student into buffer
    def insert(self,std):

        index = self.hash_function(std=std)
        index, k = self.if_collision(index,std)

        # if student exists already, then don't overwrite
        if k == 1:
            print("Student Info is already added to system with index: ", index)
        else:
            self.buffer[index] = std

    # look up a student in the hash table by, 'student' or 'first' and 'last'
    def lookup(self,last,first,display=False):

        target_student = None
        count = 0 # if student DNE, the loop only checks at a maximum of table size so it doesn't go on forever

        # create a temporary student info
        tmp_student = student(last, first, None, None)

        # get the index for this student
        key= self.hash_function(tmp_student)
            
        # look through the hash table with given index and increment if the name is not there (just in case)
        if self.buffer[key]:
            # get the first and last names as all lowercase
            last, first = self.caps_check(last, first)
            last2, first2 = self.caps_check(self.buffer[key].last, self.buffer[key].first)

            # checking if it matches
            # print(last,first)
            # print(last2,first2)

            # if it doesn't match, go to next index
            # (keep incrementing until matches OR if it increments table-size number of times)
            while ((first2==first and last2==last) == False):
                key = (key + 1) % self.buff_len
                #print(key)
                count += 1 
                
                # if index is not empty, CAP check the first and last name
                if self.buffer[key]:
                    last2, first2 = self.caps_check(self.buffer[key].last, self.buffer[key].first)
                
                # if count reaches table-size number, end the loop -> student DNE
                if count == self.buff_len:
                    break

            # after loop, if names match, set equal to target student
            if ((first2==first) and (last2==last)):
                target_student = self.buffer[key]
            # otherwise, student DNE
        
        # display results if user requests it
        # if display is inserted with "True"
        if display: 
            print("\n")
            print("Search result:" ,end=" ")

            # if target student is not null:
            if target_student: target_student.display()
            else: print(last,first, "not found")
            #print("\n")

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
    my_table.insert( student( "Obeid" , "dayi", 19147 , 3.14) ) # your name (reversed order first name)
    my_table.insert( student( "Nghiem" , "Yuan", 19148 , 4.00) ) # my name

    my_table.insert( student( "nghiem" , "yuan", 19148 , 3.14) ) # my name (with lowercase only; does not overwrite)
    my_table.insert( student( "Nghiem" , "Ytam", 19148 , 3.14) ) # my name (arbitrarily messed up #1)
    my_table.insert( student( "Nghiem" , "Ytan", 19147 , 3.14) ) # my name (arbitrarily messed up #2)
    my_table.insert( student( "Nghiem" , "Ytbm", 19147 , 3.14) ) # my name (arbitrarily messed up #3)
    my_table.insert( student( "Nghiem" , "Ytcm", 19147 , 3.14) ) # my name (arbitrarily messed up #4)
    

    # look up a student and display results
    my_table.lookup("Obeid","Iyad",display=True)
    my_table.lookup("nghiem","yuan",display=True) # my name (all lowercase)
    my_table.lookup("Nghiem","Ryan",display=True) # my brother DNE
    my_table.lookup("Yuan","Nghiem",display=True) # my name (reversed order) DNE
    my_table.lookup("Nghiem","nauy",display=True) # my name (reversed order first name) DNE
    my_table.lookup("Nghiem","Yuan",display=True) # my name (first letter capital)
    my_table.lookup("NGHIEM","YUAN",display=True) # my name (all capital)
    my_table.lookup("Nghiem","Ytcm",display=True) # my name (arbitrarily messed up #4)
    

    # display contents of hash table
    my_table.display()


if __name__=="__main__":
    main()
