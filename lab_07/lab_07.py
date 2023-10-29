''' lab_07.py

    Yuan Nghiem
    tul16619@temple.edu
    October 27, 2023

    Description:
    Implement a database that contains hash tables of students organized by first name, last name,
    and id.
    
    The following classes already exist:
        <linked_list>
        <student>
        <hash_table_base>
        <hash_table_firstname>

    The following classes have to be completed:
        <hash_table_lastname>
        <hash_table_id>
        <db>

    Usage:
    python lab_07.py TESTCASE
        where TESTCASE is either 1 or 2
    
    What to submit:
    The submit script will only submit lab_07.py   

'''

import argparse

class linked_list:
    '''standard linked list class'''

    class node:
        def __init__(self,data=None,next=None):
            self.data = data
            self.next = next
    
    def __init__(self):
        self.head = None

    def insert(self,value):
        new_node = self.node(data=value,next=self.head)
        self.head = new_node

    def lookup(self,target=None,field=None,disp=False):
        curr_ptr = self.head
        ret_val = []

        while (curr_ptr is not None):
            if hasattr(curr_ptr.data,field) and \
                getattr(curr_ptr.data,field) == target:
                    ret_val.append(curr_ptr.data)
            curr_ptr = curr_ptr.next

        if disp and ret_val:
            for r in ret_val:
                r.display()
        elif disp and not ret_val:
            print(field, "=" , target, " not found")

        return ret_val

class student:
    '''class of <student>'''

    def __init__(self,firstname="",lastname="",id=0,major=""):
        self.firstname = firstname
        self.lastname  = lastname
        self.id = id
        self.major = major
    def display(self):
        print(self.firstname , self.lastname , self.id , self.major)

class hash_table_base:
    '''basic hash table designed to be inherited'''

    def __init__(self , array_len = 50):
        self.buffer = [linked_list() for i in range(array_len)]
        self.array_len = array_len
    def insert(self,item):
        key = self.hash_function(item)
        self.buffer[key].insert(item)
    def hash_function(self,item=None,hash_item=None):
        return 0
    def lookup(self,item=None,disp=False):
        return None

class hash_table_firstname (hash_table_base):
    '''
    hash table of students organized by first name
    inherits <hash_table_base>
    '''
    # in the parameters, "item" is the inputted class object
    def hash_function(self, item=None, hash_item=None):
        if hash_item is None:
            hash_item = item.firstname
        s = 0
        for ch in hash_item:
            s += ord(ch)
        return s%self.array_len

    def lookup(self, target=None, disp=False):
        key = self.hash_function(hash_item=target)
        return self.buffer[key].lookup(target,"firstname",disp)

class hash_table_lastname (hash_table_base):
    '''hash table of students organized by last name'''

    def hash_function(self, item=None, hash_item=None):
        if hash_item is None:
            hash_item = item.lastname
        s = 0
        for ch in hash_item:
            s += ord(ch)
        return s%self.array_len

    def lookup(self, target=None, disp=False):
        key = self.hash_function(hash_item=target)
        return self.buffer[key].lookup(target,"lastname",disp)

class hash_table_id (hash_table_base):
    '''hash table of students organized by id number'''
    
    def hash_function(self, item=None, hash_item=None):
        if hash_item is None:
            hash_item = item.id
        s = 0
        for ch in str(hash_item):
            s += ord(ch)
        return s%self.array_len

    def lookup(self, target=None, disp=False):
        key = self.hash_function(hash_item=target)
        return self.buffer[key].lookup(target,"id",disp)

class db:
    '''database class that holds and manages multiple hash tables'''
    table_f_name = hash_table_firstname()
    table_l_name = hash_table_lastname()
    table_id     = hash_table_id()

def test_case_1():
    '''Test Case 1: test individual hash tables'''

    table_f_name = hash_table_firstname()
    table_l_name = hash_table_lastname()
    table_id     = hash_table_id()

    def insert(self, student):
        # f = student.firstname
        # l = student.lastname
        # id = student.id
        table_f_name.insert(student)
        table_l_name.insert(student)
        table_id.insert(student)
    
    # def lookup(self, )


    st1 = student( "Bob"  , "Smith" , 123 , "ECE"     )
    st2 = student( "Jeff" , "Smith" , 456 , "ME"      )
    st3 = student( "Jeff" , "Bezos" , 492 , "CompSci" )

    table_f_name.insert(st1)
    table_f_name.insert(st2)
    table_f_name.insert(st3)

    table_l_name.insert(st1)
    table_l_name.insert(st2)
    table_l_name.insert(st3)

    table_id.insert(st1)
    table_id.insert(st2)
    table_id.insert(st3)

    print("\nLookup ID = 123")
    table_id.lookup(123,disp=True)    

    print("\nLookup firstname = Jeff")
    table_f_name.lookup("Jeff",disp=True)

    print("\nLookup lastname = Bezos")
    table_l_name.lookup("Bezos",disp=True)

    print("\nLookup lastname = Smith")
    table_l_name.lookup("Smith",disp=True)

    print("\nLookup ID = 987")
    table_id.lookup(987,disp=True)

    print("")


    return

def test_case_2():
    '''Test Case 2: test database'''

    my_db = db()

    my_db.insert( student( "Bob"  , "Smith" , 123 , "ECE"     ) )
    my_db.insert( student( "Jeff" , "Smith" , 456 , "ME"      ) )
    my_db.insert( student( "Jeff" , "Bezos" , 492 , "CompSci" ) )

    my_db.lookup(last="Smith")
    my_db.lookup_first(first="Bob")
    my_db.lookup_id(id=989)

    return

def parse_inputs():
    '''parse command line inputs

    Do not edit this function

    ### Params
    * none

    ### Returns
    * parsed arguments
    '''
    
    parser = argparse.ArgumentParser(
    prog='Lab 7',
    description='Lab 7 Main Code')
    
    parser.add_argument('test_case' , help='1,2')

    args = parser.parse_args()
    return args

def main():

    args = parse_inputs()
    if args.test_case == '1':
        test_case_1()
        return

    if args.test_case == '2':
        test_case_2()
        return

    print("\n>>>>> Invalid test case specified at commandline <<<<< \n")
    raise SystemError


if __name__=="__main__":
    main()