import matplotlib.pyplot as plt

x = [50,75,100,125,150,175,200,250]
y = [0.131000,0.990000,1.065000,1.208000,7.254000,8.630000,8.862000,10.066000]

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

plt.title("Time Complexity of Divide and Conquer matrix multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
