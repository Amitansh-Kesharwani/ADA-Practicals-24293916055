import matplotlib.pyplot as plt

x = [100,500,1000,2000,5000,8000,10000,12000,15000,20000,30000]
y = [0.000026,0.000100,0.000185, 0.000370, 0.000946, 0.001483,0.001915,0.002341,0.002953,0.003859,0.005934]

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

plt.title("Time Complexity of Merge Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken", fontsize=12, color='purple')

plt.grid(True)
plt.show()
