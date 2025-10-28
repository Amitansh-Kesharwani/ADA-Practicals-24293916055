import matplotlib.pyplot as plt

x = [100,500,1000,2000,5000,8000,10000,12000]
y = [0.000011, 0.000173, 0.000678, 0.002564, 0.014720, 0.037192, 0.054807, 0.104178]

plt.figure(figsize=(10, 6)) 

plt.plot(
    x, y,
    color='red',          
    linestyle='-',        
    linewidth=2.5,        
    marker='o',           
    markersize=8,         
    markerfacecolor='yellow', 
    markeredgecolor='black',   
)

plt.title("Time Complexity of Insertion Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
