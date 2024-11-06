from matrix import  Matrix

m = Matrix(3, 3, matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
print(m.eigen_values())
print(m.eigen_vectors())