from matrix import Matrix
from fractions import Fraction
from equation import Polynomial, Variable

m: Matrix = Matrix(matrix=[
    [Fraction(18, 10), Fraction(-232, 100)],
    [Fraction(-25, 100), Fraction(6, 10)]
])
print(m.gauss_jordan_elimination().gauss_jordan_elimination() == m)

# poly = Polynomial("8x2 4", "4")
# print(poly)