class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.x1 = int(input('enter the value for x1: '))
        self.y1 = int(input('enter the value for y1: '))

    def display(self):
        print('first point object: (' + str(self.x) + ', ' + str(self.y) + ') second point object: (' + str(
            self.x1) + ',' + str(self.y1) + ')')

    def distance(self):
        xcor_calc = (self.x - self.x1) ** 2
        ycor_calc = (self.y - self.y1) ** 2
        dist_calc = (xcor_calc + ycor_calc) ** (1 / 2)
        return dist_calc


coords1 = Point(3, 4)
coords1.display()
print('The distance between first point object and second point object is: ', coords1.distance())
