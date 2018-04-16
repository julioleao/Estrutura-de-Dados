# Busca (pesquisa) binária

import random

# busca binária iterativa
def binary_search_ite(vet, num):
	esquerda, direita, tentativa = 0, len(vet), 1
	while 1:
		meio = (esquerda + direita) // 2
		aux_num = vet[meio]
		if num == aux_num:
			return tentativa
		elif num > aux_num:
			esquerda = meio
		else:
			direita = meio
		tentativa += 1

# busca binária recursiva
def binary_search_rec(vet, num, esq, dir, tentativa):
	meio = (esq + dir) // 2
	aux_num = vet[meio]
	if num == aux_num:
		return tentativa
	elif num > aux_num:
		return binary_search_rec(vet, num, meio, dir, tentativa + 1)
	return binary_search_rec(vet, num, esq, meio, tentativa + 1)

# teste...
def teste():
	vet = [i for i in range(1, 1000001)]
	num = random.choice(vet)
	print('Numero escolhido: %d' % num)
	print('Tentativa (iterativo): %d' % binary_search_ite(vet, num))
	print('Tentativa (recursivo): %d' % binary_search_rec(vet, num, 0, len(vet), 1))

teste()