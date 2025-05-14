import numpy as np


def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """Calculate the BMI given weight and height."""

    if len(weight) != len(height):
        raise ValueError("Weight and height lists must be of the same length.")
    for h, w in zip(height, weight):
        if not isinstance(h, (int, float)) or not isinstance(w, (int, float)):
            raise TypeError("height and weight must be numeric.")
    if len(weight) == 0:
        raise ValueError("Weight and height lists must not be empty.")
    if any(h <= 0 for h in height):  # any built-in
        return "Height must be greater than 0."
    height = np.array(height)
    weight = np.array(weight)
    bmi = weight / (height ** 2)

    return bmi.tolist()


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """Apply a limit to the BMI list and return a boolean list."""
    for i in bmi:
        if not isinstance(i, (int, float)):
            raise TypeError("height and weight must be numeric.")
    if not isinstance(limit, int):
        raise ValueError("limit must not be empty.")
    if (limit < 0):
        return "Limit must be greater than 0."
    bmi = np.array(bmi)
    result = bmi > limit
    return result.tolist()
