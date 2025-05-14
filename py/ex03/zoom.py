import numpy as np
import matplotlib.pyplot as plt
from load_image import ft_load


def zoom_image(image: np.ndarray) -> np.ndarray:
    """Zoom into the center of the image."""
    size = 400
    h, w = image.shape[:2]
    center_y, center_x = h // 2, w // 2
    half = size // 2
    # zoomed = image[104:504, 462:862]
    print(image)
    zoomed = image[center_y-half-80:center_y+half-80,
                   center_x-half+150:center_x+half+150]

    zoomed = zoomed[:, :, [1]]
    print(f"New shape after slicing: {zoomed.shape}")
    print(zoomed)
    plt.imshow(zoomed, cmap='gray')
    plt.grid(False)
    plt.show()
    return zoomed


def main():
    img = ft_load("animal.jpeg")
    print(img)
    zoom_image(img)


if __name__ == "__main__":
    main()
