# ned to plot teh graph of 
# relative frequency line graph
# exponential pdfs
# normal pdfs
# frequency line graph find frequency
from math import *
from email import message
from matplotlib import *
from matplotlib import pyplot
import numpy as np
from scipy.stats import norm
# from scipy import stats
n = int(input("Enter the value: "))
data = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
freq_mssg = []
free = 0
time_of_messages = []
for i in range(0,30):
    free += data[i]
    time_of_messages.append(free)
# print(freq_mssg)
relate = []
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
r_freq_mssg = []
time_intervals = []
for i in range(5,466,5):
    time_intervals.append(i)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
for i in range(5,466,5):
    start = i-5
    end = i
    counter = 0
    for j in time_of_messages:
        if ((j>start) and (j <= end)):
            counter += 1
    freq_mssg.append(counter)
    r_freq_mssg.append(counter/30)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
sam_mean_List = []
sam_var_List = []
exponential_pdf = []
normal_pdf = []

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
for i in range(1,n+1):
    samMean = 0
    for j in range(0,i):
        samMean += data[j]
    CalSamMean = (samMean/i)
    sam_mean_List.append(CalSamMean)
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
for i in range(1,n+1):
    samVar = 0
    for j in range(0,i):
        samVar += ((data[j] - sam_mean_List[i-1])**2)
    if(i == 1):
        CalSamVar = 0
    else:
        CalSamVar = (samVar/(i-1))
    sam_var_List.append(CalSamVar)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
lambd = (1/((sam_var_List[-1])**(1/2)))
for i in range(0,n):
    exponential_pdf.append(lambd*((e)**(-(lambd*data[i]))))

for i in range(0,n):
    normal_pdf.append(((1/(((sam_var_List[-1])**(1/2))*((2*pi)**(1/2)))))**(e**((((-(data[i]-sam_mean_List[-1])))**2)/(2*(sam_var_List[-1])))))

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
print("THE LIST OF TIME SPAN IS: ")
print(data)
print("THE TIME TAKEN BY THE MESSAGES: ")
print(time_of_messages)
print("THE LIST OF TIME INTERVALS IS: ")
print(time_intervals)
print("THE LIST OF FREQ IS:")
print(freq_mssg)
print("THE LIST OF RELATIVE FREQ IS:")
print(r_freq_mssg)
print("THE SAMPLE MEAN LIST IS: ")
print(sam_mean_List)
print("THE SAMPLE VARIANCE LIST IS: ")
print(sam_var_List)
print("THE EXPONENTIAL PDF LIST IS: ")
print(exponential_pdf)
print("THE NORMAL PDF LIST IS: ")
print(normal_pdf)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------
fig1 = pyplot.figure("Exponential PDF Graph")
pyplot.plot(data,exponential_pdf,color = "violet")
pyplot.xlabel("Time Span")
pyplot.ylabel("Exponential PDF")
pyplot.title("Exponential PDF Graph")
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------

fig2 = pyplot.figure("Normal PDF Graph")
pyplot.plot(data,normal_pdf,color = "green")
pyplot.xlabel("Time Span")
pyplot.ylabel("Normal PDF")
pyplot.title("Normal PDF Graph")
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------

fig3 = pyplot.figure("Relative Frequency  vs  TimeIntervals")
pyplot.plot(time_intervals,r_freq_mssg,color = "orange")
pyplot.title("Relative Frequency  vs  TimeIntervals")
pyplot.xlabel("Time Gap")
pyplot.ylabel("RelativeFrequency")
pyplot.show()
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------

