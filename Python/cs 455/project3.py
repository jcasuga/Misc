import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import distance_matrix

iteration = 80
delta_t = 0.008
num_node = 50
dimension = 2
area = 3
nodes = np.random.uniform(size=(num_node, dimension), high=area)
variance = 2
gt = 40 # ground truth
gt_array = np.full((num_node, 1), gt)
measure = gt + np.random.uniform(size=(num_node, 1), high=variance, low=-variance)
activeR = 1 # active range
measure_all = np.zeros([num_node, iteration])
w = np.zeros([num_node, num_node])

def num_neighbors(ran):
  matrix =  distance_matrix(nodes,nodes)
  matrix[(matrix <= ran) & (matrix > 0)] = 1
  matrix[np.where(matrix != 1)] = 0
  return matrix, np.sum(matrix, axis=1)

def plot_neighbors():
  # nodes
  plt.plot(nodes[:, 0], nodes[:, 1], 'o', color='black')
  # neighbors
  for i in range(0, num_node):
      for j in range(0, num_node):
          distance = np.linalg.norm(nodes[j] - nodes[i])
          if distance <= activeR:
              plt.plot([nodes[i, 0], nodes[j, 0]],
                        [nodes[i, 1], nodes[j, 1]],
                        'b-', lw=0.5)
  plt.show()

def plot_value(measure):
  x = np.arange(0, num_node)
  plt.plot(x, measure, 'o', color='black')
  plt.plot(x, measure, color='black')
  plt.plot(x, gt_array, 'o', color='blue')
  plt.plot(x, gt_array, color='blue')
  plt.show()

def plot_covergence_error():
  x = np.arange(0, iteration)
  plt.title("Error Convergence")
  for i in range(0, num_node):
    plt.plot(x, gt - measure_all[i, :])
  plt.show()
  x = np.arange(0, iteration)
  plt.title("Mean Square Error Convergence")
  for i in range(0, num_node):
    plt.plot(x, (gt-measure_all[i, :])**2)
  plt.show()

def plot_min_max(degree_neighbors):
  x = np.arange(0, iteration)
  plt.title("Max and Min Neighbor Error Convergence")
  plt.plot(x, (gt - measure_all[np.argmax(degree_neighbors), :]), label="Max Neighbor")
  plt.plot(x, (gt - measure_all[np.argmin(degree_neighbors), :]), label="Min Neighbor")
  leg = plt.legend(loc='upper right')
  plt.show()
  plt.title("Max and Min Neighbor Mean Square Error Convergence")
  plt.plot(x, (gt - measure_all[np.argmax(degree_neighbors), :])**2, label="Max Neighbor")
  plt.plot(x, (gt - measure_all[np.argmin(degree_neighbors), :])**2, label="Min Neighbor")
  leg = plt.legend(loc='upper right')
  plt.show()

def maxDegreeWeights(i,j,adj_matrix, degree_neighbor):
  if i == j:
    return 1 - (degree_neighbor/num_node)
  if adj_matrix[i,j] == 1:
    return 1/num_node
  else:
    return 0
  
def metropolis(i,j,adj_matrix,degree_neighbor):
  if i == j:
    tot = 0
    for n in range(num_node):
      if adj_matrix[i,n] == 1:
        tot += metropolis(i,n,adj_matrix,degree_neighbor)
    return 1 - tot
  if adj_matrix[i,j] == 1:
    return 1/(1 + np.maximum(degree_neighbor[i], degree_neighbor[j]))
  else:
    return 0
  

def main():

  adj_matrix, degree_neighbors = num_neighbors(activeR)
  for i in range(num_node):
    for j in range(num_node):
      #w[i, j] = maxDegreeWeights(i, j, adj_matrix, degree_neighbors[i])
      w[i, j] = metropolis(i, j, adj_matrix, degree_neighbors)

  for iter in range(iteration):
    if iter == 0:
      plot_neighbors()
      for n in range(0, num_node):
        measure_all[n, iter] = measure[n]
      plot_value(measure)
    else:
      r_dynamic = activeR - np.random.uniform(0,0.3)
      adj_matrix, degree_neighbors = num_neighbors(r_dynamic)
      for i in range(num_node):
        for j in range(num_node):
            #w[i, j] = maxDegreeWeights(i, j, adj_matrix, degree_neighbors[i])
            w[i, j] = metropolis(i, j, adj_matrix, degree_neighbors)


      for i in range(num_node):
        sum = 0
        if degree_neighbors[n] != 0:
          for j in range(num_node):
            if np.linalg.norm(nodes[j] - nodes[i]) < activeR and i != j:
              sum += w[i,j] * measure_all[j, iter - 1]
          adj = adj_matrix[i]
          nWeight = w[i]
          neighborWeight = nWeight[adj == 1]
          neighMeasure = (((measure_all[:,iter - 1])[:, np.newaxis])[adj == 1])[:,0]
          el = neighborWeight * neighMeasure
          sum1 = np.sum(el)
        nMeasure = measure_all[i,iter - 1] * w[i,i] + sum1
        measure[i] = nMeasure
        measure_all[i,iter] = nMeasure
        
                     

  plot_value(measure_all[:,-1])
  plot_covergence_error()
  plot_min_max(degree_neighbors)
main()
