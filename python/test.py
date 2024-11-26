from matrix import Matrix
from fractions import Fraction
from equation import Polynomial, Variable

a = Matrix(matrix=[
    [1, 2],
    [2, 4]
])

print("Eigen Values of A:", a.eigen_values())
a.diagonalize().print()
