from fractions import Fraction
from math import gcd, lcm
from typing import Callable, Literal, Generic, TypeVar
from equation import Polynomial, Variable

Type = TypeVar("Type")


class MatrixError(Exception): ...


class Matrix(Generic[Type]):
    """
# INITIALIZING MATRIX OBJECT
    -> using input method
        >>> m: Matrix[Fraction] = Matrix(2, 3, "input")           # this is a matrix with 2 rows and 3 columns
        Enter row (space-separated values): 1 2 3
        Enter row (space-separated values): 4 5 6
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> providing a valid nested list and convert it to matrix
        >>> m: Matrix[Fraction] = Matrix(2, 3, matrix=[[1, 2, 3], [4, 5, 6]])     # here matrix= is keyword only argument
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> by providing a type of matrix to generate
        -> null matrix
            >>> m: Matrix[Fraction] = Matrix(3, 3, "null")        # creating a null matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]]

        -> identity matrix
            >>> m: Matrix[Fraction] = Matrix(3, 3, "identity")    # creating an identity matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(1, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)]]

# USING OPERATORS BETWEEN MATRIX AND NUMERIC TYPES
    -> consider the following matrices and one integer throughout the section
        >>> m1: Matrix[Fraction] = Matrix(2, 2, matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix[Fraction] = Matrix(2, 2, matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> addition between matrix and numeric types
            >>> m1 + m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> subtraction between matrix and numeric types
            >>> m1 - m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> multiplication between matrix and numeric types
            >>> m1 * m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(19, 1), Fraction(22, 1)], [Fraction(43, 1), Fraction(50, 1)]])
            >>> m1 * num
            Matrix(rows=2, columns=2, matrix=[[Fraction(7, 1), Fraction(14, 1)], [Fraction(21, 1), Fraction(28, 1)]])

# USING IN-PLACE OPERATOR
    -> consider the following matrices and one integer throughout the section
    -> matrices are all redefined after every operation to keep the initial value constant throughout the operations
        >>> m1: Matrix[Fraction] = Matrix(2, 2, matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix[Fraction] = Matrix(2, 2, matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> in-place addition between matrix and numeric types
            >>> m1 += m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> in-place subtraction between matrix and numeric types
            >>> m1 -= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> in-place multiplication between matrix and numeric types
            >>> m1 *= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(19, 1), Fraction(22, 1)], [Fraction(43, 1), Fraction(50, 1)]])
            >>> m1 *= num
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(7, 1), Fraction(14, 1)], [Fraction(21, 1), Fraction(28, 1)]])

        -> checking equality between matrix
            >>> m1 == m2
            False

        -> absolute value of matrix         # making the matrix negative with multiplying with -1
            >>> m1 *= -1
            >>> abs(m1)
            Matrix(rows=2, columns=2, matrix=[[Fraction(1, 1), Fraction(2, 1)], [Fraction(3, 1), Fraction(4, 1)]])

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
        >>> m: Matrix[Fraction] = Matrix(2, 3, matrix=[[1, 2, 3], [4, 5, 6]])

        -> using index
            >>> m[1]
            [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]

            >>> m[1][2]
            Fraction(6, 1)

        -> iterating using for loop
            >>> for row in m:
            ...     print(row)
            ...
            [Fraction(1, 1), Fraction(2, 1), Fraction(3, 1)]
            [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]

            >>> for row in m:
            ...     for element in row:
            ...         print(element, end=", ")
            ...
            '1', '2', '3,' '4,' '5', '6',

# FINDING THE SOLUTION TO A SET OF LINEAR EQUATION WITH SAME NO. OF EQUATIONS TO VARIABLES USING CRAMER'S RULE
    >>> m: Matrix[Fraction] = Matrix(3, 4, matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.cramer_rule()
    (Fraction(2, 1), Fraction(3, 1), Fraction(-1, 1))

# CREATING A COPY OF THE MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    >>> m.copy()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(2, 1), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)], [Fraction(7, 1), Fraction(8, 1), Fraction(9, 1)]])

# FINDING DETERMINANT OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.determinant()
    Fraction(-1, 1)

# CONVERTING A MATRIX TO ITS EQUIVALENT ECHELON FORM
    >>> m: Matrix[Fraction] = Matrix(3, 4, matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.echelon_form()
    Matrix(rows=3, columns=4, matrix=[[Fraction(2, 1), Fraction(1, 1), Fraction(-1, 1), Fraction(8, 1)], [Fraction(0, 1), Fraction(1, 2), Fraction(1, 2), Fraction(1, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(-1, 1), Fraction(1, 1)]])

# FINDING THE EIGEN VALUES OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_values()
    (Fraction(5, 1), Fraction(-3, 1), Fraction(-3, 1))

# FINDING THE EIGEN VECTORS OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_vectors()
    ((Fraction(-4, 1), Fraction(7, 1), Fraction(14, 1)), (Fraction(4, 1), Fraction(1, 1), Fraction(2, 1)), (Fraction(7, 1), Fraction(1, 1), Fraction(3, 1)))

# FINDING THE SOLUTION TO A SET OF LINEAR EQUATION WITH SAME NO. OF EQUATIONS TO VARIABLES USING GAUSS ELIMINATION
    >>> m: Matrix[Fraction] = Matrix(3, 4, matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.gauss_elimination()
    (Fraction(2, 1), Fraction(3, 1), Fraction(-1, 1))

# FINDING THE INVERSE OF A NON-SINGULAR MATRIX USING GAUSS JORDAN ELIMINATION
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.gauss_jordan_elimination()
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(3, 1), Fraction(-1, 1)], [Fraction(0, 1), Fraction(-1, 2), Fraction(1, 2)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 2)]])

# CHECKING IF THE MATRIX IS A ORTHOGONAL MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, method="identity")
    >>> m.is_orthogonal()
    True

# CHECKING IF THE MATRIX IS A ORTHONORMAL SYSTEM OF COLUMN VECTORS
    >>> m: Matrix[Fraction] = Matrix(3, 3, method="identity")
    >>> m.is_orthonormal_system()
    True

# CHECKING IF A MATRIX IS SKEW SYMMETRIC MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[0, 1, -2], [-1, 0, 3], [2, -3, 0]])
    >>> m.is_skew_symmetric()
    True

# CHECKING IF A MATRIX IS SQUARE OR NOT
    >>> m: Matrix[Fraction] = Matrix(3, 3, method="null")
    >>> m.is_square()
    True

# CHECKING IF A MATRIX IS SYMMETRIC MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.is_symmetric()
    True

# USING THE MATRIX PRINT FUNCTION
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.print()
    ['1', '1', '-1']
    ['1', '2', '0']
    ['-1', '0', '5']

# FINDING THE RANK OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.rank()
    3

# FINDING TRANSPOSE OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(3, 3, matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.transpose()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(1, 1), Fraction(-1, 1)], [Fraction(1, 1), Fraction(2, 1), Fraction(0, 1)], [Fraction(-1, 1), Fraction(0, 1), Fraction(5, 1)]])

# DETERMINING THE TYPE OF THE MATRIX
    >>> M: Matrix[Fraction] = Matrix(2, 3, method="null")
    >>> m.type()
    'rectangular'
    """

    def __init__(self, rows: int, columns: int, method: Literal["input", "null", "identity", "pass"] = "pass", *,
                 matrix: list[list[Type]] = None) -> None:

        if rows < 0 or columns < 0:
            raise MatrixError("Row or column of a matrix cannot be negative")

        self._order: tuple[int, int] = (rows, columns)

        if method == "input":
            self._input()
            self._validate()

        elif method == "null":
            self._null()

        elif method == "identity":
            self._identity()

        elif method == "pass":
            self._matrix: list[list[Fraction]] = [row.copy() for row in matrix]
            self._validate()

    @property
    def order(self) -> tuple[int, int]:
        return self._order

    @property
    def matrix(self) -> list[list[Type]]:
        return self._matrix

    def __add__(self, other: "Matrix[Type]") -> "Matrix[Type]":
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix[Type] = Matrix(self.order[0], self.order[1], "null")

                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        result.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __sub__(self, other: "Matrix[Type]") -> "Matrix[Type]":
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix[Type] = Matrix(self.order[0], self.order[1], "null")

                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        result.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __mul__(self, other: "Matrix[Type] | Type") -> "Matrix[Type]":
        if isinstance(other, Matrix):
            if self.order[1] == other.order[0]:
                result: Matrix[Type] = Matrix(self.order[0], other.order[1], "null")

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

    def __iadd__(self, other: "Matrix[Type]") -> None:
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        self.matrix[i][j] += other.matrix[i][j]

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __isub__(self, other: "Matrix[Type]") -> None:
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.order[0]):
                    for j in range(self.order[0]):
                        self.matrix[i][j] -= other.matrix[i][j]

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __imul__(self, other: "Matrix[Type] | Type") -> None:
        if isinstance(other, Matrix):
            if self.order[1] == other.order[0]:
                for k in range(self.order[0]):
                    for i in range(other.order[1]):
                        for j in range(self.order[1]):
                            self.matrix[k][j] *= other.matrix[j][i]

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        else:
            try:
                for i in range(self.order[0]):
                    for j in range(self.order[1]):
                        self.matrix[i][j] *= other

            except ValueError:
                return NotImplemented

    def __abs__(self) -> "Matrix[Type]":
        result: Matrix[Type] = Matrix(self.order[0], self.order[1], "null")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                result.matrix[i][j] = abs(self.matrix[i][j])

        return result

    def __contains__(self, item: Type) -> bool:
        for row in self.matrix:
            for element in row:
                if element == item:
                    return True

    def __iter__(self) -> list[Type]:  # type: ignore
        for row in self.matrix:
            yield row

    __radd__: Callable[["Matrix[Type]", "Matrix[Type]"], "Matrix[Type]"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Matrix[Type]", "Matrix[Type]"], "Matrix[Type]"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Matrix[Type]", "Matrix[Type] | Type"], "Matrix[Type]"] = lambda self, other: self.__mul__(
        other)
    __bool__: Callable[["Matrix[Type]"], bool] = lambda self: self.type() != "null"
    __pos__: Callable[["Matrix[Type]"], "Matrix[Type]"] = lambda self: self
    __neg__: Callable[["Matrix[Type]"], "Matrix[Type]"] = lambda self: self.__mul__(-1)
    __eq__: Callable[["Matrix[Type]", "Matrix[Type]"], bool] = lambda self, other: self.matrix == other.matrix \
        if isinstance(other, Matrix) else NotImplemented
    __getitem__: Callable[["Matrix[Type]", int], list[Type]] = lambda self, item: self.matrix[item]
    __name__ = "Matrix"
    __str__: Callable[["Matrix[Type]"], str] = lambda self: \
        f"\nrows = {self.order[0]}\ncolumns = {self.order[1]}\nmatrix = {self.matrix}"
    __repr__: Callable[["Matrix[Type]"], str] = lambda self: \
        f"Matrix(rows={self.order[0]}, columns={self.order[1]}, matrix={self.matrix})"
    __call__ = __repr__

    def _validate(self) -> None:
        """Validates the object and user input to initialize a matrix object."""
        if self.order[0] != len(self.matrix):
            raise MatrixError("Invalid Matrix row")

        column_length: int = len(self.matrix[0])

        for column in self.matrix:
            if len(column) != column_length:
                raise MatrixError("Invalid Matrix column")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                try:
                    self.matrix[i][j] = Fraction(self.matrix[i][j])

                except TypeError:
                    pass

    def _identity(self) -> None:
        """Initializes an identity matrix"""
        self._matrix: list[list[Fraction]] = [[Fraction(1) if i == j else Fraction(0) for j in range(self.order[1])]
                                              for i in range(self.order[0])]

    def _input(self) -> None:
        """Accept user input for construct the matrix with provided values."""
        self._matrix: list[str] = []

        for _ in range(self.order[0]):
            row: list[str] = input("Enter row (space-separated values): ").split()

            if len(row) == self.order[1]:
                self._matrix.append([Fraction(element) for element in row])

            else:
                raise MatrixError("Invalid matrix elements")

    def _null(self) -> None:
        """Initializes a null matrix"""
        self._matrix: list[list[Fraction]] = [[Fraction() for _ in range(self.order[1])] for _ in range(self.order[0])]

    def cramer_rule(self) -> tuple[Type] | tuple[int, str]:
        """Solves a set of linear equation where the matrix object is an augmented coefficient matrix of the set of linear equation by using Cramer's Rule."""
        if self.order[0] != self.order[1] - 1:
            raise MatrixError("Cramer's rule is not applicable for rectangular matrix")

        temp_a: list[list[Type]] = []
        b: list[list[Type]] = []
        res: list[Type] = []

        for row in self.matrix:
            temp_a.append(row[:-1])
            b.append(row[-1])

        a: Matrix[Type] = Matrix(len(temp_a), len(temp_a[0]), matrix=temp_a)
        det: Type = a.determinant()

        if det == 0:
            return 0, "The set of linear equations has no solutions"

        for i in range(self.order[0]):
            temp_matrix: Matrix[Type] = a.copy()

            for j in range(self.order[0]):
                temp_matrix[j][i] = b[j]

            res.append(temp_matrix.determinant() / det)

        return tuple(res)

    def determinant(self) -> Type:
        """Finds the determinant of the matrix."""
        if not self.is_square():
            raise MatrixError("Determinant of rectangular matrix is not defined")

        result: Matrix[Type] = self.echelon_form()
        det: Fraction = Fraction(1)

        for i in range(result.order[0]):
            det *= result.matrix[i][i]

        return det

    def echelon_form(self) -> "Matrix[Type]":
        """Returns the echelon_form of the current matrix."""
        result: Matrix[Type] = Matrix(self.order[0], self.order[1], matrix=self.matrix)
        pivot: int = 0

        while pivot + 1 < result.order[0]:
            cnt: int = pivot

            try:
                while result.matrix[pivot][cnt] == 0:
                    pivot += 1

            except IndexError:
                return result

            if pivot != cnt:
                for i in range(result.order[1]):
                    result.matrix[pivot][i], result.matrix[cnt][i] = result.matrix[cnt][i], result.matrix[pivot][i]

            pivot: int = cnt

            for i in range(pivot + 1, result.order[0]):
                factor: Fraction = result.matrix[i][pivot] / result.matrix[pivot][pivot]

                for j in range(pivot, result.order[1]):
                    result.matrix[i][j] -= (factor * result.matrix[pivot][j])

            pivot += 1

        return result

    def eigen_values(self) -> tuple[Fraction]:
        """Finds the eigen values of a matrix."""

        def recursive_determinant(matrix: list[list[Polynomial]]):
            """Finds the determinant of a 2D-Array using recursive approach of finding determinant of sub-matrices."""
            if len(matrix) == 2:
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

            det: Polynomial = Polynomial()

            for i in range(len(matrix)):
                minor: list[list[Polynomial]] = [row[:i] + row[i + 1:] for row in matrix[1:]]
                det += ((-1) ** i) * (matrix[0][i] * recursive_determinant(minor))

            return det

        if not self.is_square():
            raise MatrixError("Eigen values for a non-square matrix are not defined")

        var: Polynomial = Polynomial("x")
        mat: list[list[Polynomial]] = \
            [[self.matrix[i][j] - var if i == j else self.matrix[i][j] for j in range(self.order[1])] for i in
             range(self.order[0])]
        char_poly: Polynomial = recursive_determinant(mat)
        res: tuple[float] = char_poly.roots()

        try:
            return tuple((Fraction(round(element, 3)) for element in res))

        except TypeError:
            return tuple(res)

        except ValueError:
            raise MatrixError("Complex roots are not supported.")

    def eigen_vectors(self) -> tuple[tuple[Fraction]]:
        """Finds the normalized eigen vectors for the corresponding eigen values of the matrix."""

        def simplify_row(lst: list[Fraction]) -> tuple[Fraction]:
            factor = Fraction(lst[0])
            size = len(lst)

            for i in range(1, size):
                factor = Fraction(gcd(factor.numerator, lst[i].numerator), lcm(factor.denominator, lst[i].denominator))

            for i in range(size):
                lst[i] /= factor

            return tuple(lst)

        res: list = []
        cnt: dict[Fraction: int] = {}
        values: tuple[Fraction] = self.eigen_values()
        var_mat: Matrix[Type] = Matrix(self.order[1], 1,
                                       matrix=[[Polynomial(f"x{i}")] for i in range(1, self.order[1] + 1)])

        for value in values:
            cnt[value] = cnt.get(value, 0) + 1

        for key, value in cnt.items():
            eigen_vec: list[Fraction | None] = [None for _ in range(self.order[1])]
            matrix: list[list[Type]] = [[self.matrix[i][j] - (key if i == j else Fraction(0))
                                         for j in range(self.order[1])] for i in range(self.order[0])]
            char_matrix: Matrix[Polynomial] = Matrix(self.order[0], self.order[1],
                                                     matrix=matrix).echelon_form() * var_mat

            for row in char_matrix.matrix[::-1]:
                poly: Polynomial = row[0]

                for idx, component in enumerate(eigen_vec):
                    if component is not None:
                        poly: Polynomial = poly.substitute(f"x{idx + 1}", component)

                var: list[Variable] = []

                for variable in poly.numerator:
                    if variable.variables:
                        var.append(variable)

                if len(var) == 0:
                    pass

                elif len(var) == 1:
                    factor: Fraction = var[0].coefficient
                    for i in range(len(poly.numerator)):
                        poly.numerator[i] /= factor

                    idx: str = tuple(var[0].variables.keys())[0][1]

                    try:
                        eigen_vec[int(idx) - 1] = -poly.numerator[1].coefficient

                    except IndexError:
                        eigen_vec[int(idx) - 1] = Fraction(0)

                elif len(var) >= 2:
                    for variable in var[1:]:
                        element: str = tuple(variable.variables.keys())[0]
                        poly: Polynomial = poly.substitute(element, Fraction(1))
                        eigen_vec[int(element[1]) - 1] = Fraction(1)

                    for i in range(len(poly.numerator)):
                        poly.numerator[i] /= var[0].coefficient

                    idx: str = tuple(var[0].variables.keys())[0][1]

                    try:
                        eigen_vec[int(idx) - 1] = -poly.numerator[1].coefficient

                    except IndexError:
                        eigen_vec[int(idx) - 1] = Fraction(0)

            eigen_vec = [1 if value is None else value for value in eigen_vec]
            res.append(simplify_row(eigen_vec))

        return tuple(res)

    def gauss_elimination(self) -> tuple[Type] | tuple[int, str]:
        if self.order[0] != self.order[1] - 1:
            matrix: list[list[Fraction]] = [row for idx, row in enumerate(self.matrix) if idx < self.order[1] - 1]

        else:
            matrix: list[list[Fraction]] = self.matrix

        result: Matrix[Fraction] = Matrix(self.order[1] - 1, self.order[1], matrix=matrix).echelon_form()

        if result[-1][-2] == 0 and result[-1][-1] != 0:
            return 0, "The set of linear equations has no solutions"

        else:
            for i in range(self.order[0]):
                result.matrix[i][-1] = -result.matrix[i][-1]

            res: list[Fraction | None] = [None for _ in range(self.order[1] - 1)]
            matrix: list[list[Polynomial]] = [[Polynomial(f"x{i}")] for i in range(1, self.order[1] + 1)]
            matrix[-1][0] = Fraction(1)
            var_mat: Matrix[Polynomial] = Matrix(self.order[1], 1, matrix=matrix)
            poly_mat: Matrix[Polynomial] = result * var_mat

            for row in poly_mat.matrix[::-1]:
                poly: Polynomial = row[0]

                for idx, component in enumerate(res):
                    if component is not None:
                        poly: Polynomial = poly.substitute(f"x{idx + 1}", component)

                var: list[Variable] = []

                for variable in poly.numerator:
                    if variable.variables:
                        var.append(variable)

                if len(var) == 0:
                    pass

                elif len(var) == 1:
                    factor: Fraction = var[0].coefficient

                    for i in range(len(poly.numerator)):
                        poly.numerator[i] /= factor

                    idx: str = tuple(var[0].variables.keys())[0][1]

                    try:
                        res[int(idx) - 1] = -poly.numerator[1].coefficient

                    except IndexError:
                        res[int(idx) - 1] = Fraction(0)

                elif len(var) > 1:
                    for variable in var:
                        var_str: str = tuple(variable.variables.keys())[0]
                        temp_poly: Polynomial = poly.substitute(var_str, 0)
                        temp_poly /= variable.coefficient
                        res[int(var_str[1]) - 1] = -temp_poly

            return tuple(res)

    def gauss_jordan_elimination(self) -> "Matrix[Type]":
        if not self.is_square():
            raise MatrixError("Inverse of a rectangular matrix is not defined")

        det: Type = self.determinant()

        if det == 0:
            raise MatrixError("Inverse of singular matrix is not defined")

        identity_mat: Matrix[Fraction] = Matrix(self.order[0], self.order[1], "identity")
        aug_matrix: Matrix[Type] = Matrix(self.order[0], self.order[0] * 2,
                                          matrix=[self.matrix[i] + identity_mat.matrix[i] for i in
                                                  range(self.order[0])])
        aug_matrix: Matrix[Type] = aug_matrix.echelon_form()
        aug_matrix._matrix = aug_matrix.matrix[::-1]

        for i in range(self.order[0]):
            aug_matrix[i][:self.order[0]] = list(reversed(aug_matrix[i][:self.order[0]]))

        aug_matrix: Matrix[Type] = aug_matrix.echelon_form()
        res: list[list[Type]] = []

        for i in range(self.order[0] - 1, -1, -1):
            factor: Type = 1 / aug_matrix[i][i]

            for j in range(self.order[0], self.order[0] * 2):
                aug_matrix[i][j] *= factor

            res.append(aug_matrix[i][self.order[0]:])

        return Matrix(self.order[0], self.order[1], matrix=res)

    def is_orthonormal_system(self) -> bool:
        def dot_product(lst1: list[Type], lst2: list[Type]) -> Type:
            res: Type = Fraction(0)

            for k in range(len(lst1)):
                res += lst1[k] * lst2[k]

            return res

        if not self.is_square():
            raise MatrixError("Orthonormal system is defined for square matrices only")

        matrix: Matrix[Type] = self.transpose()

        for i in range(matrix.order[0]):
            for j in range(i, matrix.order[0]):
                if ((i == j and dot_product(matrix.matrix[i], matrix.matrix[j]) != 1) or
                        (i != j and dot_product(matrix.matrix[i], matrix.matrix[j]) != 0)):
                    return False

        return True

    def rank(self) -> int:
        result: Matrix[Type] = self.echelon_form()
        rank: int = result.order[0]
        i: int = rank - 1
        j: int = result.order[1] - 1

        while result.matrix[i][j] == 0 and i > 0 and j > 0:
            rank -= 1
            i -= 1
            j -= 1

        return rank

    def transpose(self) -> "Matrix[Type]":
        result: Matrix[Type] = Matrix(self.order[1], self.order[0], "null")

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                result.matrix[j][i] = self.matrix[i][j]

        return result

    def type(self) -> str:
        if self.order[0] == 1 and self.order[1] != 1:
            res: str = "row"

        elif self.order[1] == 1 and self.order[0] != 1:
            res: str = "column"

        elif self.order[0] == self.order[1]:
            res: str = "square"
            is_scalar: bool = True
            is_identity: bool = True
            is_diagonal: bool = True

            for i in range(self.order[0]):
                for j in range(self.order[1]):
                    if i == j:
                        if self.matrix[i][j] != self.matrix[0][0]:
                            is_scalar: bool = False

                        elif self.matrix[i][j] != Fraction(1):
                            is_identity: bool = False

                    else:
                        if self.matrix[i][j] != Fraction():
                            is_scalar: bool = False
                            is_identity: bool = False
                            is_diagonal: bool = False

                if not (is_scalar and is_identity and is_diagonal):
                    break

            if is_identity:
                res: str = "identity"

            elif is_scalar:
                res: str = "scalar"

            elif is_diagonal:
                res: str = "diagonal"

        elif self.order[0] != self.order[1]:
            res: str = "rectangular"

        else:
            res: str = ""

        is_null: bool = True

        for i in range(self.order[0]):
            for j in range(self.order[1]):
                if self.matrix[i][j] != Fraction():
                    is_null: bool = False
                    break

            if not is_null:
                break

        if is_null:
            res: str = "null"

        return res

    copy: Callable[[], "Matrix[Type]"] = lambda self: Matrix(self.order[0], self.order[1], matrix=self.matrix)
    is_orthogonal: Callable[[], bool] = lambda self: self.is_orthonormal_system()
    is_skew_symmetric: Callable[[], bool] = lambda self: self == (-self).transpose()
    is_square: Callable[[], bool] = lambda self: self.order[0] == self.order[1]
    is_symmetric: Callable[[], bool] = lambda self: self == self.transpose()
    nullity: Callable[[], int] = lambda self: self.order[0] - self.rank()
    print: Callable[[], None] = lambda self: [print([element.__str__() for element in self.matrix[i]]) for i in
                                              range(len(self.matrix))]
    trace: Callable[[], Type] = lambda self: sum(self.matrix[i][i] for i in self.order[0])
