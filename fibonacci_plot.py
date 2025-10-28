import matplotlib.pyplot as plt

# Input sizes (fill this manually)
ns = [15,25,35]

# Execution times in seconds (manually enter from C outputs)
times_recursive = [0.000000,0.000000,0.071000]
times_iterative = [0.005000,0.011000,0.012000]
times_topdown   = [0.000000,0.000000,0.000000]
times_bottomup  = [0.006000,0.011000,0.013000]

# Plotting
plt.figure(figsize=(10,6))
plt.plot(ns, times_recursive, marker="o", label="Recursive")
plt.plot(ns, times_iterative, marker="s", label="Iterative")
plt.plot(ns, times_topdown, marker="^", label="Top Down DP")
plt.plot(ns, times_bottomup, marker="d", label="Bottom Up DP")

plt.xlabel("n (Input Size)")
plt.ylabel("Execution Time (seconds)")
plt.title("Fibonacci Algorithms Time Comparison")
plt.legend()
plt.grid(True)
plt.show()
