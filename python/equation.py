from fractions import Fraction
from typing import Callable, Generator
from math import gcd, lcm, cos, acos, pi, sqrt as sqrtf
from cmath import sqrt as sqrtc


class Variable:
    """
# INITIALIZING VARIABLE OBJECT
    -> providing a valid expression in a str
        >>> v: Variable = Variable("7x^2")
        >>> print(v)
        7x^2

    -> providing the direct coefficient and variables property attributes
        >>> v: Variable = Variable(coefficient=7, variables_dict={"x": 2})
        >>> print(v)
        7x^2

# USING OPERATORS BETWEEN VARIABLE AND NUMERIC TYPE
    # ADDITION AND SUBTRACTION OF VARIABLE OBJECTS WITH DIFFERENT VARIABLE BASES ARE NOT IMPLEMENTED
    -> consider the following variables and one integer throughout the section
        >>> v1: Variable = Variable("5x")
        >>> v2: Variable = Variable("2x")
        >>> num: int = 7

        -> addition of two variables
            >>> v1 + v2
            Variable(coefficient=7, variables={'x': Fraction(1, 1)})

        -> subtraction of two variables
            >>> v1 - v2
            Variable(coefficient=3, variables={'x': Fraction(1, 1)})

        -> multiplication of variables and numeric types
            >>> v1 * v2
            Variable(coefficient=10, variables={'x': Fraction(2, 1)})
            >>> v1 * num
            Variable(coefficient=35, variables={'x': Fraction(1, 1)})

        -> division of variables and numeric types
            >>> v1 / v2
            Variable(coefficient=5/2, variables={'x': Fraction(0, 1)})
            >>> v1 / num
            Variable(coefficient=5/7, variables={'x': Fraction(1, 1)})

        -> exponentiating a variable
            >>> v1 ** 2
            Variable(coefficient=25, variables={'x': Fraction(2, 1)})

# USING IN-PLACE OPERATOR
    -> consider the following two variables and one integer throughout the section
    -> variables are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> v1: Variable = Variable("5x")
        >>> v2: Variable = Variable("2x")
        >>> num: int = 7

        -> in-place addition of two variables
            >>> v1 += v2
            >>> v1
            Variable(coefficient=7, variables={'x': Fraction(1, 1)})

        -> in-place subtraction of two variables
            >>> v1 -= v2
            >>> v1
            Variable(coefficient=3, variables={'x': Fraction(1, 1)})

        -> in-place multiplication of variables and numeric types
            >>> v1 *= v2
            >>> v1
            Variable(coefficient=10, variables={'x': Fraction(2, 1)})
            >>> v1 *= num
            >>> v1
            Variable(coefficient=35, variables={'x': Fraction(1, 1)})

        -> in-place division of variables and numeric types
            >>> v1 /= v2
            >>> v1
            Variable(coefficient=5/2, variables={})
            >>> v1 /= num
            >>> v1
            Variable(coefficient=5/7, variables={'x': Fraction(1, 1)})

        -> exponentiating a variable
            >>> v1 **= 2
            >>> v1
            Variable(coefficient=25, variables={'x': Fraction(2, 1)})

# OTHER BULIT-IN OPERATORS
    -> checking equality between variables
        >>> v1 == v2
        False

    -> absolute value of a variable
        >>> v1 += -1                            # making the variable negative by multiplying with -1
        >>> abs(v1)
        Variable(coefficient=5, variables={'x': Fraction(1, 1)})

    -> checking the truth value of a variable
        >>> v: Variable = Variable()
        >>> bool(v)
        False
        >>> bool(v1)
        True

# SUBSTITUTE THE VALUE OF A VALUE INTO THE VARIABLE
    >>> v: Variable = v1.substitute('x', 5)
    >>> v
    Variable(coefficient=25, variables={})

# CREATING A COPY OF THE VARIABLE
    >>> v: Variable = Variable("9x^2")
    >>> v.copy()
    Variable(coefficient=9, variables={'x': Fraction(2, 1)})
    """

    def __init__(self, expression: str = "0", *, coefficient: Fraction = None,
                 variables_dict: dict[str, Fraction] = None) -> None:
        """Initialization function for Variable class"""
        self._coefficient: Fraction = coefficient
        self._variables: dict[str, Fraction] = variables_dict.copy() if variables_dict is not None else None
        expression: str = str(expression)

        if coefficient is None:
            on_coef: bool = True
            on_var: bool = True
            on_order: bool = False
            frac: str = ""
            variable: str = ""
            var: list[str] = []
            i: int = 0
            size: int = len(expression)

            while i < size:
                if on_coef and expression[i].isalpha():
                    self._coefficient: Fraction = Fraction(1)
                    on_coef: bool = False
                    i -= 1

                elif on_coef and not expression[i].isalpha():
                    while i < size and not expression[i].isalpha():
                        frac += expression[i]
                        i += 1

                    self._coefficient: Fraction = Fraction(frac)
                    frac: str = ""
                    i -= 1
                    on_coef: bool = False

                elif on_var and expression[i].isalpha():
                    while i < size and expression[i] != '^':
                        variable += expression[i]
                        i += 1

                    var.append(variable)
                    on_var: bool = False
                    on_order: bool = True
                    variable: str = ""
                    i -= 1

                elif on_var and not expression[i].isalpha():
                    raise ValueError("Invalid Variable")

                elif on_order and expression[i].isalpha():
                    var.extend(('1', expression[i]))

                elif on_order and expression[i] == '^':
                    i += 1

                    while i < size and not expression[i].isalpha():
                        frac += expression[i]
                        i += 1

                    var.append(frac)
                    frac: str = ""
                    on_order: bool = False
                    on_var: bool = True
                    i -= 1

                i += 1

            var.append(Fraction(1)) if len(var) % 2 != 0 else var
            self._variables: dict[str, Fraction] = {var[i - 1]: Fraction(var[i]) for i in range(1, len(var), 2)}

        self._variables: dict[str, Fraction] = dict(sorted({key: value for key, value in self.variables.items()
                                                            if value != Fraction(0)}.items()))

    @property
    def coefficient(self) -> Fraction:
        return self._coefficient

    @property
    def variables(self) -> dict[str, Fraction]:
        return self._variables

    def __str__(self) -> str:
        """Built-in str() overloaded function"""
        res: str = ""
        is_brace: bool = False

        if self._coefficient == 0:
            return '0'

        if self._variables == {}:
            return str(self._coefficient)

        if self._coefficient != 1:
            if self._coefficient.denominator == 1:
                res += str(self._coefficient)
            else:
                res += f"({self._coefficient})"

        if len(self._variables) > 1:
            is_brace: bool = True

        for variable, order in self._variables.items():
            if order != 0:
                if is_brace and order != 1:
                    res += '('

                if len(variable) > 1:
                    res += f"({variable})"

                else:
                    res += variable

                if order != 1:
                    if order.denominator == 1:
                        res += f"^{str(order)}"
                    else:
                        res += f"^({str(order)})"

                    if is_brace:
                        res += ')'
        return res

    def __add__(self, other: "Variable") -> "Variable":
        """Operator+ overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient + other.coefficient, variables_dict=self.variables)

        else:
            return NotImplemented

    def __sub__(self, other: "Variable") -> "Variable":
        """Operator- overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient - other.coefficient, variables_dict=self.variables)

        else:
            return NotImplemented

    def __mul__(self, other: "Variable | Fraction") -> "Variable":
        """Operator* overloaded function"""
        if isinstance(other, Variable):
            coefficient: Fraction = self.coefficient * other.coefficient
            variables: dict[str, Fraction] = {}

            for element in (self.variables, other.variables):
                for var, order in element.items():
                    variables[var] = variables.get(var, 0) + order

            return Variable(coefficient=coefficient, variables_dict=variables)

        else:
            try:
                return Variable(coefficient=self.coefficient * Fraction(other), variables_dict=self.variables)

            except ValueError:
                return NotImplemented

    def __truediv__(self, other: "Variable | Fraction") -> "Variable":
        """Operator/ overloaded function"""
        if isinstance(other, Variable):
            coefficient: Fraction = self.coefficient / other.coefficient
            variables: dict[str, Fraction] = {}

            for var, order in self.variables.items():
                variables[var] = variables.get(var, 0) + order

            for var, order in other.variables.items():
                variables[var] = variables.get(var, 0) - order

            return Variable(coefficient=coefficient, variables_dict=variables)

        else:
            try:
                return Variable(coefficient=self.coefficient / Fraction(other), variables_dict=self.variables)

            except ValueError:
                return NotImplemented

    def __pow__(self, power) -> "Variable":
        """Operator** overloaded function"""
        try:
            return Variable(coefficient=self.coefficient ** power,
                            variables_dict={key: value * power for key, value in self.variables.items()})

        except ValueError:
            return NotImplemented

    def __iadd__(self, other: "Variable") -> "Variable":
        """Operator+= overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            self._coefficient += other.coefficient
            return self

        else:
            return NotImplemented

    def __isub__(self, other: "Variable") -> "Variable":
        """Operator-= overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            self._coefficient -= other.coefficient
            return self

        else:
            return NotImplemented

    def __imul__(self, other: "Variable | Fraction") -> "Variable":
        """Operator*= overloaded function"""
        if isinstance(other, Variable):
            self._coefficient *= other.coefficient

            for var, order in other.variables.items():
                self.variables[var] = self.variables.get(var, 0) + order

            return self

        else:
            try:
                self._coefficient *= Fraction(other)
                return self

            except ValueError:
                return NotImplemented

    def __itruediv__(self, other: "Variable | Fraction") -> "Variable":
        """Operator/= overload function"""
        if isinstance(other, Variable):
            self._coefficient /= other.coefficient

            for var, order in other.variables.items():
                self.variables[var] = self.variables.get(var, 0) - order

            return self

        else:
            try:
                self._coefficient /= Fraction(other)
                return self

            except ValueError:
                return NotImplemented

    def __ipow__(self, power) -> "Variable":
        """Operator**= overloaded function"""
        try:
            self._coefficient **= power
            self._variables = {key: value * power for key, value in self.variables.items()}
            return self

        except ValueError:
            return NotImplemented

    def __eq__(self, other: "Variable | Fraction") -> bool:
        """Operator== overloaded function"""
        if isinstance(other, Variable):
            return self.coefficient == other.coefficient and self.variables == other.variables

        else:
            try:
                return self.coefficient == Fraction(other) and not self.variables

            except ValueError:
                return NotImplemented

    __rmul__: Callable[["Variable | Fraction"], "Variable"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Variable | Fraction"], "Variable"] = lambda self, other: Variable(
        coefficient=other / self.coefficient, variables_dict={key: value * -1 for key, value in self.variables.items()})
    __abs__: Callable[[], "Variable"] = lambda self: Variable(coefficient=abs(self.coefficient),
                                                              variables_dict=self.variables.copy())
    __bool__: Callable[[], bool] = lambda self: bool(self.coefficient)
    __neg__: Callable[[], "Variable"] = lambda self: self * -1
    __pos__: Callable[[], "Variable"] = lambda self: self
    __len__: Callable[[], int] = lambda self: len(self.variables)
    __repr__: Callable[[], str] = lambda self: f"Variable(coefficient={self._coefficient}, variables={self._variables})"

    def substitute(self, variable: str, value: "Variable | Fraction") -> "Variable":
        """Substitutes a value of a variable with a number or another variable and returns a new variable"""
        if self.variables.get(variable, None) is not None:
            try:
                return Variable(coefficient=self.coefficient * Fraction(value) ** self.variables[variable],
                                variables_dict={key: value for key, value in self.variables.items() if key != variable})

            except TypeError:
                if isinstance(value, Variable):
                    if len(value) == 1:
                        variables: dict[str, Fraction] = {}

                        for key, val in self.variables.items():
                            if key == variable:
                                first, second = tuple(value.variables.items())[0]
                                variables[first] = variables.get(first, 0) + second * val

                            else:
                                variables[key] = variables.get(key, 0) + val

                        return Variable(coefficient=self.coefficient * value.coefficient, variables_dict=variables)

        return self.copy()

    copy: Callable[["Variable"], "Variable"] = lambda self: Variable(coefficient=self.coefficient,
                                                                     variables_dict=self.variables.copy())


class PolynomialError(Exception): ...


class Polynomial:
    """
    # I WILL BE PRINTING THE RESULTANT POLYNOMIAL BECAUSE THE POLYNOMIAL REPRESENTATION MAY SEEM VERY CONFUSING
    # INITIALIZING POLYNOMIAL OBJECT
    -> providing a valid expression in a str
        >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> print(poly)
        3x^3 - 5x^2 + 2x + 7

    -> providing the direct numerator variables and denominator variables property attributes
        >>> poly: Polynomial = Polynomial(numerator_variables=[Variable(coefficient=3, variables={'x': Fraction(3, 1)}),Variable(coefficient=-5, variables={'x': Fraction(2, 1)}), Variable(coefficient=2, variables={'x': Fraction(1, 1)}), Variable(coefficient=7, variables={})], denominator_variables=[Variable(coefficient=1, variables={})])
        >>> print(poly)
        3x^3 - 5x^2 + 2x + 7

# USING OPERATORS BETWEEN POLYNOMIAL AND NUMERIC TYPE
    -> consider the following polynomials and one integer throughout the section
        >>> poly1: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> poly2: Polynomial = Polynomial("4x^4 6x^2 -1x 9")
        >>> num: int = 7

        -> addition of polynomials and numeric types
            >>> print(poly1 + poly2)
            4x^4 + 3x^3 + x^2 + x + 16
            >>> print(poly1 + num)
            x^3 - 5x^2 + 2x + 14

        -> subtraction of polynomials and numeric types
            >>> print(poly1 - poly2)
            -4x^4 + 3x^3 - 11x^2 + 3x - 2
            >>> print(poly1 - num)
            x^3 - 5x^2 + 2x - 0

        -> multiplication of polynomials and numeric types
            >>> print(poly1 * poly2)
            12x^7 - 20x^6 + 26x^5 - 5x^4 + 44x^3 - 5x^2 + 11x + 63
            >>> print(poly1 * num)
            3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after multiplying

        -> division of polynomials and numeric types
            >>> print(poly1 / poly2)
            (3x^3 - 5x^2 + 2x + 7) / (4x^4 + 6x^2 - x + 9)
            >>> print(poly1 / num)
            V3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after division

# USING IN-PLACE OPERATOR
    -> consider the following two polynomials and one integer throughout the section
    -> polynomials are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> poly1: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> poly2: Polynomial = Polynomial("4x^4 6x^2 -1x 9")
        >>> num: int = 7

        -> addition of polynomials and numeric types
            >>> poly1 += poly2
            >>> print(poly1)
            4x^4 + 3x^3 + x^2 + x + 16
            >>> poly1 += num
            >>> print(poly1)
            x^3 - 5x^2 + 2x + 14

        -> subtraction of polynomials and numeric types
            >>> poly1 -= poly2
            >>> print(poly1)
            -4x^4 + 3x^3 - 11x^2 + 3x - 2
            >>> poly1 -= num
            >>> print(poly1)
            x^3 - 5x^2 + 2x - 0

        -> multiplication of polynomials and numeric types
            >>> poly1 *= poly2
            >>> print(poly1)
            12x^7 - 20x^6 + 26x^5 - 5x^4 + 44x^3 - 5x^2 + 11x + 63
            >>> poly1 *= num
            >>> print(poly1)
            3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after multiplying

        -> division of polynomials and numeric types
            >>> poly1 /= poly2
            >>> print(poly1)
            (3x^3 - 5x^2 + 2x + 7) / (4x^4 + 6x^2 - x + 9)
            >>> poly1 /= num
            >>> print(poly1)
            V3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after division

# OTHER BULIT-IN OPERATORS
    -> checking equality between polynomials
        >>> poly1 == poly2
        False

    -> checking the truth value of a polynomial
        >>> poly: Polynomial = Polynomial()
        >>> bool(poly)
        False
        >>> bool(poly1)
        True

# SUBSTITUTE THE VALUE OF A VALUE INTO THE POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> poly.substitute('x', 5)
    Polynomial(numerator=[Variable(coefficient=267, variables={})], denominator=[Variable(coefficient=1, variables={})]

# CREATING A COPY OF THE POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> print(poly.copy())
    3x^3 - 5x^2 + 2x + 7

# FINDIND THE ROOTS OF A POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> poly.roots()
    (-0.841, (1.254+1.097j), (1.254-1.097j))

# CONVERTING A QUADRATIC POLYNOMAIL TO ITS RESPECTIVE PRINCIPAL AXES FORM
    >>> poly: Polynomial = Polynomial("-11x1^2 84x1^1x2^1 24x2^2 -156")
    >>> poly.to_principal_axes()
    {'x1': [Polynomial(numerator=[Variable(coefficient=601000, variables={'y1': Fraction(1, 1)}), Variable(coefficient=-901500, variables={'y2': Fraction(1, 1)})], denominator=[Variable(coefficient=1083603, variables={})]], 'x2': [Polynomial(numerator=[Variable(coefficient=901500, variables={'y1': Fraction(1, 1)}), Variable(coefficient=601000, variables={'y2': Fraction(1, 1)})], denominator=[Variable(coefficient=1083603, variables={})]], 'conic_section': 'Hyperbola'}
    """

    def __init__(self, numerator: str = "0", denominator: str = "1", *,
                 poly_obj: "Polynomial | None" = None, numerator_variables: list[Variable] | None = None,
                 denominator_variables: list[Variable] | None = None) -> None:
        """Polynomial object initializer function"""
        if poly_obj is not None:
            self._numerator: list[Variable] = poly_obj.numerator.copy()
            self._denominator: list[Variable] = poly_obj.denominator.copy()

        else:
            self._numerator: list[Variable] = numerator_variables if numerator_variables \
                else [Variable(element) for element in numerator.split()]
            self._denominator: list[Variable] = denominator_variables if denominator_variables \
                else [Variable(element) for element in denominator.split()]

        self._pre_simplify()

    @property
    def numerator(self) -> list[Variable]:
        return self._numerator

    @property
    def denominator(self) -> list[Variable]:
        return self._denominator

    def __str__(self) -> str:
        """Built-in str() overloaded function"""
        self._post_simplify()
        res: list[str] = []

        for term in (self.numerator, self.denominator):
            current: str = ""
            begin: bool = True

            for element in term:
                if begin:
                    begin: bool = False
                    current += str(element)

                elif element.coefficient > 0:
                    current += " + "
                    current += str(element)

                else:
                    current += " - "
                    current += str(abs(element))

            res.append('0' if not current else current)

        if res[1] == '1':
            return f"{res[0]}"

        else:
            return f"({res[0]}) / ({res[1]})"

    def __add__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator+ overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = self.numerator + [var * other for var in self.denominator]
            denominator: list[Variable] = self.denominator

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = ([var * other.denominator for var in self.numerator] +
                                             [var * other.numerator for var in self.denominator])
                denominator: list[Variable] = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator)

    def __sub__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator- overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [-var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = self.numerator + [var * -other for var in self.denominator]
            denominator: list[Variable] = self.denominator

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = ([var * other.denominator for var in self.numerator] +
                                             [var * -other.numerator for var in self.denominator])
                denominator: list[Variable] = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator)

    def __mul__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator* overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [element1 * element2 for element1 in self.numerator for element2 in
                                         other.numerator]
            denominator: list[Variable] = [element1 * element2 for element1 in self.denominator for element2 in
                                           other.denominator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = [element * other for element in self.numerator]
            denominator: list[Variable] = self.denominator

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = [element * other.numerator for element in self.numerator]
                denominator: list[Variable] = [element * other.denominator for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator)

    def __truediv__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator/ overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [element1 * element2 for element1 in self.numerator for element2 in
                                         other.denominator]
            denominator: list[Variable] = [element1 * element2 for element1 in self.denominator for element2 in
                                           other.numerator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = self.numerator
            denominator: list[Variable] = [element * other for element in self.denominator]

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = [element * other.numerator for element in self.numerator]
                denominator: list[Variable] = [element * other.denominator for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator)

    def __iadd__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator+= overloaded function"""
        result: Polynomial = self.__add__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __isub__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator-= overloaded function"""
        result: Polynomial = self.__sub__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __imul__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator*= overloaded function"""
        result: Polynomial = self.__mul__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __itruediv__(self, other: "Polynomial | Variable | Fraction") -> "Polynomial":
        """Operator/= overloaded function"""
        result: Polynomial = self.__truediv__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __eq__(self, other: "Polynomial | Variable| Fraction") -> bool:
        """Operator== overloaded function"""
        if isinstance(other, Polynomial):
            return self.numerator == other.numerator and self.denominator == other.denominator

        elif isinstance(other, Variable):
            return self.__eq__(Polynomial(numerator_variables=[other]))

        else:
            try:
                return self.__eq__(Polynomial(
                    numerator_variables=[Variable(coefficient=Fraction(other), variables_dict={})]))

            except ValueError:
                return NotImplemented

    __radd__: Callable[["Polynomial | Variable | Fraction"], "Polynomial"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Polynomial | Variable | Fraction"], "Polynomial"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Polynomial | Variable | Fraction"], "Polynomial"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Polynomial | Variable | Fraction"], "Polynomial"] = \
        lambda self, other: Polynomial(numerator_variables=self.denominator,
                                       denominator_variables=self.numerator) * other
    __neg__: Callable[[], "Polynomial"] = lambda self: self * -1
    __pos__: Callable[[], "Polynomial"] = lambda self: self
    __repr__: Callable[[], str] = lambda self: f"Polynomial(numerator={self.numerator}, denominator={self.denominator}"
    __bool__: Callable[[], bool] = lambda self: self.numerator[0].coefficient != 0

    def _post_simplify(self) -> None:
        """Simplifies the polynomial object after performing some mathematical operations"""
        try:
            factor: list[str, Fraction] = list(tuple(self.numerator[0].variables.items())[0])

        except IndexError:
            factor: list[str, Fraction] = None

        if len(self.denominator) == 1 and not self.denominator[0].variables and self.denominator[0].coefficient < 0:
            self.denominator[0] = abs(self.denominator[0])
            self._numerator = [var * -1 for var in self.numerator]

        if len(self.numerator) == 1:
            return

        try:
            coef: Fraction = self.numerator[0].coefficient

        except IndexError:
            coef: Fraction = Fraction(1)

        for element in self.numerator[1:]:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(factor[1], element.variables[factor[0]])

            else:
                factor: list[str, Fraction] = None

            coef: Fraction = Fraction(gcd(coef.numerator, element.coefficient.numerator),
                                      lcm(coef.denominator, element.coefficient.denominator))

        if coef != Fraction(1):
            for i in range(len(self.numerator)):
                self.numerator[i] /= coef

        for element in self.denominator:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(factor[1], element.variables[factor[0]])

            else:
                factor: list[str, Fraction] = None

            coef: Fraction = Fraction(gcd(coef.numerator, element.coefficient.numerator),
                                      lcm(coef.denominator, element.coefficient.denominator))

        if coef != Fraction(1):
            for i in range(len(self.denominator)):
                self.denominator[i] /= coef

        if factor:
            for term in (self.numerator, self.denominator):
                for element in term:
                    element.variables[factor[0]] -= factor[1]

    def _pre_simplify(self) -> None:
        """Simplifies the polynomial object after initializing a new polynomial instance"""
        factor: Variable = None
        check: Variable = None
        main_var: Variable = None
        broke: bool = False

        for idx, variable in enumerate(self.numerator):
            if variable.coefficient == 0:
                self.numerator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    variable.variables.pop(var)
                    broke: bool = True
                    break

                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor: Variable = Variable(coefficient=Fraction(1), variables_dict={var: variable.variables[var]})
                    self.numerator.pop(idx)
                    check: Variable = var
                    main_var: Variable = variable
                    broke: bool = True
                    break

            if broke and factor is None:
                self._pre_simplify()
                return

        if factor is not None:
            self._numerator: list[Variable] = [factor * element for element in self.numerator]
            self._denominator: list[Variable] = [factor * element for element in self.denominator]
            self.numerator.append(Variable(coefficient=main_var.coefficient,
                                           variables_dict={key: value for key, value in main_var.variables.items()
                                                           if key != check}))
            self._pre_simplify()
            return

        factor: Variable = None
        check: Variable = None
        main_var: Variable = None
        broke: bool = False

        for idx, variable in enumerate(self.denominator):
            if variable.coefficient == 0:
                self.denominator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    variable.variables.pop(var)
                    broke: bool = True
                    break

                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor: Variable = Variable(coefficient=Fraction(1), variables_dict={var: variable.variables[var]})
                    self.denominator.pop(idx)
                    check: Variable = var
                    main_var: Variable = variable
                    broke: bool = True
                    break

            if broke and factor is None:
                self._pre_simplify()
                return

        if len(self.denominator) == 1 and self.denominator[0].coefficient == 0:
            raise ZeroDivisionError

        if factor is not None:
            self._numerator: list[Variable] = [factor * element for element in self.numerator]
            self._denominator: list[Variable] = [factor * element for element in self.denominator]
            self.denominator.append(Variable(coefficient=main_var.coefficient,
                                             variables_dict={key: value for key, value in main_var.variables.items()
                                                             if key != check}))
            self._pre_simplify()

        self.numerator.sort(key=lambda value: tuple(value.variables.keys()))
        self.numerator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)
        self.denominator.sort(key=lambda value: tuple(value.variables.keys()))
        self.denominator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)

        change: bool = False

        while not change:
            res: list[Variable] = []
            size: int = len(self.numerator)
            i: int = 0

            while i < size:
                var: Variable = None

                try:
                    if var:
                        var += self.numerator[i] + self.numerator[i + 1]
                    else:
                        var: Variable = self.numerator[i] + self.numerator[i + 1]
                        change: bool = True
                        i += 1

                except (TypeError, IndexError):
                    pass

                res.append(var) if var is not None else res.append(self.numerator[i])
                i += 1

            if change:
                self._numerator: list[Variable] = res
                change = False

            else:
                change = True

        change = False

        while not change:
            res: list[Variable] = []
            size: int = len(self.denominator)
            i: int = 0

            while i < size:
                var: Variable = None

                try:
                    if var:
                        var += self.denominator[i] + self.denominator[i + 1]
                    else:
                        var: Variable = self.denominator[i] + self.denominator[i + 1]
                        change: bool = True
                        i += 1

                except (TypeError, IndexError):
                    pass

                res.append(var) if var else res.append(self.denominator[i])
                i += 1

            if change:
                self._denominator = res
                change: bool = False

            else:
                change: bool = True

    @staticmethod
    def _conic_section(eigen_values: dict[str, Fraction], determinant: Fraction) -> str:
        """Determines which type of conic section does the eigen vector represents"""
        are_positive: list[bool | None] = []
        is_zero_determinant: bool = True if determinant == Fraction(0) else False

        for value in eigen_values.values():
            if value == Fraction(0):
                are_positive.append(None)

            elif value > Fraction(0):
                are_positive.append(True)

            else:
                are_positive.append(False)

        if are_positive[0] is not None and are_positive[1] is not None:
            if are_positive[0] == are_positive[1] and not is_zero_determinant:
                return "Ellipse"

            elif are_positive[0] != are_positive[1] and not is_zero_determinant:
                return "Hyperbola"

            elif are_positive[0] == are_positive[1] and is_zero_determinant:
                return "Point"

            elif are_positive[0] != are_positive[1] and is_zero_determinant:
                return "Intersecting Lines"

        else:
            if (are_positive[0] is None or are_positive[1] is None) and is_zero_determinant:
                return "Parabola"
    
    def roots(self) -> tuple[float]:
        """Computes the roots of the polynomial"""

        def quadratic_roots(b: Fraction, c: Fraction) -> tuple[float | complex]:
            """Computes the quadratic roots of a second degree polynomial"""
            determinant: Fraction = (b * b) - (4 * c)

            if determinant >= 0:
                root1: float = (-b + sqrtf(determinant)) / 2

                if determinant != 0:
                    root2: float = (-b - sqrtf(determinant)) / 2

                else:
                    root2: float = root1

            else:
                return (-b + sqrtc(determinant)) / 2, (-b - sqrtc(determinant)) / 2

            return round(root1, 14), round(root2, 14)

        def cubic_roots(b: Fraction, c: Fraction, d: Fraction) -> tuple[float | complex]:
            """Computes the cubic roots of a 3rd degree polynomial"""
            q: Fraction = (c / 3) - (b ** 2 / 9)
            r: Fraction = ((c * b - 3 * d) / 6) - (b ** 3 / 27)
            check: Fraction = r ** 2 + q ** 3

            if check > 0:
                a: complex = (abs(r) + sqrtc(check)) ** (1 / 3)

                if r >= 0:
                    t1: complex = a - (q / a)

                else:
                    t1: complex = (q / a) - a

                x2: complex = -t1 / 2 - b / 3
                y2: complex = sqrtc(3) / 2 * (a + (q / a))
                res: tuple[complex] = (t1 - b / 3, complex(x2, y2.real), complex(x2, -y2.real))
                return tuple(round(element.real, 3) if element.imag == 0
                             else complex(round(element.real, 3), round(element.imag, 3)) for element in res)

            else:
                theta: float = 0 if q == 0 else acos(r / (-q) ** (3 / 2))
                phis: Generator[float] = ((theta + (j * pi)) / 3 for j in range(0, 5, 2))
                return tuple(round(2 * sqrtf(-q) * cos(phi) - b / 3, 3) for phi in phis)

        var: tuple[str, Fraction] = tuple(self.numerator[0].variables.items())[0]
        factor: Fraction = self.numerator[0].coefficient
        constant: Fraction = self.numerator[-1].coefficient if self.numerator[-1].variables == {} else Fraction(0)
        coef: dict[Fraction, Fraction] = {}

        for i in range(len(self.numerator)):
            if self.numerator[i].variables and (
                    len(self.numerator[i].variables) != 1 or var[0] not in self.numerator[i].variables):
                raise ValueError("roots of the this Equation cannot be determined")

            if self.numerator[i].variables:
                coef[self.numerator[i].variables[var[0]]] = self.numerator[i].coefficient / factor

        if var[1] == 2:
            return quadratic_roots(coef.get(1, 0), constant / factor)

        elif var[1] == 3:
            return cubic_roots(coef.get(2, 0), coef.get(1, 0), constant / factor)

        else:
            return NotImplemented

    def to_principal_axes(self) -> dict[str, "Polynomial | str"]:
        """Converts a quadratic polynomial to its principal axes using matrix algebra"""
        from matrix import Matrix

        if tuple(self.numerator[0].variables.values())[0] > Fraction(2):
            raise PolynomialError("Quadratic polynomials can be transformed into its corresponding principal axes")

        res: Matrix[Fraction] = Matrix(2, 2, "null")

        for var in self.numerator:
            if var.variables:
                power: Fraction = tuple(var.variables.values())[0]
            else:
                power: Fraction = Fraction(0)

            if power == Fraction(2):
                position: int = int(tuple(var.variables.keys())[0][1]) - 1
                res[position][position] = var.coefficient

            elif power == Fraction(1):
                pos1: int = int(tuple(var.variables.keys())[0][1]) - 1
                pos2: int = int(tuple(var.variables.keys())[1][1]) - 1
                res[pos1][pos2] = var.coefficient / 2
                res[pos2][pos1] = var.coefficient / 2

        eigen_val: dict[str, Fraction] = res.eigen_values()
        numerator: list[Variable] = [Variable(coefficient=value, variables_dict={f"y{idx + 1}": 2}) for idx, value in
                                     enumerate(eigen_val.values())]
        numerator.append(self.numerator[-1])
        q = Polynomial(numerator_variables=numerator)
        conic_sec: str = self._conic_section(eigen_val, q.numerator[-1].coefficient)
        eigen_vec: tuple[tuple[Fraction]] = res.eigen_vectors()
        eigen_vec: tuple[tuple[Fraction]] = tuple(Matrix.normalize(vec) for vec in eigen_vec)
        x: Matrix[Fraction] = Matrix(2, 2, matrix=[list(vec) for vec in eigen_vec]).transpose()
        y: Matrix[Polynomial] = Matrix(2, 1, matrix=[[Polynomial("y1")], [Polynomial("y2")]])
        res: Matrix[Polynomial] = x * y
        return {"x1": res[0], "x2": res[1], "conic_section": conic_sec}

    copy: Callable[[], "Polynomial"] = lambda self: Polynomial(poly_obj=self)
    substitute: Callable[[str, Variable | Fraction], "Polynomial"] = lambda self, variable, value: (
        Polynomial(numerator_variables=[var.substitute(variable, value) for var in self.numerator],
                   denominator_variables=[var.substitute(variable, value) for var in self.denominator]))
