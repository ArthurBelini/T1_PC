import os

mean = None
speedups = []
efficiencies = []
fr = open("resultados.txt", "r")

def get_mean():
    return (sum(data) / 10)

def write(string):
    fw = open("resultados.txt", "a")
    fw.write(string)
    fw.close()
    fr.readline()

for i in (1024, 2048, 4096):  # Tamanho da matriz
    mean = None
    speedups = []
    efficiencies = []
    data = []

    for j in range(10):  # Quantidade de vezes
        os.system('./mm_s ' + str(i))  # Sequencial

        data.append(float(fr.readline().split()[-1]))
        # print(data)

    mean = get_mean()
    write('m ' + str(get_mean()) + '\n')

    for j in (2, 4, 8, 16):  # Quantidade de threads
        data = []

        for k in range(10):  # Quantidade de vezes
            os.system('./mm_p ' + str(i) + ' ' + str(j))  # Paralelo

            data.append(float(fr.readline().split()[-1]))
            # print(data)

        speedups.append(mean / get_mean())
        efficiencies.append(speedups[-1] / j)

        write('m ' + str(get_mean()) + '\n')
        write('s ' + str(speedups[-1]) + '\n')
        write('e ' + str(efficiencies[-1]) + '\n')

    write(f's_curve (0,0)(2,{speedups[0]})(4,{speedups[1]})(8,{speedups[2]})(16,{speedups[3]})' + '\n')
    write(f'e_curve (0,0)(2,{efficiencies[0]})(4,{efficiencies[1]})(8,{efficiencies[2]})(16,{efficiencies[3]})' + '\n')
    
fr.close()
