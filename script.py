import os

fr = open("resultados.txt", "r")

def calculate_mean():
    fw = open("resultados.txt", "a")
    fw.write(str(sum(data) / 10) + '\n')
    fw.close()
    fr.readline()

for i in (1024, 2048, 4096):  # Tamanho da matriz
    data = []

    for j in range(10):  # Quantidade de vezes
        os.system('./mm_s ' + str(i))  # Sequencial

        data.append(float(fr.readline().split()[-1]))
        print(data)

    calculate_mean()

    for j in (2, 4, 8, 16):  # Quantidade de threads
        data = []

        for k in range(10):  # Quantidade de vezes
            os.system('./mm_p ' + str(i) + ' ' + str(j))  # Paralelo

            data.append(float(fr.readline().split()[-1]))
            print(data)

        calculate_mean()
        
fr.close()




