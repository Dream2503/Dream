from matrix import Matrix
from equation import Variable

# m = Matrix(3, 3, matrix=[[5, 10, -10], [10, 5, -20], [5, -5, -10]])
# print(m.eigen_values())

var = Variable("5x1^2x2^3")
print(var)
print(var.substitute("x1", 2))