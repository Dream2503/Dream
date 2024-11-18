from matrix import Matrix

m = Matrix(3, 3, matrix=[[5, 10, -10], [10, 5, -20], [5, -5, -10]])
print(m.eigen_values())