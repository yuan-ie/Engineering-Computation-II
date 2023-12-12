class movies:
    def __init__(self, movie_ID = "", title = "", start_year = ""):
        self.id = movie_ID
        self.title = title
        self.yr = start_year
    def display(self):
        print("Movie: ", self.title, "| Year: ", self.yr)

class actors:
    def __init__(self, actor_ID = "", actor_name = "", year_birth = "", year_death = ""):
        self.id = actor_ID
        self.name = actor_name
        self.yr_birth = year_birth
        self.yr_death = year_death
    def display(self):
        if self.yr_death == "\\N":
            self.yr_death = "N/A"
        print("Actor: ", self.name, "| Year of Birth: ", self.yr_birth, "| Year of Death: ", self.yr_death)

class starring_roles:
    def __init__(self, movie_ID = "", actor_ID = "", characters=""):
        self.id = actor_ID
        self.movie_ID = movie_ID
        self.characters = characters
    def display(self):
        pass # don't want to do anything