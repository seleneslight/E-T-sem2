import math
class Triangle():
    def __init__(self, side):
        self.parameters = dict(side=side)

    def area(self):
        s = self.parameters['side']
        return (math.sqrt(3.0)/4.0)*(s**2)
    def perimeter(self):
        s = self.parameters['side']
        return 3.0*s
    def info(self):
        print(f'Class name: {self.__class__.__name__}')
        print(f'Parameters: {self.parameters}')
        print(f'Area: {self.area()}, Perimeter: {self.perimeter()}')
