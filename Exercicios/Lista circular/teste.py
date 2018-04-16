# Python Program for recursive binary search.
 
# Returns index of x in arr if present, else -1
def binarySearch (arr, l, r, x):
 
    # Check base case
    if r >= l:
 
        mid = l + (r - l)/2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
         
        # If element is smaller than mid, then it 
        # can only be present in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
 
        # Else the element can only be present 
        # in right subarray
        else:
            return binarySearch(arr, mid+1, r, x)
 
    else:
        # Element is not present in the array
        return -1
 
#Funcao Insertion Sort
def insertionSort(arr):
 
 	# Laco para percorrer o vetor comeca de i ate o tamanho do vetor len(arr)
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >=0 and key < arr[j] :
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = key
 
 
# Codigo para a execucao das funcoes acima
arr = [12, 11, 13, 5, 6]
print ("Vetor desordenado:")
for i in range(len(arr)):
    print ("%d" %arr[i])
insertionSort(arr)
print ("Vetor ordenado:")
for i in range(len(arr)):
    print ("%d" %arr[i])

# Valor a ser buscado no vetor arr
x = 13
 
# Chama a funcao de busca binaria passando x, o valor que deseja encontrar
result = binarySearch(arr, 0, len(arr)-1, x)

# Se o retorno da funcao for diferente de -1 significa que encontrou o elemento
# entao mostre na tela o indice onde ele se encontra.
# Caso contrario, imprima uma msg informando que nao foi encontrado o elemento
if result != -1:
    print "Elemento esta presente no indice %d" % result
else:
    print "Elemento %d nao encontrado no vetor" % x
 
