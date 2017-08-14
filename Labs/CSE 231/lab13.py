import math
class vector(object):
    def __init__(self,x=0,y=0):
        '''defines all parameters'''
        self.x=x
        self.y=y
    def __str__(self):
        '''returns a string. 2 decimals'''
        return str(round(self.vector,2))   
    def __repr__(self):
        '''returns a string'''
        return repr(self.vector) 
    def __add__(self,vector):
        '''adds vectors together'''
        vector = (int(self.x)+int(vector.x), int(self.y)+int(vector.y))
        return vector
    def __sub__(self,vector):
        '''subtracts vectors'''
        return (int(self.x)-int(vector.x),int(self.y)-int(vector.y))
    def __mul__(self,vector):
        return (self.x*vector.x,self.y*vector.y)
    def __rmul__(self,vector):
        return self.__mul__(vector)
    def __eq__(self,vector):
        if self.x == vector.x and self.y == vector.y:
            return True
        else:
            return False
    def magnitude(self):
        magnitude=math.hypot(self.x,self.y)
        return magnitude
    def unit(self):
        '''turns into unit vector'''
        try:
            magnitude = self.x*(1/self.x) and self.y*(1/self.y)
            return magnitude*(1/magnitude)
        except ZeroDivisionError:
            print('Cannot convert zero vector to a unit vector')

def main():
    v1 = vector(2,2)
    v2 = vector(5,6)
    print('subtracting vectors: ',v2.__sub__(v1))
    print('adding vectors: ',v1.__add__(v2))
    print('multiplying vectors: ',v1.__mul__(v2))
    print('are the vectors equal?: ',v1.__eq__(v2))
    print('magnitude of vector 1: ',v1.magnitude())
    print('magnitude of vector 2: ',v2.magnitude())
    print('unit vector 1: ',v1.unit())
    print('unit vector 2: ',v2.unit())
main()



    
