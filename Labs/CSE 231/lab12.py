import turtle
import time
class circle(object):
    def __init__(self,x=50,y=50,radius=25,color=''):
        self.x=x
        self.y=y
        self.radius=radius
        self.color=color

    def draw(self,turtle,x,y ,radius = 50,color=''):
        """draw circle with given radius using turtle"""
##        turtle.pencolor=('black')
        turtle.fillcolor(color)
        turtle.begin_fill()
        turtle.up()
        turtle.goto(x,y)
        turtle.down()
        turtle.circle(float(radius))
        turtle.end_fill()
       
class triangle(object):
    def __init__(self,x1=0,y1=0,x2=50,y2=50,x3=0,y3=0,color=''):
        self.x1=x1
        self.y1=y1
        self.x2=x2
        self.y2=y2
        self.x3=x3
        self.y3=y3
        self.color=color

    def draw(self,turtle,x1,y1,x,y2,x3,y3,color=''):
        turtle.pencolor('black')
        turtle.fillcolor(color)
        turtle.begin_fill()
        turtle.goto(x1,y1)
        turtle.left(60)
        turtle.forward(100)
        turtle.right(120)
        turtle.forward(100)
        turtle.goto(x3,y3)
        turtle.end_fill()
        
        
class rectangle(object):
    def __int__(self,x1=50,y1=50,x2=-50,y2=-50,line_color=''):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.line_color= line_color

        
    
    def draw_rectangle(self,x1=50,y1=50,x2=-50,y2=-50,line_color=''):

        turtle.pencolor("black")
        turtle.fillcolor('')
        turtle.begin_fill()
        turtle.up()
        turtle.goto(50,50)
        turtle.down()
        turtle.forward(100)

        turtle.right(90)
        turtle.forward(50)
        turtle.right(90)
        turtle.forward(100)
        turtle.right(90)
        turtle.forward(50)
            
        turtle.end_fill()           

draw_circle=circle()
draw_circle.draw(turtle,50,50,50,'red')
print(draw_circle)

draw_triangle=triangle()
draw_triangle.draw(turtle,50,50,100,100,50,50,'blue')
print(triangle)

##draw_rectangle=rectangle()
##draw_rectangle.draw_rectangle(turtle,50,50,50,'green')
##print(rectangle)
