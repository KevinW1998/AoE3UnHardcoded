import os

import binascii
from typing import Sequence

def calculate_timestamp_hash(input_folder: str, list_of_classes: Sequence[str]) -> str:
    # my_class --> input_folder/my_class.h
    all_files = map(lambda class_name: os.path.normpath(os.path.join(input_folder, class_name + ".h")), list_of_classes)

    # Collect the timestamps of all
    all_files_timestamp = map(lambda next_full_file: str(os.path.getmtime(next_full_file)), all_files)

    # Calculate crc of joined timestamps
    joined_timestamps = ", ".join(all_files_timestamp)

    return str(binascii.crc32(joined_timestamps.encode()))


def has_file_changes(input_folder: str, list_of_classes: Sequence[str], hash_file: str) -> bool:
    if not os.path.exists(hash_file):
        return True

    hash_str = ""
    with open(hash_file) as f:
        lines = f.readlines()
        if len(lines) >= 1:
            hash_str = lines[0]
        else:
            return True

    return hash_str != calculate_timestamp_hash(input_folder, list_of_classes)

def write_file_change_hash(input_folder: str, list_of_classes: Sequence[str], hash_file: str) -> None:
    calc_hash = calculate_timestamp_hash(input_folder, list_of_classes)
    with open(hash_file, 'w') as f:
        f.write(calc_hash)


