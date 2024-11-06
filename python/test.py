from matrix import  Matrix

m = Matrix(3, 3, matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
m.gauss_jordan_elimination().print()