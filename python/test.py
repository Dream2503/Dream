from matrix import Matrix

m: Matrix = Matrix(3, 3, matrix=[[2, 0, -1], [0, 0.5, 0], [1, 0, 4]])
print(m.eigen_values())
# print(m.eigen_vectors())