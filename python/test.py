from matrix import Matrix

m: Matrix = Matrix(2, 3, matrix=[[2, -6, -11], [-3, 8, 10], [1, 0, 4]])
print(m.gauss_jordan_elimination())
