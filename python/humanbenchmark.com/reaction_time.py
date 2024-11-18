import pyautogui
from PIL import ImageChops, Image
import time

# Define the region of the screen to monitor (x, y, width, height)
# Adjust these values based on your screen setup
TARGET: tuple[int] = (975, 250, 1, 1)  # Example: Top-left corner (300, 300), 5x5 size


def capture_screenshot(region: tuple[int]) -> Image:
    """Capture a screenshot of the specified region."""
    return pyautogui.screenshot(region=region)


def detect_color_change(image1: Image, image2: Image) -> tuple[int] | None:
    """Detect if there is a color change between two images."""
    diff: Image = ImageChops.difference(image1, image2)
    diff_bbox: tuple[int] | None = diff.getbbox()
    return diff_bbox


def is_green(image: Image, box: tuple[int]) -> bool:
    """Check if the area within the bounding box is predominantly green."""
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    green_pixels = sum(1 for r, g, b in pixels if g > r and g > b and g > 100)
    total_pixels = len(pixels)

    # If more than 50% of the pixels are green, return True
    return green_pixels / total_pixels > 0.5


def is_blue(image: Image, box: tuple[int]) -> bool:
    """Check if the area within the bounding box is predominantly blue."""
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    blue_pixels = sum(1 for r, g, b in pixels if b > r and b > g and b > 100)
    total_pixels = len(pixels)

    # If more than 50% of the pixels are blue, return True
    return blue_pixels / total_pixels > 0.5


def click_at(region: tuple[int], diff_bbox: tuple[int]):
    """Click at the region of the detected color change."""
    if diff_bbox:
        pyautogui.moveTo(region[0], region[1])
        pyautogui.click()
        print(f"Clicked at: ({region[0]}, {region[1]})\n")

print("Monitoring for color changes in the selected screen region. Press Ctrl+C to stop.")

prev_image: Image = capture_screenshot(TARGET)
still_blue = False

try:
    while True:
        curr_image: Image = capture_screenshot(TARGET)
        diff_box: tuple[int] | None = detect_color_change(prev_image, curr_image)

        if diff_box and is_green(curr_image, diff_box):
            print("Green Color detected!")
            click_at(TARGET, diff_box)
            still_blue = False

        if diff_box and is_blue(curr_image, diff_box) and not still_blue:
            print("Blue Color detected!")
            time.sleep(1.5)
            click_at(TARGET, diff_box)
            still_blue = True

        prev_image = curr_image

except KeyboardInterrupt:
    print("\nMonitoring stopped.")