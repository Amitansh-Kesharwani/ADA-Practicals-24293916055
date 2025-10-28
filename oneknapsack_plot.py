import matplotlib.pyplot as plt

x = [3,4,5,6,7,8,9,10,11,12,13,14,15,16]
y = [0.001000,0.001000,0.002000,0.001000,0.002000,0.002000,0.003000,0.003000,0.002000,0.003000,0.003000,0.004000,0.004000,0.004000]

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

plt.title("Time Complexity of 0/1 Knapsack", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
