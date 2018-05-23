import zlib


# Borrowed from https://stackoverflow.com/a/2387880/5082374

def crc(fileName):
    prev = 0
    for eachLine in open(fileName, "rb"):
        prev = zlib.crc32(eachLine, prev)
    return "%X" % (prev & 0xFFFFFFFF)
