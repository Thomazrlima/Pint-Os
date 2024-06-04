# Sistema de Threads com Sincronização 🧵

Bem-vindo ao repositório do sistema de threads com sincronização. Este repositório foi criado para armazenar e organizar o desenvolvimento de funcionalidades de sincronização em um sistema de threads, ampliando o entendimento dos problemas de sincronização em sistemas concorrentes.

## Estrutura do Repositório 📂

O repositório está organizado da seguinte maneira:

- **threads/**: Diretório principal onde a maior parte do desenvolvimento será feita.
- **devices/**: Diretório onde alguns ajustes adicionais podem ser necessários.

## Pré-requisitos 📚

Antes de iniciar a atividade, é recomendável a leitura dos seguintes documentos para uma melhor compreensão do projeto:

- `CodingStandards.pdf`
- `Threads.pdf`
- `TestingDebugging.pdf`
- `ThreadSwitching.pdf`
- Seções A.1, A.3 e A.5 de `A.ReferenceGuide.pdf`
- `B.4.4BSDScheduler.pdf`

## Sincronização 🔄

Para resolver problemas de sincronização, utilize semáforos, bloqueios e variáveis de condição em vez de desativar interrupções. Desativar interrupções só deve ser usado para coordenação de dados compartilhados entre um thread do kernel e um manipulador de interrupções.

Nos projetos Pint-OS, a única classe de problema resolvida pela desativação de interrupções é a coordenação de dados compartilhados entre um thread do kernel e um manipulador de interrupções. Como os manipuladores de interrupção não podem dormir, eles não podem adquirir bloqueios. Isso significa que os dados compartilhados entre os threads do kernel e um manipulador de interrupção devem ser protegidos dentro de um thread do kernel, desativando as interrupções.

## Alarm Clock ⏰

### Exercício 1: Implementação de `timer_sleep()`

A função `timer_sleep()`, definida em `devices/timer.c`, atualmente causa busy wait. O objetivo é apresentar uma nova implementação que evite o busy wait.

**Função:**

```c
void timer_sleep(int64_t ticks)
```

Suspende a execução da thread chamada até que o tempo tenha avançado em pelo menos x ticks do temporizador. A menos que o sistema esteja ocioso, a thread não precisa acordar após exatamente x ticks. Basta colocá-la na fila `ready` e esperar. `timer_sleep()` é útil para threads que operam em tempo real, por exemplo, para piscar o cursor uma vez por segundo.

### Dicas para Implementação 💡

- Leia os comentários em `lib/kernel/list.h` com atenção, pois o design/uso de lista é diferente da lista encadeada típica.
- Utilize primitivas de sincronização que fornecem funcionalidade de "espera" de thread. A leitura da seção A.3 do `A.ReferenceGuide.pdf` é suficiente.
- Verifique onde a variável `static ticks` é atualizada para decidir onde verificar se o tempo decorrido excedeu o tempo de suspensão.

## Como Contribuir 🤝

Se você é um aluno matriculado na disciplina, pode contribuir com este repositório da seguinte forma:

1. **Clonando o Repositório**: Comece clonando este repositório para sua máquina local usando o comando:
    ```bash
    git clone <URL-do-repositório>
    ```

2. **Criando uma Nova Atividade**: Para adicionar uma nova atividade, crie um novo diretório numerado dentro do diretório "threads". Nomeie o diretório de acordo com a numeração sequencial das atividades.

3. **Desenvolvendo a Atividade**: Coloque os arquivos da atividade no diretório criado. Isso pode incluir arquivos de código-fonte (.c), arquivos de cabeçalho (.h), scripts e quaisquer outros arquivos relevantes.

4. **Commit e Push**: Após concluir a atividade, faça commit das suas alterações e envie-as para o repositório:
    ```bash
    git add .
    git commit -m "Descrição das alterações"
    git push origin <nome-da-branch>
    ```

5. **Solicitando Pull Request**: No GitHub, abra um pull request para que o instrutor possa revisar e incorporar suas alterações no repositório principal.

## Dúvidas e Suporte ❓

Se tiver dúvidas específicas sobre as atividades ou encontrar problemas no código fornecido, sinta-se à vontade para abrir uma **Issue** neste repositório. Certifique-se de fornecer detalhes claros para que possamos ajudar você da melhor maneira possível.

Esperamos que este repositório seja uma ferramenta útil para aprimorar suas habilidades em programação de threads e aprofundar seus conhecimentos sobre sincronização em sistemas concorrentes. Boa codificação!
