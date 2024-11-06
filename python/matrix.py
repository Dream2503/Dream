from typing import Literal, Callable, Any
from fractions import Fraction
from equation import Term
from math import gcd, lcm
class MatrixError(Exception): ...

class Matrix:
    """
# INITIALIZING MATRIX OBJECT
    -> using input method
        >>> m = Matrix(2, 3, "input")           # this is a matrix with 2 rows and 3 columns
        Enter row (space-separated values): 1 2 3
        Enter row (space-separated values): 4 5 6
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Frqction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> providing a valid nested list and convert it to matrix
        >>> m = Matrix(2, 3, matrix=[[1, 2, 3], [4, 5, 6]])     # here matrix= is keyword only argument
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[1, 2, 3], [4, 5, 6]]

    -> by providing a type of matrix to generate
        -> null matrix
            >>> m = Matrix(3, 3, "null")        # creating a null matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

        -> identity matrix
            >>> m = Matrix(3, 3, "identity")    # creating an identity matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
            type = identity

# USING OPERATORS BETWEEN MATRIX AND NUMERIC TYPES
    -> consider the following matrices and one integer throughout the section
        >>> m1 = Matrix(2, 2, matrix=[[1, 2], [3, 4]])
        >>> m2 = Matrix(2, 2, matrix=[[5, 6], [7, 8]])
        >>> num = 7

        -> addition between matrix and numeric types
            >>> m1 + m2
            Matrix(rows=2, columns=2, matrix=[[6, 8], [10, 12]])

        -> subtraction between matrix and numeric types
            >>> m1 - m2
            Matrix(rows=2, columns=2, matrix=[[-4, -4], [-4, -4]])

        -> multiplication between matrix and numeric types
            >>> m1 * m2
            Matrix(rows=2, columns=2, matrix=[[19, 22], [43, 50]])

            >>> m1 * num
            Matrix(rows=2, columns=2, matrix=[[7, 14], [21, 28]])

# USING IN-PLACE OPERATOR
    -> consider the following matrices and one integer throughout the section
    -> matrices are all redefined after every operation to keep the initial value constant throughout the operations
        >>> m1 = Matrix(2, 2, matrix=[[1, 2], [3, 4]])
        >>> m2 = Matrix(2, 2, matrix=[[5, 6], [7, 8]])
        >>> num = 7

        -> in-place addition between matrix and numeric types
            >>> m1 += m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[6, 8], [10, 12]])

        -> in-place subtraction between matrix and numeric types
            >>> m1 -= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[-4, -4], [-4, -4]])

        -> in-place multiplication between matrix and numeric types
            >>> m1 *= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[30, 112], [90, 224]])

            >>> m1 *= num
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[7, 14], [21, 28]])

        -> checking equality between matrix
            >>> m1 == m2
            False

        -> absolute value of matrix         # making the matrix negative with multiplying with -1
            >>> m1 *= -1
            >>> abs(m1)
            Matrix(rows=2, columns=2, matrix=[[1, 2], [3, 4]])

        -> checking if an element is in matrix
            >>> 4 in m1
            True

            >>> 5 in m1
            False

        -> checking truth value of a matrix
            >>> m = Matrix(2, 2, "null")
            >>> bool(m)
            False

            >>> bool(m1)
            True

#ACCESSING ELEMENT OF A MATRIX
    -> consider the following matrix for this session
        >>> m = Matrix(2, 3, matrix=[[1, 2, 3], [4, 5, 6]])

        -> using index
            >>> m[1]
            [4, 5, 6]

            >>> m[1][2]
            6

        -> iterating using for loop
            >>> for row in m:
            ...     print(row)
            ...
            [1, 2, 3]
            [4, 5, 6]

            >>> for row in m:
            ...     for element in row:
            ...         print(element, end=", ")
            ...
            1, 2, 3, 4, 5, 6,

# CHECKING IF A MATRIX IS SYMMETRIC MATRIX
    >>> m = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.is_symmetric()
    True

    >>> m = Matrix(3, 3, matrix=[[0, 1, -2], [-1, 0, 3], [2, -3, 0]])
    >>> m.is_symmetric()
    False


# CHECKING IF A MATRIX IS SKEW SYMMETRIC MATRIX
    >>> m = Matrix(3, 3, matrix=[[0, 1, -2], [-1, 0, 3], [2, -3, 0]])
    >>> m.is_skew_symmetric()
    True

    >>> m = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.is_skew_symmetric()
    False

# USING THE MATRIX PRINT FUNCTION
    >>> m = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.print()
    [1, 1, -1]
    [1, 2, 0]
    [-1, 0, 5]

# FINDING TRANSPOSE OF A MATRIX
    >>> m = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.transpose()
    Matrix(rows=3, columns=3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    """

    def __init__(self, rows: int, columns: int, method: Literal["input", "null", "identity", "pass"] = "pass", *,
                 matrix: list[list[Any]] = None) -> None:

        if rows < 0 or columns < 0:
            raise MatrixError("Row or column of a matrix cannot be negative")

        self._order = (rows, columns)

        if method == "input":
            self._input()._validate()

        elif method == "null":
            self._null()

        elif method == "identity":
            self._identity()

        elif method == "pass":
            self._matrix = [row.copy() for row in matrix]
            self._validate()

    @property
    def order(self) -> tuple[int, int]:
        return self._order

    @property
    def matrix(self) -> list[list[Fraction]]:
        return self._matrix

    def __add__(self, other: "Matrix") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order == other.order:
                result = Matrix(self.order[0], self.order[1], "null")

                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        result.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __sub__(self, other: "Matrix") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order == other.order:
                result = Matrix(self.order[0], self.order[1], "null")

                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        result.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __mul__(self, other: "Matrix | Fraction") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order[1] == other.order[0]:
                result = Matrix(self.order[0], other.order[1], "null")

                for k in range(self.order[0]):
                    for i in range(other.order[1]):
                        for j in range(self.order[1]):
                            result.matrix[k][i] += self.matrix[k][j] * other.matrix[j][i]

                return result

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        try:
            other = Fraction(other)
            result = Matrix(self.order[0], self.order[1], "null")

            for i in range(self.order[0]):
                for j in range(self.order[1]):
                    result[i][j] = self.matrix[i][j] * other

            return result

        except ValueError:
            return NotImplemented

    def __iadd__(self, other: "Matrix") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        self.matrix[i][j] += other.matrix[i][j]

                return self

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __isub__(self, other: "Matrix") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.order[0]):
                    for j in range(self.order[0]):
                        self.matrix[i][j] -= other.matrix[i][j]

                return self

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __imul__(self, other: "Matrix | Fraction") -> "Matrix":
        if isinstance(other, Matrix):
            if self.order[1] == other.order[0]:
                for k in range(self.order[0]):
                    for i in range(other.order[1]):
                        for j in range(self.order[1]):
                            self.matrix[k][j] *= other.matrix[j][i]

                return self

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        else:
            try:
                other = Fraction(other)

                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        self.matrix[i][j] *= other

            except ValueError:
                return NotImplemented

    def __abs__(self) -> "Matrix":
        result = Matrix(self.order[0], self.order[1], "null")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                result.matrix[i][j] = abs(self.matrix[i][j])

        return result

    def __contains__(self, item: Fraction) -> bool:
        for row in self.matrix:
            for element in row:
                if element == item:
                    return True

    def __iter__(self) -> list[Fraction]:
        for row in self.matrix:
            yield row

    __radd__: Callable[["Matrix", "Matrix"], "Matrix"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Matrix", "Matrix"], "Matrix"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Matrix", "Matrix | Fraction"], "Matrix"] = lambda self, other: self.__mul__(other)
    __bool__: Callable[["Matrix"], bool] = lambda self: self.type != "null"
    __pos__: Callable[["Matrix"], "Matrix"] = lambda self: self
    __neg__: Callable[["Matrix"], "Matrix"] = lambda self: self.__mul__(-1)
    __eq__: Callable[["Matrix", "Matrix"], bool] = lambda self, other: self.matrix == other.matrix\
        if isinstance(other, Matrix) else NotImplemented
    __getitem__: Callable[["Matrix", int], list[Fraction]] = lambda self, item: self.matrix[item]
    __name__ = "Matrix"
    __str__: Callable[["Matrix"], str] = lambda self:\
        f"\nrows = {self.order[0]}\ncolumns = {self.order[1]}\nmatrix = {self.matrix}"
    __repr__: Callable[["Matrix"], str] = lambda self:\
        f"Matrix(rows={self.order[0]}, columns={self.order[1]}, matrix={self.matrix})"
    __call__ = __repr__

    def _validate(self) -> "Matrix":
        if self.order[0] != len(self.matrix):
            raise MatrixError("Invalid Matrix row")

        column_length = len(self.matrix[0])

        for column in self.matrix:
            if len(column) != column_length:
                raise MatrixError("Invalid Matrix column")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                try:
                    self.matrix[i][j] = Fraction(self.matrix[i][j])

                except:
                    raise MatrixError("Invalid Matrix element")

        return self

    def _identity(self) -> "Matrix":
        self._matrix = [[Fraction(1) if i == j else Fraction(0) for j in range(self.order[1])]
                        for i in range(self.order[0])]
        return self

    def _input(self) -> "Matrix":
        self._matrix = []

        for _ in range(self.order[0]):
            row = input("Enter row (space-separated values): ").split()

            if len(row) == self.order[1]:
                self._matrix.append([Fraction(element) for element in row])

            else:
                raise MatrixError("Invalid matrix elements")

        return self

    def _null(self) -> "Matrix":
        self._matrix = [[Fraction() for _ in range(self.order[1])] for _ in range(self.order[0])]
        return self

    def cramer_rule(self) -> tuple[Fraction]:
        if self.order[0] != self.order[1] - 1:
            raise MatrixError("Cramer's rule is not applicable for rectangular matrix")

        a = []
        b = []

        for row in self.matrix:
            a.append(row[:-1])
            b.append(row[-1])

        a = Matrix(len(a), len(a[0]), matrix=a)
        det = a.determinant()
        res = []

        for i in range(self.order[0]):
            temp_matrix = a.copy()

            for j in range(self.order[0]):
                temp_matrix[j][i] = b[j]

            res.append(temp_matrix.determinant() / det)

        return tuple(res)

    def determinant(self) -> Fraction:
        if not self.is_square():
            raise MatrixError("Determinant of rectangular matrix is not defined")

        result = self.echelon_form()
        det = Fraction(1)

        for i in range(result.order[0]):
            det *= result.matrix[i][i]

        return det

    def echelon_form(self) -> "Matrix":
        if self.order[0] != self.order[1] - 1:
            raise MatrixError("Invalid matrix to form echelon matrix")

        result = Matrix(self.order[0], self.order[1], matrix=self.matrix)

        pivot = 0
        while pivot + 1 < result.order[0]:
            cnt = pivot

            try:
                while result.matrix[pivot][cnt] == 0:
                    pivot += 1

            except IndexError:
                return result

            if pivot != cnt:
                for i in range(result.order[1]):
                    result.matrix[pivot][i], result.matrix[cnt][i] = result.matrix[cnt][i], result.matrix[pivot][i]

            pivot = cnt

            for i in range(pivot + 1, result.order[0]):
                factor = result.matrix[i][pivot] / result.matrix[pivot][pivot]

                for j in range(pivot, result.order[1]):
                    result.matrix[i][j] -= (factor * result.matrix[pivot][j])

            pivot += 1

        return result

    def eigen_values(self) -> tuple[Fraction]:
        def determinant_for_eigen(matrix: list[list[Fraction]]):
            if len(matrix) == 2:
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

            det = Fraction()

            for i in range(len(matrix)):
                minor = [row[:i] + row[i+1:] for row in matrix[1:]]
                det += ((-1)**i) * matrix[0][i] * determinant_for_eigen(minor)

            return det

        if not self.is_square():
            raise MatrixError("Eigen values for a non-square matrix are not defined")

        var = Term("x")
        mat = [[self.matrix[i][j] - var if i == j else self.matrix[i][j] for j in range(self.order[1])] for i in range(self.order[0])]
        res = determinant_for_eigen(mat).roots()

        try:
            return tuple((Fraction(element) for element in res))

        except ValueError:
            raise MatrixError("Complex roots are not allowed")

    def eigen_vectors(self) -> tuple[tuple[Fraction]]:
        def simplify_row(lst: list[Fraction]) -> list[Fraction]:
            factor = Fraction(lst[0])
            size = len(lst)

            for i in range(1, size):
                factor = Fraction(gcd(factor.numerator, lst[i].numerator), lcm(factor.denominator, lst[i].denominator))

            for i in range(size):
                lst[i] /= factor

            return lst

        res, cnt = [], {}
        values = self.eigen_values()

        for value in values:
            cnt[value] = cnt.get(value, 0) + 1

        for key, value in cnt.items():
            characteristic_matrix = Matrix(self.order[0], self.order[1],
                                           matrix=[[self.matrix[i][j] - (key if i == j else 0)
                                                    for j in range(self.order[1])] for i in range(self.order[0])])
            vector = characteristic_matrix.gauss_elimination()

            if isinstance(vector[1], str):
                for i in range(1, value+1):
                    row = simplify_row(characteristic_matrix[0].copy())
                    vector = [Fraction(1)]

                    for j in range(2, len(row)):
                        row[1] += row[j] * (j + i - 1)
                        vector.append(Fraction(j + i - 1))

                    row = row[:2]
                    row[1] *= -1
                    row[1] /= row[0]
                    vector.insert(0, row[1])
                    res.append(tuple(simplify_row(vector)))

            else:
                res.append(res)

        return tuple(res)

    def gauss_elimination(self) -> tuple[Fraction] | tuple[int, str]:
        result = self.echelon_form()

        if result[-1][-2] == 0 and result[-1][-1] != 0:
            return -1, "The set of linear equations has no solutions"

        elif result[-1][-2] == result[-1][-1] == 0:
            return 0, "The set of linear equations has infinitely many solutions"

        else:
            cnt = ans = 0
            res = [result[-1][-1] / result[-1][-2]]

            for i in range(-2, -result.order[0] - 1, -1):
                for j in range(-2, i - 1, -1):
                    ans += result[i][j] * res[cnt]
                    cnt += 1

                res.append((result[i][-1] - ans) / result[i][i - 1])
                ans = cnt = 0

            res.reverse()
            return tuple(res)

    def gauss_jordan_elimination(self) -> "Matrix":
        if not self.is_square():
            raise MatrixError("Inverse of a rectangular matrix is not defined")

        det = self.determinant()

        if det == 0:
            raise MatrixError("Inverse of singular matrix is not defined")

        identity_mat = Matrix(self.order[0], self.order[1], "identity")
        aug_matrix = Matrix(self.order[0], self.order[0] * 2,
                            matrix=list(reversed((self.matrix[i] + identity_mat.matrix[i]
                                                  for i in range(self.order[0]))))).echelon_form()
        for i in range(self.order[0]):
            aug_matrix[i][:self.order[0]] = list(reversed(aug_matrix[i][:self.order[0]]))

        aug_matrix = aug_matrix.echelon_form()
        res = []

        for i in range(self.order[0] - 1, -1, -1):
            factor = 1 / aug_matrix[i][i]

            for j in range(self.order[0], self.order[0] * 2):
                aug_matrix[i][j] *= factor

            res.append(aug_matrix[i][self.order[0]:])

        return Matrix(self.order[0], self.order[1], matrix=res)

    def is_orthonormal_system(self) -> bool:
        def dot_product(lst1: list[Fraction], lst2: list[Fraction]):
            res = 0

            for k in range(len(lst1)):
                res += lst1 * lst2

            return res

        if not self.is_square():
            raise MatrixError("Orthonormal system is defined for square matrices only")

        matrix = self.transpose()

        for i in range(matrix.order[0]):
            for j in range(i, matrix.order[0]):
                if ((i == j and dot_product(matrix.matrix[i], matrix.matrix[j]) != 1) or
                        (i != j and dot_product(matrix.matrix[i], matrix.matrix[j]) != 0)):
                    return False

        return True

    def rank(self) -> int:
        result = self.echelon_form()
        rank = result.order[0]
        i, j = rank - 1, result.order[1] - 1

        while result.matrix[i][j] == 0 and i > 0 and j > 0:
            rank -= 1
            i -= 1
            j -= 1

        return rank

    def transpose(self) -> "Matrix":
        result = Matrix(self.order[1], self.order[0], "null")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                result.matrix[j][i] = self.matrix[i][j]

        return result

    def type(self) -> "Matrix":
        if self.order[0] == 1 and self.order[1] != 1:
            res = "row"

        elif self.order[1] == 1 and self.order[0] != 1:
            res = "column"

        elif self.order[0] == self.order[1]:
            res = "square"
            is_scalar = is_identity = is_diagonal = True

            for i in range(self.order[0]):
                for j in range(self.order[1]):
                    if i == j:
                        if self.matrix[i][j] != self.matrix[0][0]:
                            is_scalar = False

                        elif self.matrix[i][j] != Fraction(1):
                            is_identity = False

                    else:
                        if self.matrix[i][j] != Fraction():
                            is_scalar = is_identity = is_diagonal = False

                if not (is_scalar and is_identity and is_diagonal):
                    break

            if is_identity:
                res = "identity"

            elif is_scalar:
                res = "scalar"

            elif is_diagonal:
                res = "diagonal"

        elif self.order[0] != self.order[1]:
            res = "rectangular"

        else:
            res = ""

        is_null = True

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                if self.matrix[i][j] != Fraction():
                    is_null = False
                    break

            if not is_null:
                break

        if is_null:
            res = "null"

        return res

    copy: Callable[["Matrix"], "Matrix"] = lambda self: Matrix(self.order[0], self.order[1], matrix=self.matrix)
    is_orthogonal: Callable[["Matrix"], bool] = lambda self: self.is_orthonormal_system()
    is_skew_symmetric: Callable[["Matrix"], bool] = lambda self: self == (-self).transpose()
    is_square: Callable[["Matrix"], bool] = lambda self: self.order[0] == self.order[1]
    is_symmetric: Callable[["Matrix"], bool] = lambda self: self == self.transpose()
    print: Callable[["Matrix"], None] = lambda self: [print([element.__str__() for element in self.matrix[i]])
                                                      for i in range(len(self.matrix))]


