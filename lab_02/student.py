# note -> delete the "pass" statements. Those are placeholders
# until you replace them with actual code

class student:

    def __init__(self):
        self.numGrade = 0
        self.grades_stored = []
        self.name = ""

    def set_name(self,name):
        self.name = name

    def add_grade(self,grade):
        self.grades_stored.append(grade)
        self.numGrade += 1
        

    def get_max(self):
        grade_max = max(self.grades_stored)
        return grade_max

    def get_average(self):
        total = sum(self.grades_stored)
        average = total / len(self.grades_stored)
        #average = total / self.numGrade #same thing as above
        return average

    def display(self):
        i = 0
        print(f"{self.name} : ", end="")
        for i in range(self.numGrade):
            #print(f"grade {i + 1} : {self.grades_stored[i]}") #for me to read easier
            print(f"{self.grades_stored[i]}, ", end="")
        print("\b\b  ")
        print() #new line


    
