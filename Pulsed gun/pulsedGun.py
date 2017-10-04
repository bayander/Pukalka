import serial, time, sys

def chsumm(message):
    result = 0
    for ch in message:
        result += ord(ch)
    return str(result%256).zfill(3)

ser = serial.Serial(port = sys.argv[1], baudrate = 9600)

if ser.isOpen():
    ser.close()

ser.open()
time.sleep(2)

def send(f, d):
    message = '001GUN'
    message += str(f).zfill(3)
    message += str(d).zfill(3)
    message += chsumm(message) + '\n'
    ser.write(message.encode())
    print " - ", ser.readline()

freq = 4
dFac = 50

while True:
    key = raw_input('>> ')
    if (key == 'f'):
        freq = int(raw_input('freq = '))
        send(freq, dFac)
    elif (key == 'd'):
        dFac = int(raw_input('dFac = '))
        send(freq, dFac)
    elif (key == 'stop'):
        send(freq, 0)
    elif (key == 'start'):
        send(freq, dFac)
    elif (key == 'q'):
        break
 
ser.close()
