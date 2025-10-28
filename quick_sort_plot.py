import matplotlib.pyplot as plt

x = [10, 100, 200, 500, 800, 1000, 1200, 1500, 1800, 2000, 2500, 3000, 3500, 4000,5000,6000,8000,10000]
y = [0.000000, 0.000010, 0.000022, 0.000052, 0.000082, 0.000092, 0.000132, 0.000151, 0.000188, 0.000252, 0.000321, 0.000366, 0.000403, 0.000508,0.000655, 0.000869, 0.001101]

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

plt.title("Time Complexity of Quick Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
