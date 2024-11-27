from PIL import Image, ImageChops
from mss.screenshot import ScreenShot
import time
import mouse
import mss

TARGET = (975, 250, 1, 1)


def capture_screenshot(region: tuple[int]) -> Image:
    with mss.mss() as sct:
        monitor: dict[str, int] = {"top": region[1], "left": region[0], "width": region[2], "height": region[3]}
        screenshot: ScreenShot = sct.grab(monitor)
        img: Image = Image.frombytes("RGB", screenshot.size, screenshot.bgra, "raw", "BGRX")
        return img


def detect_color_change(image1: Image, image2: Image) -> tuple[int]:
    return ImageChops.difference(image1, image2).getbbox()


def is_green(image: Image, box: tuple[int]) -> bool:
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    green_pixels: int = sum(1 for r, g, b in pixels if g > r and g > b and g > 100)
    total_pixels: int = len(pixels)

    return (green_pixels / total_pixels) > 0.5


def is_blue(image: Image, box: tuple[int]) -> bool:
    cropped_area: Image = image.crop(box)
    pixels: tuple[tuple[int]] = tuple(cropped_area.getdata())

    blue_pixels: int = sum(1 for r, g, b in pixels if b > r and b > g and b > 100)
    total_pixels: int = len(pixels)

    return (blue_pixels / total_pixels) > 0.5


def main():
    prev_image: Image = capture_screenshot(TARGET)

    try:
        while True:
            curr_image: Image = capture_screenshot(TARGET)
            diff_box: tuple[int] = detect_color_change(prev_image, curr_image)

            if diff_box:
                if is_green(curr_image, diff_box):
                    mouse.click()

                if is_blue(curr_image, diff_box):
                    time.sleep(1.5)
                    mouse.click()

                prev_image: Image = curr_image

    except KeyboardInterrupt:
        print("\nMonitoring stopped.")


if __name__ == "__main__":
    main()
