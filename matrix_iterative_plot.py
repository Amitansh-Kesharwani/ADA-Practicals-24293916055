import matplotlib.pyplot as plt

x = [3,4,5,6,7,8,9]
y = [0.001000,0.001000,0.004000,0.007000,0.009000,0.013000,0.020000]

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

plt.title("Time Complexity of Iterative matrix multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
