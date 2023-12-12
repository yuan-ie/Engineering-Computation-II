from argparse import ArgumentParser
from classes import movies, actors, starring_roles
from hash_table import hash_table

'''
Name: Yuan Nghiem
Email: tul16619@temple.edu
Date: December 11, 2012

Objectives of Project 5:
    - store all the data into corresponding databases
    - be able to look up IDs to display actor/movie info
    - link the two databases by searching up the actor to display all the movies they starred in
'''


movie_database = hash_table()
actor_database = hash_table()
starring_roles_database = hash_table()


def get_opts():
    '''Get command line argument.'''

    # set up parser
    parser = ArgumentParser()
    parser.add_argument('option' , type=int, nargs='?', 
                        default=1, help="pig project section load option: 1, 2, 3, 4, 5, 6, 7, 8")

    # parse command line
    opts = parser.parse_args()
    option = opts.option

    #  input the section you want to look at
    if option not in [1,2,3]:
        raise ValueError("Specify section: 1, 2, 3")

    return option

'''------------------------------ MAIN -------------------------------------'''

def load_data(option):

    if option == 1:
        filename = "/data/courses/ece_3822/current/project_5_data/movies.tsv"
    elif option == 2:
        filename = "/data/courses/ece_3822/current/project_5_data/names.tsv"
    elif option == 3:
        filename = "/data/courses/ece_3822/current/project_5_data/starring_roles.tsv"
    
    if option == 1:
        with open(filename, 'r') as f:
            
            # create empty data list
            data = []
            # skips the first line
            next(f)
            # read the lines after the first line
            lines = f.readlines()

            # for each line
            for line in lines:
                # read only the words separated by tabs
                words = line.strip().split('\t')
                for word in words:
                    # store words for each line into data vector
                    data.append(word)
                
                # store movie information into database
                movie_database.insert(movies(data[0], data[2], data[5]))

                # pop the words from the data vector
                for word in words:
                    data.pop()
        f.close()

    elif option == 2:
        with open(filename, 'r') as f:
            
            # create empty data list
            data = []
            # skips the first line
            next(f)
            # read the lines after the first line
            lines = f.readlines()

            # for each line
            for line in lines:
                # read only the words separated by tabs
                words = line.strip().split('\t')
                for word in words:
                    # store words for each line into data vector
                    data.append(word)
                
                # store actor information into database
                actor_database.insert(actors(data[0], data[1], data[2], data[3]))

                # pop the words from the data vector
                for word in words:
                    data.pop()
        f.close()

    elif option == 3:
        # loads movie data into database
        load_data(1)
        # loads actor data into database
        load_data(2)

        with open(filename, 'r') as f:
            
            # create empty data list
            data = []
            # skips the first line
            next(f)
            # read the lines after the first line
            lines = f.readlines()

            # for each line
            for line in lines:
                # read only the words separated by tabs
                words = line.strip().split('\t')
                for word in words:
                    # store words for each line into data vector
                    data.append(word)
                
                # store actor information into database
                starring_roles_database.insert(starring_roles(data[0], data[2], data[5]))
                #actors(data[0], data[2], data[2], data[5]).display()
                

                # pop the words from the data vector
                for word in words:
                    data.pop()
        f.close()

# look up the actor and movies
def lookup_actor_starring_roles(id):
    # get a list of the actor with associated movies
    tmp = starring_roles_database.lookup_ID(id)
    print("Movies Starring: ",)

    # look up the ID of actor and display
    actor_database.lookup_ID(id)
    print()

    # look up the IDs of the movies and display
    for item in tmp:
        movie_database.lookup_ID(item.movie_ID)

'''------------------------------ MAIN -------------------------------------'''
            
def main():

    option = get_opts()
    load_data(option)

    print()
    
    # look up based on movie ID
    movie_database.lookup_ID("tt9916170")
    print()

    # look up based on actor ID
    actor_database.lookup_ID("nm0000112")
    actor_database.lookup_ID("nm0001884")
    print()

    print("---------------------------------------------------------------------")
    print()
    # look up based on actor ID and get the movies they star in
    lookup_actor_starring_roles("nm0000129")

main()