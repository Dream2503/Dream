from fractions import Fraction
from typing import Callable, Generic, TypeVar
from math import gcd, lcm, cos, acos, pi, sqrt as sqrtf
from cmath import sqrt as sqrtc

First = TypeVar("First")
Second = TypeVar("Second")

class Variable(Generic[First, Second]):
    def __init__(self, expression: str = "0", *, variable_obj: "Variable" = None, coefficient: Fraction = None,
                 variables_dict: dict[str, Fraction] = None) -> None:
        self._coefficient = coefficient
        self._variables = variables_dict

        if variable_obj is not None:
            self._coefficient = variable_obj._coefficient
            self._variables = variable_obj._variables

        expression = str(expression)

        if coefficient is None:
            on_coef = on_var = True
            on_order = False
            frac = ""
            var = []
            i, size = 0, len(expression)

            while i < size:
                if on_coef and expression[i].isalpha():
                    self._coefficient = Fraction(1)
                    on_coef = False
                    i -= 1

                elif on_coef and not expression[i].isalpha():
                    while i < size and not expression[i].isalpha():
                        frac += expression[i]
                        i += 1

                    self._coefficient = Fraction(frac)
                    frac = ""
                    i -= 1
                    on_coef = False

                elif on_var and expression[i].isalpha():
                    var.append(expression[i])
                    on_var, on_order = False, True

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
                    frac = ""
                    i -= 1
                    on_order, on_var = False, True

                i += 1

            var.append(Fraction(1)) if len(var) % 2 != 0 else var
            self._variables = {var[i - 1]: Fraction(var[i]) for i in range(1, len(var), 2)}

        self._variables = dict(sorted(self._variables.items()))

    @property
    def coefficient(self) -> Fraction:
        return self._coefficient

    @property
    def variables(self) -> dict[str, Fraction]:
        return self._variables

    def __repr__(self) -> str:
        return f"Variable({self._coefficient}, {self._variables})"

    def __str__(self) -> str:
        res = ""
        is_brace = False

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
            is_brace = True

        for variable, order in self._variables.items():
            if order != 0:
                if is_brace and order != 1:
                    res += '('

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
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient + other.coefficient, variables_dict=self.variables.copy())

        else:
            return NotImplemented

    def __sub__(self, other: "Variable") -> "Variable":
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient - other.coefficient, variables_dict=self.variables.copy())

        else:
            return NotImplemented

    def __mul__(self, other: "Variable | Fraction") -> "Variable":
        if isinstance(other, Variable):
            coefficient = self.coefficient * other.coefficient
            variables = {}

            for element in (self.variables, other.variables):
                for var, order in element.items():
                    variables[var] = variables.get(var, 0) + order

            return Variable(coefficient=coefficient, variables_dict=variables)

        else:
            try:
                other = Fraction(other)
                return Variable(coefficient=self.coefficient * other, variables_dict=self.variables.copy())

            except ValueError:
                return NotImplemented

    def __truediv__(self, other: "Variable | Fraction") -> "Variable":
        if isinstance(other, Variable):
            coefficient = self.coefficient / other.coefficient
            variables = {}

            for var, order in self.variables.items():
                variables[var] = variables.get(var, 0) + order

            for var, order in other.variables.items():
                variables[var] = variables.get(var, 0) - order

            return Variable(coefficient=coefficient, variables_dict=variables)

        else:
            try:
                other = Fraction(other)
                return Variable(coefficient=self.coefficient / other, variables_dict=self.variables)

            except ValueError:
                return NotImplemented

    def __eq__(self, other: "Variable | Fraction") -> bool:
        if isinstance(other, Variable):
            return self.coefficient == other.coefficient and self.variables == other.variables

        else:
            try:
                other = Fraction(other)
                return self.coefficient == other

            except ValueError:
                return NotImplemented

    __rmul__: Callable[["Variable", "Variable | Fraction"], "Variable"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Variable", "Variable | Fraction"], "Variable"] = lambda self, other: Variable(
        coefficient=other / self.coefficient, variables_dict={key: value * -1 for key, value in self.variables.items()})
    __abs__: Callable[["Variable"], "Variable"] = lambda self: Variable(coefficient=abs(self.coefficient),
                                                                        variables_dict=self.variables.copy())
    __neg__: Callable[["Variable"], "Variable"] = lambda self: self * -1
    __pos__: Callable[["Variable"], "Variable"] = lambda self: self

class Term:
    def __init__(self, numerator_variables: str = "0", denominator_variables: str = "1", *,
                 numerator: list[Variable[Fraction, dict[str, Fraction]]] | None = None,
                 denominator: list[Variable[Fraction, dict[str, Fraction]]] | None = None) -> None:
        if isinstance(numerator_variables, Term):
            numerator = numerator_variables.numerator.copy()
            denominator = numerator_variables.denominator.copy()

        elif isinstance(numerator_variables, Variable):
            numerator = [numerator_variables]

        elif isinstance(numerator_variables, str):
            pass

        else:
            numerator_variables = Fraction(numerator_variables)
            numerator = [Variable(numerator_variables)]

        self._numerator = numerator if numerator else [Variable(element) for element in numerator_variables.split()]
        self._denominator = denominator if denominator else [Variable(element) for element in
                                                             denominator_variables.split()]
        self._init_simplify()

    @property
    def numerator(self) -> list[Variable[Fraction, dict[str, Fraction]]]:
        return self._numerator

    @property
    def denominator(self) -> list[Variable[Fraction, dict[str, Fraction]]]:
        return self._denominator

    def __repr__(self) -> str:
        return f"Term(numerator={self.numerator}, denominator={self.denominator})"

    def __str__(self) -> str:
        res = []

        for term in (self.numerator, self.denominator):
            current = ""
            begin = True

            for element in term:
                if begin:
                    begin = False
                    current += str(element)

                elif element.coefficient > 0:
                    current += " + "
                    current += str(element)

                else:
                    current += " - "
                    current += str(abs(element))

            res.append('0' if not current else current)

        return f"({res[0]}) / ({res[1]})"

    def __add__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            numerator = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] +\
                        [var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator = self.numerator + [var * other for var in self.denominator]
            denominator = self.denominator

        else:
            try:
                other = Fraction(other)
                numerator = self.numerator + [var * other.numerator for var in self.denominator]
                denominator = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        res = Term(numerator=numerator, denominator=denominator)
        return res._operation_simplify()

    def __sub__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            numerator = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] +\
                        [-var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator = self.numerator + [var * -other for var in self.denominator]
            denominator = self.denominator

        else:
            try:
                other = Fraction(other)
                numerator = self.numerator + [var * -other.numerator for var in self.denominator]
                denominator = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=numerator, denominator=denominator)._operation_simplify()

    def __mul__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            num = [element1 * element2 for element1 in self.numerator for element2 in other.numerator]
            dec = [element1 * element2 for element1 in self.denominator for element2 in other.denominator]

        elif isinstance(other, Variable):
            num = [element * other for element in self.numerator]
            dec = self.denominator

        else:
            try:
                other = Fraction(other)
                num = [element * other.numerator for element in self.numerator]
                dec = [element * other.denominator for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=num, denominator=dec)._operation_simplify()

    def __truediv__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            num = [element1 * element2 for element1 in self.numerator for element2 in other.denominator]
            dec = [element1 * element2 for element1 in self.denominator for element2 in other.numerator]

        elif isinstance(other, Variable):
            num = self.numerator
            dec = [element * other for element in self.denominator]

        else:
            try:
                other = Fraction(other)
                num = [element * other.denominator for element in self.numerator]
                dec = [element * other.numerator for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=num, denominator=dec)._operation_simplify()

    def __eq__(self, other: "Term | Variable| Fraction") -> bool:
        if isinstance(other, Term):
            return self.numerator == other.numerator and self.denominator == other.denominator

        elif isinstance(other, Variable):
            temp = Term(numerator=[other])
            return self.__eq__(temp)

        else:
            try:
                other = Fraction(other)
                temp = Term(numerator=[Variable(coefficient=other, variables_dict={})])
                return self.__eq__(temp)

            except ValueError:
                return NotImplemented

    __radd__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: Term(
        numerator=self.denominator, denominator=self.numerator) * other
    __neg__: Callable[["Term"], "Term"] = lambda self: self * -1
    __pos__: Callable[["Term"], "Term"] = lambda self: self

    def _init_simplify(self) -> "Term":
        zero = factor = check = var_coef = None
        broke = False

        for idx, variable in enumerate(self.numerator):
            if variable.coefficient == 0:
                self.numerator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    zero = var
                    check = variable
                    broke = True
                    break

                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor = Variable(coefficient=Fraction(1), variables_dict={var: variable.variables[var]})
                    self.numerator.pop(idx)
                    check = var
                    var_coef = variable
                    broke = True
                    break

            if broke:
                break

        if zero is not None:
            check.variables.pop(zero)
            self._init_simplify()

        if factor is not None:
            self._numerator = [factor * element for element in self.numerator]
            self._denominator = [factor * element for element in self.denominator]
            self.numerator.append(Variable(coefficient=var_coef.coefficient,
                                           variables_dict={key: value for key, value in var_coef.variables.items()
                                                           if key != check}))
            self._init_simplify()

        zero = factor = check = var_coef = None
        broke = False

        for idx, variable in enumerate(self.denominator):
            if variable.coefficient == 0:
                self.numerator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    zero = var
                    check = variable
                    broke = True
                    break
                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor = Variable(coefficient=Fraction(1), variables_dict={var: variable.variables[var]})
                    self.denominator.pop(idx)
                    check = var
                    var_coef = variable
                    broke = True
                    break

            if broke:
                break

        if zero is not None:
            check.variables.pop(zero)
            self._init_simplify()

        if factor is not None:
            self._numerator = [factor * element for element in self.numerator]
            self._denominator = [factor * element for element in self.denominator]
            self.denominator.append(Variable(coefficient=var_coef.coefficient,
                                             variables_dict={key: value for key, value in var_coef.variables.items()
                                                             if key != check}))
            self._init_simplify()

        self.numerator.sort(key=lambda value: tuple(value.variables.keys()))
        self.numerator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)
        self.denominator.sort(key=lambda value: tuple(value.variables.keys()))
        self.denominator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)

        return self

    def _operation_simplify(self) -> "Term":
        change = False

        while not change:
            res = []
            size, i = len(self.numerator), 0

            while i < size:
                var = None

                try:
                    if var:
                        var += self.numerator[i] + self.numerator[i + 1]
                    else:
                        var = self.numerator[i] + self.numerator[i + 1]

                    change = True
                    i += 1

                except (TypeError, IndexError):
                    pass

                res.append(var) if var else res.append(self.numerator[i])
                i += 1

            if change:
                self._numerator = res
                change = False

            else:
                change = True

        change = False

        while not change:
            res = []
            size, i = len(self.denominator), 0

            while i < size:
                var = None

                try:
                    if var:
                        var += self.denominator[i] + self.denominator[i + 1]
                    else:
                        var = self.denominator[i] + self.denominator[i + 1]

                    change = True
                    i += 1

                except (TypeError, IndexError):
                    pass

                res.append(var) if var else res.append(self.denominator[i])
                i += 1

            if change:
                self._denominator = res
                change = False

            else:
                change = True

        try:
            factor: list[str, Fraction] = list(tuple(self.numerator[0].variables.items())[0])

        except IndexError:
            factor = None
        try:
            coef = self.numerator[0].coefficient

        except IndexError:
            coef = 0

        for element in self.numerator[1:]:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(factor[1], element.variables[factor[0]])

            else:
                factor = None

            coef = Fraction(gcd(coef.numerator, element.coefficient.numerator), lcm(coef.denominator, element.coefficient.denominator))

        if factor:
            for element in self.denominator:
                if factor is not None and factor[0] in element.variables:
                    factor[1] = min(factor[1], element.variables[factor[0]])

                else:
                    factor = None

                coef = Fraction(gcd(coef.numerator, element.coefficient.numerator), lcm(coef.denominator, element.coefficient.denominator))

        if factor:
            for term in (self.numerator, self.denominator):
                for element in term:
                    element.variables[factor[0]] -= factor[1]

        return Term(numerator=self.numerator, denominator=self.denominator)

    def roots(self) -> tuple[float, ...]:
        def quadratic_roots(b: Fraction, c: Fraction) -> tuple[float, float]:
            determinant = (b * b) - (4 * c)

            if determinant >= 0:
                root1 = (-b + sqrtf(determinant)) / 2

                if determinant != 0:
                    root2 = (-b - sqrtf(determinant)) / 2

                else:
                    root2 = root1

            else:
                return (-b + sqrtc(determinant)) / 2, (-b - sqrtc(determinant)) / 2

            return round(root1, 15), round(root2, 15)

        def cubic_roots(b: Fraction, c: Fraction, d: Fraction) -> tuple[float, float, float]:
            q = (c / 3) - (b ** 2 / 9)
            r = ((c * b - 3 * d) / 6) - (b ** 3 / 27)
            check = r ** 2 + q ** 3

            if check > 0:
                a = (abs(r) + sqrtc(check)) ** (1 / 3)

                if r >= 0:
                    t1 = a - (q / a)
                else:
                    t1 = (q / a) - a

                x2 = -t1 / 2 - b / 3
                y2 = sqrtc(3) / 2 * (a + (q / a))
                return round(t1 - b / 3, 14), complex(x2, y2.real), complex(x2, -y2.real)

            else:
                theta = 0 if q == 0 else acos(r / (-q) ** (3 / 2))
                phis = ((theta + (j * pi)) / 3 for j in range(0, 5, 2))
                return tuple(round(2 * sqrtf(-q) * cos(phi) - b / 3, 14) for phi in phis)

        def quartic_roots(a: Fraction, b: Fraction, c: Fraction, d: Fraction, e: Fraction) -> tuple[
            float, float, float, float]:
            return a, b, c, d, e

        var = tuple(self.numerator[0].variables.items())[0]
        factor = self.numerator[0].coefficient
        constant = self.numerator[-1].coefficient if self.numerator[-1].variables == {} else 0
        coef = {}

        for i in range(len(self.numerator) - (1 if constant else 0)):
            if len(self.numerator[i].variables) != 1 or var[0] not in self.numerator[i].variables:
                raise ValueError("roots of the this Equation cannot be determined")

            coef[self.numerator[i].variables[var[0]]] = self.numerator[i].coefficient / factor

        if var[1] == 2:
            return quadratic_roots(coef.get(1, 0), constant / factor)

        elif var[1] == 3:
            return cubic_roots(coef.get(2, 0), coef.get(1, 0), constant / factor)

        elif var[1] == 4:
            return quartic_roots(coef[4], coef.get(3, 0), coef.get(2, 0), coef.get(1, 0), constant / factor)
