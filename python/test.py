from pprint import pprint

from matrix import Matrix
from fractions import Fraction

m: Matrix[Fraction] = Matrix(matrix=[[1, -1, 1], [-2, 2, -2]])
pprint(m.singular_value_decomposition())
print(m.pseudo_inverse().__repr__())