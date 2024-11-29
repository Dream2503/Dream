from PIL import Image, ImageChops
from mss.screenshot import ScreenShot
import time
import mouse
import mss

TARGET: tuple[int] = (975, 250)


def capture_screenshot(region: tuple[int]) -> Image:
    with mss.mss() as sct:
        monitor: dict[str, int] = {"top": region[1], "left": region[0], "width": 1, "height": 1}
        screenshot: ScreenShot = sct.grab(monitor)
        img: Image = Image.frombytes("RGB", screenshot.size, screenshot.bgra, "raw", "BGRX")
        return img


def is_green(image: Image) -> bool:
    r, g, b = tuple(image.getdata())[0]
    return g > r and g > b and g > 50


def is_blue(image: Image) -> bool:
    r, g, b = tuple(image.getdata())[0]
    return b > r and b > g and b > 50


def main():
    prev_image: Image = capture_screenshot(TARGET)

    try:
        while True:
            curr_image: Image = capture_screenshot(TARGET)
            diff_box: tuple[int] | None = ImageChops.difference(prev_image, curr_image).getbbox()

            if diff_box:
                if is_green(curr_image):
                    mouse.click()

                if is_blue(curr_image):
                    time.sleep(1.5)
                    mouse.click()

                prev_image: Image = curr_image

    except KeyboardInterrupt:
        print("\nMonitoring stopped.")


if __name__ == "__main__":
    main()
