# Reads data from Serial and saves it to a data file in numpy binary format.
import serial
import numpy as np

ser = serial.Serial(3)
print ser.portstr

N = 1000
# data is : [servo pos, left sensor vals, right sensor vals]
data = np.zeros( (N, 3), dtype=int)

i = 0
while i < N:
  s = ser.readline(100)
  if s[0] == ' ':
    print s.strip()
    continue
  bits = s.strip().split(' ')
  # bits = [pos, :, left, right]

  data[i] = [int(bits[0]), int(bits[2]), int(bits[3])]
  print data[i]
  i+=1
  if i % 100 == 0:
    print "%g/%g" % (i, N)
ser.close()

# print direction
# print data
data.tofile('data')
