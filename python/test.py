from fractions import Fraction

from matrix import Matrix
from equation import Variable, Term

# m = Matrix(3, 3, matrix=[[5, 10, -10], [10, 5, -20], [5, -5, -10]])
# print(m.eigen_values())

var = Term("3x^3 -5x^2 2x -7")
print(var)
print(var.substitute("x", 2))