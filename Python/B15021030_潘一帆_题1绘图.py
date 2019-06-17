import turtle
import time

def yinyang():
    turtle.goto(0,0)
    turtle.pencolor("black")
    turtle.fillcolor("black")
    turtle.pensize(3)
    turtle.speed(10)
    turtle.seth(0)
    turtle.up()
    turtle.goto(0,-200)
    turtle.fill(1)
    turtle.down()
    turtle.circle(200,-180,60)
    turtle.seth(0)
    turtle.circle(-100,180,60)
    turtle.circle(100,180,60)
    turtle.fill(0)
    turtle.circle(200,180,60)
    turtle.up()
    turtle.goto(0,100)
    turtle.dot(50,"white")
    turtle.goto(0,-100)
    turtle.dot(50,"black")
    turtle.goto(-80,-250)
    turtle.write("Yin Yang diagram is completed!")
    turtle.seth(0)


    
def ring():
    turtle.colormode(255)
    turtle.up()
    turtle.goto(-100,0)
    turtle.color(0,107,176)
    turtle.pensize(3)
    turtle.speed(10)
    turtle.down()
    turtle.circle(40,360,80)
    turtle.up()
    turtle.goto(0,0)
    turtle.color(29,24,21)
    turtle.down()
    turtle.circle(40,360,80)
    turtle.up()
    turtle.goto(100,0)
    turtle.down()
    turtle.color(220,47,31)
    turtle.circle(40,360,80)
    turtle.up()
    turtle.goto(-50,-40)
    turtle.color(239,169,13)
    turtle.down()
    turtle.circle(40,360,80)
    turtle.up()
    turtle.goto(50,-40)
    turtle.color(5,147,65)
    turtle.down()
    turtle.circle(40,360,80)
    turtle.up()
    turtle.goto(-70,-130)
    turtle.color("red")
    turtle.down()
    turtle.write("Olympic rings are completed!")
    turtle.up()


def paint(ang,r,ang2):
    turtle.seth(ang)
    turtle.circle(r,ang2)

def rose():
    turtle.goto(0,0)
    turtle.speed(3)
    turtle.color("white") 
    turtle.pensize(7)
    turtle.dot(200,"pink")
    turtle.up()
    turtle.goto(30,130)
    turtle.down()
    turtle.seth(180)
    ang=200
    r=200
    ang2=98
    for j in range (13):
        paint(ang,r,ang2) 
        paint(ang+ang2-180,-r,ang2*2/3)
        ang2=ang2-4
        ang=ang+58
        r=r*0.9
    turtle.up()
    turtle.goto(-60,-170)
    turtle.color("red") 
    turtle.write("A beautiful rose is completed!")

yinyang()
time.sleep(3)
turtle.clear()
ring()
time.sleep(3)
turtle.clear()
rose()
turtle.done()

