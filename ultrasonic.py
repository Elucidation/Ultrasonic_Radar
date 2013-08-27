import serial
import numpy as np

ser = serial.Serial(3)
print ser.portstr

N = 1000
direction = np.zeros( N, dtype=long)
data = np.zeros( N, dtype=long)

i = 0
while i < N:
  s = ser.readline(10)

  direction[i], data[i] = map(long, s.strip().split())
  i+=1
  if i % 100 == 0:
    print "%g/%g" % (i, N)
ser.close()

# print direction
# print data
data.tofile('data')
direction.tofile('direction')