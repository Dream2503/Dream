from math import sqrt, acos, degrees
class PointError(Exception): ...

class Point:
    def __init__(self, x: int | float = 0, y: int | float = 0, z: int | float = 0, *,
                 point: 'Point | Line' = None) -> None:
        if point is not None and isinstance(point, Point):
            self._x, self._y, self._z = point

        else:
            if all((isinstance(x, (int, float)), isinstance(y, (int, float)), isinstance(z, (int, float)))):
                self._x, self._y, self._z = x, y, z
            
            else:
                raise PointError('Invalid datatype for points')

        self._magnitude = None

    @property
    def x(self) -> int | float:
        return self._x

    @x.setter
    def x(self, value) -> None:
        if isinstance(value, (int, float)):
            self._x, self._magnitude = value, None

        else:
            raise PointError('Invalid datatype for coordinate value')

    @property
    def y(self) -> int | float:
        return self._y

    @y.setter
    def y(self, value) -> None:
        if isinstance(value, (int, float)):
            self._y, self._magnitude = value, None

        else:
            raise PointError('Invalid datatype for coordinate value')

    @property
    def z(self) -> int | float:
        return self._z

    @z.setter
    def z(self, value) -> None:
        if isinstance(value, (int, float)):
            self._z, self._magnitude = value, None

        else:
            raise PointError('Invalid datatype for coordinate value')

    @property
    def magnitude(self) -> float:
        if not self._magnitude:
            self._magnitude = round(sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2), 3)

        return self._magnitude

    def __add__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            return Point(self.x + value.x, self.y + value.y, self.z + value.z)

        elif isinstance(value, (int, float)):
            return Point(self.x + value, self.y + value, self.z + value)

        else:
            return NotImplemented

    def __sub__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            return Point(self.x - value.x, self.y - value.y, self.z - value.z)

        elif isinstance(value, (int, float)):
            return Point(self.x - value, self.y - value, self.z - value)

        else:
            return NotImplemented

    def __mul__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            return Point(self.x * value.x, self.y * value.y, self.z * value.z)

        elif isinstance(value, (int, float)):
            return Point(self.x * value, self.y * value, self.z * value)

        else:
            return NotImplemented

    def __truediv__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            return Point(round(self.x / value, 3),
                         round(self.y / value, 3),
                         round(self.z / value, 3))

        else:
            return NotImplemented

    def __floordiv__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            return Point(self.x // value, self.y // value, self.z // value)

        else:
            return NotImplemented

    def __mod__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            return Point(self.x % value, self.y % value, self.z % value)

        else:
            return NotImplemented

    def __pow__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            return Point(self.x ** value, self.y ** value, self.z ** value)

        else:
            return NotImplemented

    def __iadd__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            self.x += value.x
            self.y += value.y
            self.z += value.z
            return self

        elif isinstance(value, (int, float)):
            self.x += value
            self.y += value
            self.z += value
            return self

        else:
            return NotImplemented

    def __isub__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            self.x -= value.x
            self.y -= value.y
            self.z -= value.z
            return self

        elif isinstance(value, (int, float)):
            self.x -= value
            self.y -= value
            self.z -= value
            return self

        else:
            return NotImplemented

    def __imul__(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            self.x *= value.x
            self.y *= value.y
            self.z *= value.z
            return self

        if isinstance(value, (int, float)):
            self.x *= value
            self.y *= value
            self.z *= value
            return self

        else:
            return NotImplemented

    def __itruediv__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            self.x = round(self.x / value, 3)
            self.y = round(self.y / value, 3)
            self.z = round(self.z / value, 3)
            return self

        else:
            return NotImplemented

    def __ifloordiv__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            self.x //= value
            self.y //= value
            self.z //= value
            return self

        else:
            return NotImplemented

    def __imod__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            self.x %= value
            self.y %= value
            self.z %= value
            return self

        else:
            return NotImplemented

    def __ipow__(self, value: int | float) -> 'Point':
        if isinstance(value, (int, float)):
            self.x **= value
            self.y **= value
            self.z **= value
            return self

        else:
            return NotImplemented

    def __eq__(self, value: 'Point | Line') -> bool:
        if isinstance(value, Point):
            return self.x == value.x and self.y == value.y and self.z == value.z

        elif isinstance(value, (int, float)):
            return self.x == self.y == self.z == value

    def __str__(self) -> str:
        skip = False
        res = '\nPoint = '
        if self.x > 0:
            res += str(self.x) + 'i'

        elif self.x < 0:
            res += f'- {abs(self.x)}i'

        else:
            skip = True

        if skip:
            if self.y > 0:
                res += str(self.y) + 'j'

            elif self.y < 0:
                res += f'- {abs(self.y)}j'

        else:
            if self.y > 0:
                res +=f' + {self.y}j'

            elif self.y < 0:
                res += f' - {abs(self.y)}j'

            else:
                skip = False

        if skip:
            if self.z > 0:
                res += str(self.z) + 'k'

            elif self.z < 0:
                res += f'- {abs(self.z)}k'

        else:
            if self.z > 0:
                res += f' + {self.z}k'

            elif self.z < 0:
                res += f' - {abs(self.z)}k'

        if len(res) == 10:
            res += '0'
        
        return res + f'\nmagnitude = {self.magnitude}'

    def __getitem__(self, idx: int | slice) -> int | float: 
        return (self.x, self.y, self.z)[idx]

    __abs__ = lambda self: Point(abs(self.x), abs(self.y), abs(self.z))
    __radd__ = lambda self, value: self + value
    __rsub__ = lambda self, value: -(self - value)
    __rmul__ = lambda self, value: self * value
    __rtruediv__ = lambda self, value: 1 / (self / value)
    __rfloordiv__ = lambda self, value: 1 // (self // value)
    __rmod__ = lambda self, value: self % value
    __rpow__ = lambda self, value: self ** value
    __bool__ = lambda self: self.x != self.y != self.z != 0
    __pos__ = lambda self: self
    __neg__ = lambda self: self * -1
    __name__ = 'Point'
    __class__ = "<class 'Point'>"
    __repr__ = __call__ = lambda self: f'Point(x={self.x}, y={self.y}, z={self.z}, mod={self.mod})'

    def dot(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            return sum(self * value)

        else:
            raise PointError('Invalid datatype operation')

    def cross(self, value: 'Point | Line | int | float') -> 'Point':
        if isinstance(value, Point):
            return Point((self.y * value.z) - (self.z * value.y),
                         -(self.x * value.z) - (self.z * value.x),
                         (self.x * value.y) - (self.y * value.x))

        else:
            raise PointError('Invalid datatype operation')

    def distance(self, value: 'Point | Line') -> float:
        if isinstance(value, Point):
            return sqrt((value.x - self.x) ** 2 +
                        (value.y - self.y) ** 2 +
                        (value.z - self.z) ** 2)

        else:
            raise PointError('Invalid Point object')

    def unit_vector(self) -> 'Point':
        return (1 / self.magnitude) * self

    def projection(self, value: 'Point | Line') -> float:
        if isinstance(value, Point):
            projec = (1 / value.magnitude) * self.dot(value)
            return round(projec, 3)

        else:
            raise PointError('Invalid Point object')

    def angle_between(self, value: 'Point | Line') -> float:
        if isinstance(value, Point):
            res = degrees(acos(abs(self.dot(value) / (self.magnitude * value.magnitude))))
            return round(res, 1)

    def is_perpendicular(self, value: 'Point | Line') -> bool:
        if isinstance(value, Point):
            return (self.x * value.x +
                    self.y * value.y +
                    self.z * value.z) == 0

        else:
            raise PointError('Invalid Point object')

    def is_parallel(self, value: 'Point | Line') -> bool:
        if isinstance(value, Point):
            x = self.x / value.x
            y = self.y / value.y
            z = self.z / value.z
            return x == y == z

    line = lambda self: Line(line=self)
    direction_cosines = lambda self: (round(self.x / self.magnitude, 3),
                                      round(self.y / self.magnitude, 3),
                                      round(self.z / self.magnitude, 3))



class Line(Point):
    def __init__(self, point1: Point = Point(0, 0, 0),
                 point2: Point = Point(0, 0, 0), *,
                 line: 'Line | Point'  = None) -> None:
        if line is not None:
            self._x, self._y, self._z = line
            self._point1, self._point2 = Point(0, 0, 0), Point(point=line)

        else:
            if isinstance(point1, Point) and isinstance(point2, Point):
                self._point1, self._point2 = point1, point2
                self._x, self._y, self._z = self.point2 - self.point1

            else:
                raise PointError('Invalid Point object')

        self._magnitude = None
             
    @property
    def point1(self):
        return self._point1

    @point1.setter
    def point1(self, value):
        if isinstance(value, Point):
            self._point1, self.magnitude = value, None

        else:
            raise PointError('Invalid Point object')

    @property
    def point2(self):
        return self._point2

    @point2.setter
    def point2(self, value):
        if isinstance(value, Point):
            self._point2, self.magnitude = value, None

        else:
            raise PointError('Invalid Point object')

    @property
    def magnitude(self) -> float:
        if not self._magnitude:
            self._magnitude = round(sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2), 3)

        return self._magnitude       

    def __add__(self, value: 'Line | Point | int | float') -> 'Line':
        res = super().__add__(value)
        return Line(line=res)

    def __sub__(self, value: 'Line | Point | int | float') -> 'Line':
        res = super().__sub__(value)
        return Line(line=res)

    def __mul__(self, value: 'Line | Point | int | float') -> 'Line':
        res = super().__mul__(value)
        return Line(line=res)

    def __truediv__(self, value: int | float) -> 'Line':
        res = super().__truediv__(value)
        return Line(line=res)

    def __floordiv__(self, value: int | float) -> 'Line':
        res = super().__floordiv__(value)
        return Line(line=res)

    def __mod__(self, value: int | float) -> 'Line':
        res = super().__mod__(value)
        return Line(line=res)

    def __pow__(self, value: int | float) -> 'Line':
        res = super().__pow__(value)
        return Line(line=res)

    def __iadd__(self, value: 'Point | Line | int | float') -> 'Line':
        res = super().__iadd__(value)
        return Line(line=res)

    def __isub__(self, value: 'Point | Line | int | float') -> 'Line':
        res = super().__isub__(value)
        return Line(line=res)

    def __imul__(self, value: 'Point | Line | int | float') -> 'Line':
        res = super().__imul__(value)
        return Line(line=res)

    def __itruediv__(self, value: int | float) -> 'Line':
        res = super().__itruediv__(value)
        return Line(line=res)

    def __ifloordiv__(self, value: int | float) -> 'Line':
        res = super().__ifloordiv__(value)
        return Line(line=res)

    def __imod__(self, value: int | float) -> 'Line':
        res = super().__imod__(value)
        return Line(line=res)

    def __ipow__(self, value: int | float) -> 'Line':
        res = super().__ipow__(value)
        return Line(line=res)

    def __str__(self) -> str:
        return '\nLine' + super().__str__()[6:]

    def __repr__(self) -> str:
        return 'Line' + super().__repr__()[5:]

    def section_internal(self, ratio1, ratio2) -> 'Line':
        if isinstance(ratio1, (int, float)) and isinstance(ratio2, (int ,float)):
            return (ratio1 * self.point2) + (ratio2 * self.point1) / (ratio1 + ratio2)

        else:
            raise PointError('Invalid ratio types')

    def section_external(self, ratio1, ratio2) -> 'Line':
        if isinstance(ratio1, (int, float)) and isinstance(ratio2, (int ,float)):
            return (ratio1 * self.point2) - (ratio2 * self.point1) - (ratio1 + ratio2)

        else:
            raise PointError('Invalid ratio types')

    def shortest_distance(self, value: 'Line') -> 'Line':
        if isinstance(value, Line):
            a1, a2, b1, b2 = self.point1, value.point1, self.point2, value.point2
            if b1 == b2:
                res = (b1.cross(a2 -a1) / b1.magnitude).magnitude

            else:
                b1xb2 = b1.cross(b2)
                res = (b1xb2.dot(a2 -a1)) / b1xb2.magnitude

            return round(abs(res), 3)

        else:
            raise PointError('Invalid Point object')

    point = lambda self: Point(point=self)
    dot = lambda self: self.point1.dot(self.point2)
    cross = lambda self: self.point1.cross(self.point2)
    direction_cosines = lambda self: (round((self.point2.x - self.point1.x) / self.magnitude, 3),
                                      round((self.point2.y - self.point1.y) / self.magnitude, 3),
                                      round((self.point2.z - self.point1.z) / self.magnitude, 3))