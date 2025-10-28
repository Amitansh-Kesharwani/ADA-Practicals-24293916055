import matplotlib.pyplot as plt

x = [100, 500, 1000, 2000, 3000, 5000,8000, 10000]
y = [0.000018, 0.000239, 0.000910, 0.003477, 0.007587, 0.020643, 0.076750, 0.088325]

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

plt.title("Time Complexity of Selection Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
