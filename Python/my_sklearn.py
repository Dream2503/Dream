import numpy as np
from typing import Literal


class MyStandardScaler:
    def __init__(self) -> None:
        self.mean: np.ndarray = np.ndarray((0, 0))
        self.scale: np.ndarray = np.ndarray((0, 0))
        self.var: np.ndarray = np.ndarray((0, 0))
        self.n_sample_seen: int = 0

    def fit(self, X: np.ndarray) -> None:
        self.mean = X.mean(axis=0)
        self.scale = X.std(axis=0)
        self.var = X.var(axis=0)
        self.n_sample_seen = X.shape[0]

    def transform(self, X: np.ndarray) -> np.ndarray:
        return (X - self.mean) / self.scale

    def fit_transform(self, X: np.ndarray) -> np.ndarray:
        self.fit(X)
        return self.transform(X)

    def inverse_transform(self, X: np.ndarray) -> np.ndarray:
        return X * self.scale + self.mean


class MyLinearRegression:
    def __init__(self, *, tol: float = 1e-3, alpha: float = 1, max_iter: int = 100,
                 method: Literal["gradient decent", "normal equation"] = "gradient decent") -> None:
        self.tol: float = tol
        self.alpha: float = alpha
        self.coef: np.ndarray = np.ndarray((0, 0))
        self.intercept: float = 0
        self.max_iter: int = max_iter
        self.method: str = method
        self.is_logistic: bool = False
        self.l1_ratio: float = 0
        self.total_iters: int = 0
        self.lambda_: float = 0
        self.sc: MyStandardScaler = MyStandardScaler()

    def fit(self, X: np.ndarray, y: np.ndarray) -> None:
        if self.method == "gradient decent":
            n_samples, n_features = X.shape
            self.coef = np.zeros(n_features)
            y: np.ndarray = y.ravel()
            X: np.ndarray = self.sc.fit_transform(X)

            for _ in range(self.max_iter):
                self.total_iters += 1

                if self.is_logistic:
                    y_pred: np.ndarray = (1 / (1 + np.exp(-(X.dot(self.coef) + self.intercept))))

                else:
                    y_pred: np.ndarray = X.dot(self.coef) + self.intercept

                error: np.ndarray = y - y_pred
                grad_v: np.ndarray = (-X.T.dot(error) / n_samples + self.lambda_ *
                                      ((1 - self.l1_ratio) * self.coef + self.l1_ratio * np.sign(self.coef)))
                grad_b: np.ndarray = -np.sum(error) / n_samples

                self.coef -= self.alpha * grad_v
                self.intercept -= self.alpha * grad_b

                if np.linalg.norm(grad_v) < self.tol and abs(grad_b) < self.tol:
                    self.coef /= self.sc.scale
                    self.intercept -= self.sc.mean.dot(self.coef)
                    break

        elif self.method == "normal equation":
            try:
                X_n: np.ndarray = np.concat([np.ones((X.shape[0], 1)), X], axis=1)
                coefs: np.ndarray = np.linalg.inv(X_n.T @ X_n) @ X_n.T.dot(y)
                self.intercept, self.coef = coefs[0], coefs[1:]

            except np.linalg.LinAlgError:
                self.method = "gradient decent"
                self.fit(X, y)

    def predict(self, X: np.ndarray) -> np.ndarray:
        z: np.ndarray = X.dot(self.coef) + self.intercept

        if self.is_logistic:
            return (1 / (1 + np.exp(-z)) >= 0.5).astype(int)

        return z


class MyLogisticRegression(MyLinearRegression):
    def __init__(self, *, tol: float = 1e-3, alpha: float = 1, max_iter: int = 100) -> None:
        super().__init__(tol=tol, alpha=alpha, max_iter=max_iter)
        self.is_logistic = True


class MyRidge(MyLinearRegression):
    def __init__(self, lambda_: float = 1, *, tol: float = 1e-3, alpha: float = 1, max_iter: int = 100):
        super().__init__(tol=tol, alpha=alpha, max_iter=max_iter)
        self.l1_ratio = 0
        self.lambda_ = lambda_


class MyLasso(MyLinearRegression):
    def __init__(self, lambda_: float = 1, *, tol: float = 1e-3, alpha: float = 1, max_iter: int = 100):
        super().__init__(tol=tol, alpha=alpha, max_iter=max_iter)
        self.l1_ratio = 1
        self.lambda_ = lambda_


class MyElasticNet(MyLinearRegression):
    def __init__(self, lambda_: float = 1, *, l1_ratio: float = 0.5, tol: float = 1e-3, alpha: float = 1,
                 max_iter: int = 100):
        super().__init__(tol=tol, alpha=alpha, max_iter=max_iter)
        self.l1_ratio = l1_ratio
        self.lambda_ = lambda_


def my_r2_score(y_true: np.ndarray, y_pred: np.ndarray) -> np.float64:
    ss_res: np.float64 = np.sum((y_true - y_pred) ** 2)
    ss_tot: np.float64 = np.sum((y_true - np.mean(y_true)) ** 2)
    return 1 - ss_res / ss_tot


def my_adjusted_r2_score(y_true: np.ndarray, y_pred: np.ndarray, n_features: int) -> np.float64:
    r2: np.float64 = my_r2_score(y_true, y_pred)
    n: int = y_true.shape[0]
    return 1 - (1 - r2) * (n - 1) / (n - n_features - 1)

def my_confusion_matrix(y_true: np.ndarray, y_pred: np.ndarray) -> np.ndarray:
    labels: np.ndarray = np.unique(np.concat((y_true, y_pred)))
    label_to_index: dict = {label: i for i, label in enumerate(labels)}
    n: int = len(labels)
    matrix: np.ndarray = np.zeros((n, n), dtype=int)

    for yt, yp in zip(y_true, y_pred):
        i: int = label_to_index[yt]
        j: int = label_to_index[yp]
        matrix[i][j] += 1

    return matrix
