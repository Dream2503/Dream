from PIL import ImageChops
from PIL.Image import Image
from time import sleep
from pyautogui import click, screenshot

TARGET: tuple[int] = (975, 250, 1, 1)


def capture_screenshot(region: tuple[int]) -> Image:
    """Capture a screenshot of the specified region."""
    return screenshot(region=region)


def detect_color_change(image1: Image, image2: Image) -> tuple[int] | None:
    """Detect if there is a color change between two images."""
    return ImageChops.difference(image1, image2).getbbox()


def is_green(image: Image, box: tuple[int]) -> bool:
    """Check if the area within the bounding box is predominantly green."""
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    green_pixels: int = sum(1 for r, g, b in pixels if g > r and g > b and g > 100)
    total_pixels: int = len(pixels)

    return (green_pixels / total_pixels) > 0.5


def is_blue(image: Image, box: tuple[int]) -> bool:
    """Check if the area within the bounding box is predominantly blue."""
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    blue_pixels: int = sum(1 for r, g, b in pixels if b > r and b > g and b > 100)
    total_pixels: int = len(pixels)

    return (blue_pixels / total_pixels) > 0.5


print("Monitoring for color changes in the selected screen region. Press Ctrl+C to stop.")

prev_image: Image = capture_screenshot(TARGET)

try:
    while True:
        curr_image: Image = capture_screenshot(TARGET)
        diff_box: tuple[int] | None = detect_color_change(prev_image, curr_image)

        if diff_box:
            if is_green(curr_image, diff_box):
                click()

            if is_blue(curr_image, diff_box):
                sleep(1.5)
                click()

            prev_image = curr_image

except KeyboardInterrupt:
    print("\nMonitoring stopped.")
