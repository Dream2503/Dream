import cv2
import keyboard
import numpy as np
from PIL import ImageGrab, ImageChops
from PIL.Image import Image
import pytesseract
import time
import mouse

pytesseract.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"
TARGET: tuple[int] = (700, 450, 1200, 600)
CHANGE: tuple[int] = (400, 500, 401, 501)

def capture_text_from_screen(target_area: tuple[int]) -> str:
    # Capture the screen area
    screenshot = ImageGrab.grab(bbox=target_area)

    # Convert the image to grayscale
    gray = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2GRAY)

    # Apply adaptive thresholding to enhance text
    thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                                   cv2.THRESH_BINARY_INV, 11, 2)

    # Configure Tesseract to recognize only digits
    custom_config = r'--oem 3 --psm 6 -c tessedit_char_whitelist=0123456789'

    # Extract text from the processed image
    numbers = pytesseract.image_to_string(thresh, config=custom_config)

    return numbers.strip()


def main():
    time.sleep(2)
    mouse.move(781, 571, duration=0.5)
    mouse.click()

    for _ in range(5):
        time.sleep(0.1)
        num: str = capture_text_from_screen(TARGET)
        prev_img = ImageGrab.grab(CHANGE)

        while True:
            curr_img = ImageGrab.grab(CHANGE)
            diff = ImageChops.difference(prev_img, curr_img).getbbox()


            if diff:
                break

            prev_img = curr_img

        time.sleep(0.5)
        keyboard.write(num)
        print(num)
        keyboard.send("enter")
        time.sleep(2)
        keyboard.send("enter")


if __name__ == "__main__":

    main()
