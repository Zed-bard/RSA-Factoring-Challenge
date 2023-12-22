import sys

def read_textfile(filename, letters):
    with open(filename, 'r') as file:
        buf = file.read(letters)
        i = 0
        while i < len(buf):
            j = 0
            buf2 = ''
            while i < len(buf) and buf[i] != '\n':
                buf2 += buf[i]
                i += 1
                j += 1
            number = int(buf2)
            flag = 0
            k = 2
            while k < number // 2 and flag == 0:
                if number % k == 0:
                    flag = 1
                k += 1
            number2 = number // (k - 1)
            print(f"{number} = {number2} * {k - 1}")
            i += 1

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Please provide a filename.')
        sys.exit(1)
    filename = sys.argv[1]
    letters = 100
    read_textfile(filename, letters)
