from PIL import ImageGrab
from PIL.Image import Image
import pytesseract
import time
import mouse

pytesseract.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"
TARGET: tuple[int] = (750, 475, 1200, 575)


def capture_text_from_screen(target_area: tuple[int]) -> str:
    screenshot: Image = ImageGrab.grab(target_area)
    text: str = pytesseract.image_to_string(screenshot)
    return text.strip()


def main():
    seen: set[str] = set()
    time.sleep(2)
    mouse.move(781, 581, duration=0.5)
    mouse.click()

    for _ in range(20):
        time.sleep(0.1)
        word: str = capture_text_from_screen(TARGET)

        if word in seen:
            mouse.move(710, 500, duration=0.5)
            mouse.click()

        else:
            seen.add(word)
            mouse.move(850, 500, duration=0.5)
            mouse.click()


if __name__ == "__main__":
    main()
