def string_input(message):
    """
    Solicita ao usuário uma string contendo apenas letras.

    Parâmetros:
        message (str): Mensagem exibida ao solicitar a entrada do usuário.

    Retorna:
        str: Uma string não vazia contendo apenas caracteres alfabéticos.
    """
    assert message != ""

    while True:
        buffer = input(message).strip()

        if buffer and buffer.isalpha():
            return buffer

        print("[ERROR]: Digite apenas letras.")


def float_input(message):
    """
    Solicita ao usuário uma nota no formato float, entre 0.0 e 10.0.

    Parâmetros:
        message (str): Mensagem exibida ao solicitar a entrada do usuário.

    Retorna:
        float: Um número decimal entre 0.0 e 10.0 representando a nota.
    """
    assert message != ""

    while True:
        try:
            value = float(input(message).strip())
            if 0.0 <= value <= 10.0:
                return value

            print("[ERROR]: Nota fora do intervalo indicado.")

        except ValueError:
            print("[ERROR]: Digite apenas números.")


def main():
    dict_alunos = {}
    dict_alunos_aprovados = {}
    nome_aluno = ""

    nota_aluno = 0.0

    for i in range (10):
        while(True):
            nome_aluno = string_input("Digite o nome do aluno: ")

            if dict_alunos.get(nome_aluno) != None:
                print("[ERROR]: Aluno já cadastrado.")
                continue

            nota_aluno = float_input("Digite a nota do aluno ( 0 - 10): ")

            break

        dict_alunos.update({nome_aluno: nota_aluno})

        if nota_aluno >= 6.0:
            dict_alunos_aprovados.update({nome_aluno:nota_aluno})

    print("[INFO]: Dicionário de alunos cadastrados >>", dict_alunos)
    print("[INFO]: Dicionário de alunos com média maior ou igual a seis >>",
          dict_alunos_aprovados)


if __name__ == '__main__':
    main()

