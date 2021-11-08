#IMPORT PANDAS, AND MATPLOTLIB
import pandas as pd 
import matplotlib.pyplot as plt

#Variable for data file
LIGHTFILE1 = open("OP9.TXT")

#Represents the time axis 
data_1_times = []
#Represents the Luxe axis
data_1_values = []

#Define a funciton to parse data from .TXT file
def LineByLine(loopedFile):
    for line in loopedFile:
        if "TIME: " in line:
            data_1_times.append(int(line[6:len(line)-1]))
        elif "LUX: " in line:
            data_1_values.append(int(line[5:len(line)-1]))
    print(data_1_times)
    print(data_1_values)

#Call LineByLine with the .TXT file
LineByLine(LIGHTFILE1)

#Create a pandas dataframe with two columns, time & lux amount
df = pd.DataFrame({"TIME (MILLIS FROM PROGRAM START)":data_1_times, "LUXES":data_1_values})

#Graph dataframe with Time on the x axis, and lux on the y axis
df.plot(x="TIME (MILLIS FROM PROGRAM START)", y="LUXES")
plt.show()