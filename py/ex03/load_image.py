import numpy as np
from PIL import Image


def ft_load(path: str) -> np.ndarray:
    """Load an image from a file and convert it to a numpy array."""
    try:
        img = Image.open(path)
    except FileNotFoundError:
        raise FileNotFoundError(f"File not found: {path}")
    except Exception as e:
        raise Exception(f"Failed to load image: {e}")
    if img.format.lower() not in ['jpg', 'jpeg']:
        raise ValueError(f"Unsupported image format: {img.format}")
    img = np.array(img)

    img_np = np.array(img)
    print('The shape of image is:', img_np.shape)
    return img_np
