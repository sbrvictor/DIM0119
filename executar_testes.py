import os
import subprocess
import time
import csv
import shutil

# Mapeamento dos 8 exercícios e seus respectivos nomes de arquivos .cpp
exercicios = {
    1: "busca_linear_iterativa",
    2: "busca_linear_recursiva",
    3: "busca_seq_alternativa_iterativa",
    4: "busca_seq_alternativa_recursiva",
    5: "busca_binaria_iterativa",
    6: "busca_binaria_recursiva",
    7: "busca_ternaria_iterativa",
    8: "busca_ternaria_recursiva"
}

# Tamanhos dos arrays gerados (de 5 em 5 até 3000)
tamanhos = list(range(5, 3001, 5))

# Quantidade de repetições exigidas para tirar a média no pior caso
n_repeticoes = 5

print("--- ETAPA 1: Verificando dependências e compilando os programas C++ ---")

# Verifica se o g++ está instalado no ambiente Linux/WSL
if not shutil.which("g++"):
    print("\n[ERRO CRÍTICO] O compilador 'g++' não foi encontrado no seu sistema.")
    print("Por favor, instale-o executando o comando:")
    print("  sudo apt update && sudo apt install build-essential -y\n")
    exit(1)

for num, nome in exercicios.items():
    cpp_file = f"{nome}.cpp"
    exe_file = f"./{nome}"
    
    if os.path.exists(cpp_file):
        try:
            # Compila o arquivo C++ gerando o executável correspondente
            subprocess.run(["g++", cpp_file, "-o", nome], check=True)
            print(f"Compilado com sucesso: {cpp_file}")
        except subprocess.CalledProcessError as e:
            print(f"Erro ao compilar o arquivo {cpp_file}: {e}")
            exit(1)
    else:
        print(f"[AVISO] O arquivo {cpp_file} não foi encontrado na pasta!")

print("\n--- ETAPA 2: Executando os testes empíricos (5 repetições por tamanho) ---")
resultados = []

for num, nome in exercicios.items():
    exe_file = f"./{nome}"
    
    for val in tamanhos:
        txt_file = f"testes/p{num}v{val}.txt"
        
        if not os.path.exists(txt_file):
            continue
        
        tempos_runs = []
        
        # Realiza as 5 repetições para o mesmo arquivo de teste
        for _ in range(n_repeticoes):
            with open(txt_file, "r") as f:
                # Mede o tempo de alta precisão do bloco de execução
                inicio = time.perf_counter()
                
                subprocess.run(
                    [exe_file],
                    stdin=f,
                    stdout=subprocess.DEVNULL,
                    stderr=subprocess.DEVNULL,
                    check=True
                )
                
                fim = time.perf_counter()
            
            duracao = fim - inicio
            tempos_runs.append(duracao)
        
        # Calcula a média das 5 execuções para mitigar flutuações do SO
        media_tempo = sum(tempos_runs) / n_repeticoes
        
        resultados.append({
            "exercicio": num,
            "algoritmo": nome,
            "tamanho_array": val,
            "media_tempo_segundos": media_tempo
        })
        
    print(f"-> Exercício {num} ({nome}) finalizado para todos os tamanhos.")

# --- ETAPA 3: Salvando os dados em uma tabela CSV ---
csv_filename = "resultados_tempos.csv"
with open(csv_filename, mode="w", newline="", encoding="utf-8") as csv_file:
    fieldnames = ["exercicio", "algoritmo", "tamanho_array", "media_tempo_segundos"]
    writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
    
    writer.writeheader()
    for linha in resultados:
        writer.writerow(linha)

print(f"\n[SUCESSO] Todos os testes foram concluídos e salvos na tabela '{csv_filename}'.")