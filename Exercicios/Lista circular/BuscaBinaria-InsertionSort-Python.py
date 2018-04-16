# Nome: Julio Cesario de Paiva Leao
# RA: 1916033
# Estrutura de Dados
# Engenharia de Software 2018/01

# TRABALHO 2
# vamos dar uma variada?

# escolha uma das estruturas de dados vistas ate o momento, e um metodo de ordenacao;
# implemente em qualquer outra linguagem de programacao que nao possua ponteiros!
# 	> JavaScript;
# 	> PHP;
# 	> Java;
# 	> C#;
# 	> NodeJS;
# 	> Python;
# 	> Ruby;

 
# Funcao para busca binaria
def binarySearch (arr, left, right, x):
 
    # Teste de saida da funcao recursiva
    if right >= left:
 		# descobre a metade do vetor
        mid = left + (right - left)/2
 
        # Se o elemento procurado estiver no meio do vetor, retorne o meio
        if arr[mid] == x:
            return mid
         
        # Se o elemento procurado for menor que o meio do vetor
        # entao chama a fancao de novo, passando o vetor (arr),
        # lado esquerdo (left), meio - 1 (mid-1) e o valor a ser procurado (x)
        # Realizando assim novamente a funcao de forma recusrsiva. 
        elif arr[mid] > x:
            return binarySearch(arr, left, mid-1, x)
 
        # Se o elemento procurado for maior que o meio do vetor
        # entao chama a fancao de novo, passando o vetor (arr),
        # meio + 1 (mid+1), lado direito (right) e o valor a ser procurado (x)
        # Realizando assim novamente a funcao de forma recusrsiva. 
        else:
            return binarySearch(arr, mid+1, right, x)
 
    else:
        # Se o valor (x) nao for encontrado, retorna entao -1
        return -1
 
#Funcao Insertion Sort
def insertionSort(arr):
 
 	# Laco para percorrer o vetor comeca de i, valendo 1, vai ate o tamanho do vetor len(arr)
    for i in range(1, len(arr)):
 		# variavel aux recebe a posicao i do vetor, nesse caso posicao 1
        aux = arr[i]
 
        # Entra no laco, e percorra enquanto j for maior que 0
        # e aux for menor que o vetor arr[j].
        # enquanto no laco, se aux for menor que arr[j]
        # entao a roxima posicao do arr[j+1] recebe esse valor
        # decrementa o j em -1
        # fora do laco, pegue o vetor na primeira posicao, nesse caso ele vai atingir a primeira posicao
        # e coloque o valor de aux, finalizando assim a ordenacao
        j = i-1
        while j >=0 and aux < arr[j] :
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = aux
 
 
# Codigo para a execucao das funcoes acima
arr = [12, 11, 13, 5, 6, 47, 3, 5, 1, 89]
print ("Vetor desordenado:")
# imprime o vetor desordenado
print (arr)
# chama a funcao de ordenacao
insertionSort(arr)

print ("\nVetor ordenado:")
# imprime o vetor ordenado
print (arr)

# Valor a ser buscado no vetor arr
x = 47
 
# Chama a funcao de busca binaria passando x, o valor que deseja encontrar, como parametro
# o vetor arr, a posicao inicial 0 e o tamanho total do vetor arr len(arr)
result = binarySearch(arr, 0, len(arr)-1, x)

# Se o retorno da funcao for diferente de -1 significa que encontrou o elemento
# entao mostre na tela o indice onde ele se encontra.
# Caso contrario, imprima uma msg informando que nao foi encontrado o elemento.
if result != -1:
    print "\nElemento %d esta presente no indice %d.\n" % (x, result)
else:
    print "\nElemento %d nao foi encontrado no vetor.\n" % x
 
