import matplotlib.pyplot as plt

x = [15, 55, 105, 505, 1005, 3005, 5005, 6005, 7005, 8005]
y = [0.000001, 0.000002, 0.000002, 0.000002, 0.000024, 0.000096, 0.000162, 0.000184, 0.000203, 0.000175]

plt.figure(figsize=(8, 5)) 

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

plt.title("Time Complexity of Linear Search", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
