from matrix import Matrix
from fractions import Fraction

m: Matrix[Fraction] = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
print(m.singular_value_decomposition())