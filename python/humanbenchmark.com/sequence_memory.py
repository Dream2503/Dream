from PIL import Image, ImageChops
from mss.screenshot import ScreenShot
import mouse
import time
import mss

TARGET: dict[int, tuple[int]] = {
    1: (811, 404),
    2: (976, 404),
    3: (1141, 404),
    4: (811, 569),
    5: (976, 569),
    6: (1141, 569),
    7: (811, 733),
    8: (976, 733),
    9: (1141, 733)
}
TOTAL_TARGETS = len(TARGET)

def capture_screenshots(regions: dict[int, tuple[int]]) -> list[Image]:
    with mss.mss() as sct:
        img_lst: list[Image] = []

        for region in regions.values():
            monitor: dict[str, int] = {"top": region[1], "left": region[0], "width": 1, "height": 1}
            screenshot: ScreenShot = sct.grab(monitor)
            img_lst.append(Image.frombytes("RGB", screenshot.size, screenshot.bgra, "raw", "BGRX"))

        return img_lst

def detect_color_change(images1: list[Image], images2: list[Image]) -> list[int]:
    res: list[int] = []

    for i in range(TOTAL_TARGETS):
        bbox = ImageChops.difference(images1[i], images2[i]).getbbox()

        if bbox:
            res.append(i)

    return res

def get_black(images: list[Image], tiles: list[int]) -> list[int]:
    blacks: list[int] = []

    for i in tiles:
        r, g, b = tuple(images[i].getdata())[0]

        if r < 50 and g < 50 and b < 50:
            blacks.append(i+1)

    return blacks

def main():
    sequence: list[int] = []
    cnt: int = 0
    level: int = 1
    prev_images: list[Image] = capture_screenshots(TARGET)

    try:
        time.sleep(2)
        mouse.move(976, 695)
        mouse.click()

        while True:
            while cnt != level:
                curr_images: list[Image] = capture_screenshots(TARGET)
                changed_tiles: list[int] = detect_color_change(prev_images, curr_images)

                if changed_tiles:
                    black_pos: list[int] = get_black(curr_images, changed_tiles)

                    if black_pos:
                        sequence.append(black_pos[0])
                        cnt += 1

                prev_images: Image = curr_images

            time.sleep(1)

            for i in sequence:
                x, y = TARGET[i]
                mouse.move(x+5, y+5, duration=0.2)
                mouse.click()

            sequence: list[tuple[int]] = []
            cnt: int = 0
            level += 1


    except KeyboardInterrupt:
        print("\nMonitoring stopped.")

if __name__ == "__main__":
    main()