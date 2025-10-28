import matplotlib.pyplot as plt

x = [100,500,1000,2000,5000,5500,6000,7000,8000]
y = [0.000027,0.000412,0.001438,0.005350,0.031398,0.037523,0.044491,0.061179,0.078649]

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

plt.title("Time Complexity of Bubble Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
