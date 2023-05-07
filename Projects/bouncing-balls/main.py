import sys
import pygame as py

class Ball:
    # Vector = [x cordinates, y cordinates, speed x speed y, size]
    def __init__(self, vector: list, screen) -> None:
        self.position = [vector[0], vector[1]]
        self.speed = [vector[2][0], vector[2][1]]
        self.radius = vector[3]
        self.color = (255, 255, 255)
        self.screen = screen
        self.size = 20

        self.draw()
    
    def draw(self):
        py.draw.circle(self.screen, self.color, self.position, self.size)

class Surface:
    def __init__(self, floorWidth, floorHeight, screenHeight):
        self.floorWidth = floorWidth
        self.floorHeight = floorHeight
        self.screenHeight = screenHeight
        self.surface = py.Surface((self.floorWidth, self.floorHeight))
        self.floorRectangle = self.surface.get_rect()
        
        self.coloring()
        self.floorPlacement()
    
    def coloring(self):
        self.surface.fill((255, 255, 255))  # fill with white color
        
    def floorPlacement(self):
        self.floorRectangle.bottom = self.screenHeight

def moveObj(ballObject, speed: list):
    ballObject.position[0] += speed[0]
    ballObject.position[1] += speed[1]

def gravity(velocity):
    gravityPull = 2
    return velocity - gravityPull

def bounce(velocity):
    return -velocity * 0.8


def overlap(ballObject, surfaceObject):
    return surfaceObject.floorRectangle.colliderect(py.Rect(*ballObject.position, ballObject.size, ballObject.size))


def game():
    pass

def main():
    py.init()
    # set the dimensions of the screen
    screen_width = 640
    screen_height = 480
    screen = py.display.set_mode((screen_width, screen_height))
    
    # draw the floor on the screen
    floor = Surface(screen_width, 100, screen_height)
    screen.blit(floor.surface, floor.floorRectangle)
    
    # Draw ball
    ball = Ball([screen_width / 2, 300, [0, 0], 2], screen)
    
    while True:
        # handle events
        for event in py.event.get():
            if event.type == py.QUIT:
                py.quit()
                sys.exit()
        if overlap(ball, floor):
            ball.speed[1] = bounce(ball.speed)
        ball.speed[1] = gravity(ball.speed[1])
        moveObj(ball, ball.speed)
        
        # fill screen with background color
        screen.fill((0, 0, 0))
        # redraw floor
        screen.blit(floor.surface, floor.floorRectangle)
        # redraw ball at its new position
        ball.draw()
        
        # update the screen
        py.display.update()

    

if __name__ == '__main__':
    main()
