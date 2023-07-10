import os

for i in (1024, 2048, 4096):  # Tamanho da matriz
    for j in range(1, 17):  # Quantidade de threads
        for k in range(10):  # Quantidade de vezes
            os.system('./mm_p ' + str(i) + ' ' + str(j))