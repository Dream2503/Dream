from fractions import Fraction
from typing import Callable, Generator
from math import gcd, lcm, cos, acos, pi, sqrt as sqrtf
from cmath import sqrt as sqrtc


class Variable:
    def __init__(self, expression: str = "0", *, variable_obj: "Variable" = None, coefficient: Fraction = None,
                 variables_dict: dict[str, Fraction] = None) -> None:
        self._coefficient: Fraction = coefficient
        self._variables: dict[str, Fraction] = variables_dict

        if variable_obj is not None:
            self._coefficient: Fraction = variable_obj._coefficient
            self._variables: dict[str, Fraction] = variable_obj._variables

        expression = str(expression)

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
                    on_coef = False
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

        self._variables: dict[str, Fraction] = dict(sorted(self._variables.items()))

    @property
    def coefficient(self) -> Fraction:
        return self._coefficient

    @property
    def variables(self) -> dict[str, Fraction]:
        return self._variables

    def __repr__(self) -> str:
        return f"Variable({self._coefficient}, {self._variables})"

    def __str__(self) -> str:
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
            coefficient: Fraction = self.coefficient * other.coefficient
            variables: dict[str, Fraction] = {}

            for element in (self.variables, other.variables):
                for var, order in element.items():
                    variables[var] = variables.get(var, 0) + order

            return Variable(coefficient=coefficient, variables_dict=variables)

        else:
            try:
                other: Fraction = Fraction(other)
                return Variable(coefficient=self.coefficient * other, variables_dict=self.variables.copy())

            except ValueError:
                return NotImplemented

    def __truediv__(self, other: "Variable | Fraction") -> "Variable":
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
                other: Fraction = Fraction(other)
                return Variable(coefficient=self.coefficient / other, variables_dict=self.variables)

            except ValueError:
                return NotImplemented

    def __eq__(self, other: "Variable | Fraction") -> bool:
        if isinstance(other, Variable):
            return self.coefficient == other.coefficient and self.variables == other.variables

        else:
            try:
                other: Fraction = Fraction(other)
                return self.coefficient == other

            except ValueError:
                return NotImplemented

    __rmul__: Callable[["Variable", "Variable | Fraction"], "Variable"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Variable", "Variable | Fraction"], "Variable"] = lambda self, other: Variable(
        coefficient=other / self.coefficient, variables_dict={key: value * -1 for key, value in self.variables.items()})
    __abs__: Callable[["Variable"], "Variable"] = lambda self: Variable(coefficient=abs(self.coefficient),
                                                                        variables_dict=self.variables.copy())
    __bool__: Callable[["Variable"], bool] = lambda self: bool(self.coefficient)
    __neg__: Callable[["Variable"], "Variable"] = lambda self: self * -1
    __pos__: Callable[["Variable"], "Variable"] = lambda self: self
    __len__: Callable[["Variable"], int] = lambda self: len(self.variables)

    copy: Callable[["Variable"], "Variable"] = lambda self: Variable(coefficient=self.coefficient,
                                                                     variables_dict=self.variables.copy())

    def substitute(self, variable: str, value: Fraction) -> "Variable":
        if self.variables.get(variable, None) is not None:
            if len(self) == 1:
                return Variable(coefficient=self.coefficient * (value ** self.variables[variable]), variables_dict={})

            else:
                return Variable(coefficient=self.coefficient * (value ** self.variables[variable]),
                                variables_dict={key: value for key, value in self.variables.items() if key != variable})

        else:
            return self.copy()


class Term:
    def __init__(self, numerator_variables: str = "0", denominator_variables: str = "1", *,
                 term_obj: "Term | None" = None, numerator: list[Variable] | None = None,
                 denominator: list[Variable] | None = None) -> None:
        if term_obj is not None:
            self._numerator: list[Variable] = term_obj.numerator.copy()
            self._denominator: list[Variable] = term_obj.denominator.copy()

        else:
            self._numerator: list[Variable] = numerator if numerator \
                else [Variable(element) for element in numerator_variables.split()]
            self._denominator: list[Variable] = denominator if denominator \
                else [Variable(element) for element in denominator_variables.split()]

        self._init_simplify()

    @property
    def numerator(self) -> list[Variable]:
        return self._numerator

    @property
    def denominator(self) -> list[Variable]:
        return self._denominator

    def __repr__(self) -> str:
        return f"Term(numerator={self.numerator}, denominator={self.denominator})"

    def __str__(self) -> str:
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

        return f"({res[0]}) / ({res[1]})"

    def __add__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = self.numerator + [var * other for var in self.denominator]
            denominator: list[Variable] = self.denominator

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = self.numerator + [var * other.numerator for var in self.denominator]
                denominator: list[Variable] = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=numerator, denominator=denominator)

    def __sub__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [-var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator: list[Variable] = self.numerator + [var * -other for var in self.denominator]
            denominator: list[Variable] = self.denominator

        else:
            try:
                other: Fraction = Fraction(other)
                numerator: list[Variable] = self.numerator + [var * -other.numerator for var in self.denominator]
                denominator: list[Variable] = [var * other.denominator for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=numerator, denominator=denominator)

    def __mul__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
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

        return Term(numerator=numerator, denominator=denominator)

    def __truediv__(self, other: "Term | Variable | Fraction") -> "Term":
        if isinstance(other, Term):
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
                numerator: list[Variable] = [element * other.denominator for element in self.numerator]
                denominator: list[Variable] = [element * other.numerator for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Term(numerator=numerator, denominator=denominator)

    def __eq__(self, other: "Term | Variable| Fraction") -> bool:
        if isinstance(other, Term):
            return self.numerator == other.numerator and self.denominator == other.denominator

        elif isinstance(other, Variable):
            return self.__eq__(Term(numerator=[other]))

        else:
            try:
                return self.__eq__(Term(numerator=[Variable(coefficient=Fraction(other), variables_dict={})]))

            except ValueError:
                return NotImplemented

    __radd__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Term", "Term | Variable | Fraction"], "Term"] = lambda self, other: Term(
        numerator=self.denominator, denominator=self.numerator) * other
    __neg__: Callable[["Term"], "Term"] = lambda self: self * -1
    __pos__: Callable[["Term"], "Term"] = lambda self: self
    __len__: Callable[["Term"], int] = lambda self: len(self.variables())

    def _init_simplify(self) -> None:
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
                self._init_simplify()
                return

        if factor is not None:
            self._numerator: list[Variable] = [factor * element for element in self.numerator]
            self._denominator: list[Variable] = [factor * element for element in self.denominator]
            self.numerator.append(Variable(coefficient=main_var.coefficient,
                                           variables_dict={key: value for key, value in main_var.variables.items()
                                                           if key != check}))
            self._init_simplify()
            return

        factor: Variable = None
        check: Variable = None
        main_var: Variable = None
        broke: bool = False

        for idx, variable in enumerate(self.denominator):
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
                    self.denominator.pop(idx)
                    check: Variable = var
                    main_var: Variable = variable
                    broke: bool = True
                    break

            if broke and factor is None:
                self._init_simplify()
                return

        if factor is not None:
            self._numerator: list[Variable] = [factor * element for element in self.numerator]
            self._denominator: list[Variable] = [factor * element for element in self.denominator]
            self.denominator.append(Variable(coefficient=main_var.coefficient,
                                             variables_dict={key: value for key, value in main_var.variables.items()
                                                             if key != check}))
            self._init_simplify()

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

                res.append(var) if var else res.append(self.numerator[i])
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

        try:
            factor: list[str, Fraction] = list(tuple(self.numerator[0].variables.items())[0])

        except IndexError:
            factor: list[str, Fraction] = None

        try:
            coef: Fraction = self.numerator[0].coefficient

        except IndexError:
            coef: Fraction = Fraction(0)

        for element in self.numerator[1:]:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(factor[1], element.variables[factor[0]])

            else:
                factor: list[str, Fraction] = None

            coef: Fraction = Fraction(gcd(coef.numerator, element.coefficient.numerator),
                                      lcm(coef.denominator, element.coefficient.denominator))

        if factor:
            for element in self.denominator:
                if factor is not None and factor[0] in element.variables:
                    factor[1] = min(factor[1], element.variables[factor[0]])

                else:
                    factor: list[str, Fraction] = None

                coef: Fraction = Fraction(gcd(coef.numerator, element.coefficient.numerator),
                                          lcm(coef.denominator, element.coefficient.denominator))

        if factor:
            for term in (self.numerator, self.denominator):
                for element in term:
                    element.variables[factor[0]] -= factor[1]

    def substitute(self, variable: str, value: Fraction) -> "Term | Fraction":
        return Term(numerator=[var.substitute(variable, value) for var in self.numerator],
                    denominator=[var.substitute(variable, value) for var in self.denominator])

    def roots(self) -> tuple[float]:
        def quadratic_roots(b: Fraction, c: Fraction) -> tuple[float, float]:
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

        def cubic_roots(b: Fraction, c: Fraction, d: Fraction) -> tuple[
            float | complex, float | complex, float | complex]:
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
                return round(t1 - b / 3, 14), complex(x2, y2.real), complex(x2, -y2.real)

            else:
                theta: int = 0 if q == 0 else acos(r / (-q) ** (3 / 2))
                phis: Generator[float] = ((theta + (j * pi)) / 3 for j in range(0, 5, 2))
                return tuple(round(2 * sqrtf(-q) * cos(phi) - b / 3, 14) for phi in phis)

        def quartic_roots(a: Fraction, b: Fraction, c: Fraction, d: Fraction, e: Fraction) -> tuple[
            float, float, float, float]:
            return a, b, c, d, e

        var: str = tuple(self.numerator[0].variables.items())[0]
        factor: Fraction = self.numerator[0].coefficient
        constant: Fraction = self.numerator[-1].coefficient if self.numerator[-1].variables == {} else Fraction(0)
        coef: dict[Fraction, Fraction] = {}

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
