class Pet(object):
    def __init__(self,species=None,name=''):
        self.name=name
        self.species=species
        species_list = ['dog', 'cat','horse', 'gerbil', 'hamster', 'ferret', 'bird']
        if self.species.lower() in species_list:
            pass
        else:
            raise PetError ("Got a pet error.")

    def __str__(self):
        if self.name != '':
            return ('Species of: {:s}, named {:s}').format(self.species,self.name)
        else:
            return ('Species of: {:s}, unnamed').format(self.species)
        
class Dog(Pet):
    def __init__(self,name='',chases='Cats'):
        self.chases = chases
        Pet.__init__(self,'Dog',name)

    def __str__(self):
        Pet.__str__(self)
        if self.name != '':
            return ('Species of: Dog, named {:s} who chases {:s}').format(self.name,self.chases)
        else:
            return ('Species of: Dog, unnamed who chases {:s}').format(self.chases)

class Cat(Pet):
    def __init__(self,name='',hates='Dogs'):
        self.hates = hates
        Pet.__init__(self,'Cat',name)

    def __str__(self):
        Pet.__str__(self)
        if self.name != '':
            return ('Species of: Cat, named {:s} who hates {:s}').format(self.name,self.hates)
        else:
            return ('Species of: Cat, unnamed who hates {:s}').format(self.hates)

class PetError(Exception):
    pass
    
            



def demo():
    try:
        pet = Pet('horse')
        print(pet)   # -->
        dog = Dog('fido')
        print(dog)   # --> species of Dog, named fido who chases Cats
        cat = Cat('fluffy', 'everything')
        print(cat)   # --> species of Cat, named fluffy who hates everything
        pet = Pet('pig')   # raises a PetError
        print(pet)   
    except PetError:
        print("Got a pet error.")   # --> Got a pet error
demo()
