import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """Slices a 2D list (family) from start to end index."""
    if not isinstance(family, list):
        raise TypeError("family must be a list")
    for row in family:
        if not isinstance(row, list):
            raise ValueError("each row must be a list")
    if len(row) != 2:
        raise ValueError("each row must have exactly 2 elements")
    if not isinstance(start, int) or not isinstance(end, int):
        raise TypeError("start and end must be integers")

    shape = np.shape(family)
    if len(shape) != 2:
        raise ValueError("family must be a 2D list")
    print('My shape is :', shape)

    family = family[start:end]
    print('My new shape is :', np.shape(family))
    return family
