def FloydAlgorithm(matrix, size):
    for k in range(size):
        for i in range(size):
            for j in range(size):
                if (matrix[i][k] and matrix[k][j] and i != j):
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j] or matrix[i][j] == 0):
                        matrix[i][j] = matrix[i][k] + matrix[k][j]

def printArr(arr):
    for i in range(len(arr)):
        print(arr[i])
'''
  1 2 3 4
1 1 1 0 1
2 1 0 0 0
3 0 1 0 0
4 0 1 1 0
'''
matrix=[
    [1,1,0,1],
    [1,0,0,0],
    [0,1,0,0],
    [0,1,1,0]]


printArr(matrix)
FloydAlgorithm(matrix, len(matrix))
print("------------")
printArr(matrix)