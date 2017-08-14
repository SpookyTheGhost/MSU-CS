import turtle
import time
import random

turtle.color(0,0,0)

def draw_circle(x,y,r,turtle,color):
    turtle.up()
    turtle.fillcolor(color)
    turtle.setheading(0)
    turtle.up()
    turtle.goto(x,y)
    turtle.down()
    turtle.begin_fill()
    turtle.circle(r)
    turtle.goto(x,y)
    turtle.end_fill()

draw_circle (0,0,160,turtle,'blue')
draw_circle (0,20,140,turtle,'white')
draw_circle (0,40,120,turtle,'green')
draw_circle (0,60,100,turtle,'white')
draw_circle (0,80,80,turtle,'red')



turtle.hideturtle()
time.sleep(30)
turtle.bye()
