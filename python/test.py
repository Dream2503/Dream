from matrix import Matrix

m = Matrix(3, 3, matrix=[[5, 10, -10], [10, 5, -20], [5, -5, -10]])
print(m.eigen_values())
m.eigen_vectors()

# var = Polynomial("3x^3 -5x^2 2x -7")
# print(var)
# print(var.substitute("x", 2))