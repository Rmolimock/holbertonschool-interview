#!/usr/bin/python3
# this module prints useful log info every 10 lines received from stdin

if __name__ == "__main__":
    from sys import stdin

    file_size, count = 0, 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    try:
        for line in stdin:
            data = line.split()
            ip = data[0]
            status = data[-2]
            size = data[-1]
            if int(status) in status_codes:
                status_codes[int(status)] += 1
            file_size += int(size)
            count += 1
            if count % 10 == 0:
                print("File size: {}".format(file_size))
                for code, value in sorted(status_codes.items()):
                    if value > 0:
                        print("{}: {}".format(code, value))

    except KeyboardInterrupt:
                print("File size: {}".format(file_size))
                for code, value in sorted(status_codes.items()):
                    if value > 0:
                        print("{}: {}".format(code, value))
                raise 
