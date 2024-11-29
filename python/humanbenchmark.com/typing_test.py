from PIL import ImageGrab
from PIL.Image import Image
import pytesseract
import time
import keyboard
import mouse

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'
TARGET: tuple[int] = (325, 475, 1625, 725)

def capture_text_from_screen(target_area: tuple[int]) -> str:
    screenshot: Image = ImageGrab.grab(target_area)
    text: str = pytesseract.image_to_string(screenshot)
    return text.replace('\n', ' ').replace("  ", " ").strip()

def perform_actions(text: str) -> None:
    mouse.move(775, 450)
    mouse.click()
    keyboard.write(text)
    time.sleep(2)
    mouse.move(875, 575)
    mouse.click()

def main():
    time.sleep(2)

    for _ in range(1):
        text: str = capture_text_from_screen(TARGET)
        perform_actions(text)
        time.sleep(0.2)

if __name__ == "__main__":
    main()
