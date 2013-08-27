# Reads data file to numpy data array, and then does a polar plot of data
import pylab
import numpy as np
from scipy import signal

# with open('C:\Users\Sam\Desktop\usonic_data_1', 'r') as f:
#   data = np.array(map(lambda x: long(x.strip()), f.readlines()))
# print data
FILENAME = 'data' # same folder

data = np.fromfile(FILENAME, dtype=int)
data = data.reshape((data.size/3, 3))
N = data.shape[0]
print "Received %g points of data." % (N*2)

direction = data[:,0]
left = data[:,1]
right = data[:,2]

low = min(direction)
high = max(direction)
print "Data scanned from %g to %g and %g to %g." % (low, high, low+180, high+180)

# scan_range = np.arange(low,high+1)
# scan_data = []
# for pos in scan_range:
#   vals = data[direction==pos]
#   avg = sum(vals)/len(vals)
#   # print pos, ":", avg
#   scan_data.append(avg)

#######
# pylab.plot(scan_range, scan_data, 'b')
# pylab.polar(scan_range * np.pi / 180.0, scan_data, 'b')
# pylab.axes([0.025, 0.025, 0.95, 0.95], polar=True)
pylab.polar(direction * np.pi / 180.0, left, 'b,', (direction+180) * np.pi / 180.0, right, 'r,')
# pylab.xlabel('Position')
# pylab.ylabel('Distance (mm)')
pylab.title('Ultrasonic Sensor Distance Scan Test')
pylab.show()
