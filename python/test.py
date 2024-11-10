from matrix import Matrix
m1 = Matrix(2, 2, matrix=[[9, 3], [-2, 0]])
m2 = Matrix(2, 2, matrix=[[1, -4], [2, 5]])

print(m1 * m2)
print(m2 * m1)