import numpy as np
from PIL import Image


def ft_load(path: str) -> list:
    try:
        img = Image.open(path)
    except FileNotFoundError:
        raise FileNotFoundError(f"File not found: {path}")
    except Exception as e:
        raise Exception(f"Failed to load image: {e}")
    if img.format.lower() not in ['jpg', 'jpeg']:
        raise ValueError(f"Unsupported image format: {img.format}")
    img = np.array(img)

    image = np.array(img)
    size = 400
    h, w = image.shape[:2]
    center_y, center_x = h // 2, w // 2
    half = size // 2
    # zoomed = image[104:504, 462:862]
    zoomed = image[center_y-half-80:center_y+half-80,
                   center_x-half+150:center_x+half+150]

    zoomed = zoomed[:, :, [1]]
    print(f"The shape of image is: {zoomed.shape}")
    print(zoomed)
    return zoomed
