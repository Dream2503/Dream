from matrix import Matrix
from fractions import Fraction
from equation import Polynomial

m: Matrix = Matrix(3, 4, matrix=[
    [4, -8, 3, 16],
    [-1, 2, -5, -21],
    [3, -6, 1, 7],
])
m.echelon_form().print()

for element in m.gauss_elimination():
    print(element)

# poly = Polynomial("8x2 4", "4")
# print(poly)