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
# data = []
freq_mssg = [1,5,2,8,14,9,2,3,8,16,4,7,9,5,4,6,18,8,5,4,5,7,8,4,25,6,17,8,4,15]
# freq_mssg = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0]
# freq_mssg = [4,1,3,5,8,12,15,7,17,20,23,23,27,30,32,26,25,25,21,20,18,17,15,13,10,9,5,3,2,0]
r_freq_mssg = []

for i in freq_mssg:
    if i not in data:
        data.append(freq_mssg)

sum = 0
for i in range(0,n):
    sum += data[i]

for i in range(0,n):
    r_freq_mssg.append(data[i]/sum)


sam_mean_List = []
sam_var_List = []
exponential_pdf = []
normal_pdf = []


for i in range(1,n+1):
    samMean = 0
    for j in range(0,i):
        samMean += data[j]
    CalSamMean = (samMean/i)
    sam_mean_List.append(CalSamMean)

for i in range(1,n+1):
    samVar = 0
    for j in range(0,i):
        # print(sam_mean_List[i-1])
        samVar += ((freq_mssg[j] - sam_mean_List[i-1])**2)
        # print(samVar)
    if(i == 1):
        CalSamVar = 0
        # print(samVar)
        # print(i-1)
    else:
        print(samVar)
        print(i-1)
        CalSamVar = (samVar/(i-1))
        # print(CalSamVar)
    sam_var_List.append(CalSamVar)

lambd = (1/((sam_var_List[-1])**(1/2)))
for i in range(0,n):
    exponential_pdf.append(lambd*((e)**(-(lambd*freq_mssg[i]))))

for i in range(0,n):
    # normal_pdf.append(stats.norm(data[i],((sam_var_List[-1])**(1/2))))
    normal_pdf.append(((1/(((sam_var_List[-1])**(1/2))*((2*pi)**(1/2)))))**(e**((((-(freq_mssg[i]-sam_mean_List[-1])))**2)/(2*(sam_var_List[-1])))))

print(sam_mean_List)
print(sam_var_List)
print(exponential_pdf)
print(normal_pdf)
# pyplot.plot(exponential_pdf,data,color = "violet")
fig1 = pyplot.figure("Exponential PDF Graph")
pyplot.plot(data,exponential_pdf,color = "violet")
pyplot.xlabel("Time Span")
# pyplot.xlabel("Relative Frequency")
pyplot.ylabel("Exponential PDF")
# pyplot.plot(exponential_pdf,r_freq_mssg,color = "violet")
# pyplot.plot(data,exponential_pdf,color = "violet")
pyplot.title("Exponential PDF Graph")
# pyplot.show()

# normal_pdf = norm.pdf(freq_mssg,sam_mean_List[-1],(sam_var_List[-1]**(1/2)))
print("the list is",normal_pdf)

fig2 = pyplot.figure("Normal PDF Graph")
pyplot.plot(data,normal_pdf,color = "green")
pyplot.xlabel("Time Span")
# pyplot.xlabel("Relative Frequency")
pyplot.ylabel("Normal PDF")
# pyplot.plot(normal_pdf,r_freq_mssg,color = "green")
# pyplot.plot(data,normal_pdf,color = "green")
pyplot.title("Normal PDF Graph")

# fig3 = pyplot.figure("PDF Graph")
# pyplot.plot(r_freq_mssg,data,color = "orange")
# # pyplot.plot(data,r_freq_mssg,color = "orange")
# # pyplot.plot(data,normal_pdf,color = "green")
# pyplot.title("PDF Graph")

fig3 = pyplot.figure("Freq vs TimeSpan")
pyplot.plot(data,r_freq_mssg,color = "orange")
# pyplot.plot(data,r_freq_mssg,color = "orange")
# pyplot.plot(data,normal_pdf,color = "green")
pyplot.title("Freq vs TimeSpan")
pyplot.xlabel("Time Gap")
pyplot.ylabel("Frequency")
pyplot.show()


