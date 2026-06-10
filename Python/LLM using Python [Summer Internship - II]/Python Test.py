# Q1. Write a python code snippet to delete a directory and it’s contents ?
from typing import Literal


def delete_directory(directory_path: str) -> bool:
    import shutil
    import os

    if os.path.exists(directory_path):
        shutil.rmtree(directory_path)
        print("Directory deleted successfully.")
        return True

    else:
        print("Directory does not exist.")
        return False


# Q2. Write a Python code snippet to filter and search criteria based files ?
def search_files(directory: str, criteria: Literal["name", "size", "extension"], value: str | int) -> list[str]:
    import os

    files = os.listdir(directory)

    match criteria:
        case "name":
            if isinstance(value, str):
                return [file for file in files if value in file]

            raise ValueError("value must be str")

        case "size":
            if isinstance(value, int):
                return [file for file in files if os.path.getsize(file) >= value]

            raise ValueError("value must be int")

        case "extension":
            if isinstance(value, str):
                return [file for file in files if file.endswith(value)]

            raise ValueError("value must be str")


# Q3. Write a Python code snippet to Zip Archive?
def zip_archive(files: list[str] | str, type: Literal["files", "folder"], filename: str) -> None:
    match type:
        case "files":
            if isinstance(files, list):
                with open(filename, "w") as destination:
                    for file in files:
                        if isinstance(file, str):
                            with open(file, "r") as source:
                                destination.write(source.read())
                        else:
                            break
                    else:
                        return

            raise ValueError("Must give list of filenames")

        case "folder":
            if isinstance(files, str):
                import os

                file_names = os.listdir(files)

                with open(filename, "w") as destination:
                    for file in file_names:
                        if isinstance(file, str):
                            with open(file, "r") as source:
                                destination.write(source.read())
                        else:
                            break
                    else:
                        return
            raise ValueError("Must give a valid single folder name")


# Q4. Write a Python code snippet to retrieve web content ?
def retrieve_web_content(url: str) -> str:
    import requests

    response = requests.get(url)

    if response.status_code == 200:
        return response.text

    raise RuntimeError(f"Error: {response.status_code}")


# Q5.
def ip_range_to_list(input_ip_range) -> list[str]:
    import socket
    import struct

    start_ip, end_ip = input_ip_range.split('-')

    start_int = struct.unpack("!I", socket.inet_aton(start_ip.strip()))[0]
    end_int = struct.unpack("!I", socket.inet_aton(end_ip.strip()))[0]

    return [socket.inet_ntoa(struct.pack("!I", ip_int)) for ip_int in range(start_int, end_int + 1)]
