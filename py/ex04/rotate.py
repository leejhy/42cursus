import numpy as np
import matplotlib.pyplot as plt
from load_image import ft_load


def rotate_image(image: np.ndarray) -> np.ndarray:
    size = 400
    if image.ndim == 3:
        image = image[:, :, 0]  # (400, 400)으로 변환
    transposed = []
    for i in range(size):
        row = []
        for j in range(size):
            row.append(image[j][i])
        transposed.append(row)
    transposed = np.array(transposed)

    print(f"New shape after Transpose: {transposed.shape}")
    print(transposed)
    plt.imshow(transposed, cmap='gray')
    plt.grid(False)
    plt.show()


def main():
    img = ft_load("animal.jpeg")
    rotate_image(img)


if __name__ == "__main__":
    main()
