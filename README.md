<p align="center">
  <img
    src="https://img.shields.io/badge/Status-Em%20desenvolvimento-green?style=flat-square"
    alt="Status"
  />
</p>

<p align="center">
  <img
    src="https://img.shields.io/github/repo-size/Thomazrlima/Udemy_Courses?style=flat"
    alt="Repository Size"
  />
  <img
    src="https://img.shields.io/github/languages/count/Thomazrlima/Udemy_Courses?style=flat&logo=python"
    alt="Language Count"
  />
  <img
    src="https://img.shields.io/github/commit-activity/t/Thomazrlima/Udemy_Courses?style=flat&logo=github"
    alt="Commit Activity"
  />
  <a href="LICENSE.md"
    ><img
      src="https://img.shields.io/github/license/Thomazrlima/Udemy_Courses"
      alt="License"
  /></a>
</p>

<p align="center">
  <img
    width="400"
    display="inline-block"
    src="https://media.geeksforgeeks.org/wp-content/uploads/ghant-chart.png"
  />
</p>

Bem-vindo ao repositório do sistema de threads com sincronização. Este repositório foi criado para armazenar e organizar o desenvolvimento de funcionalidades de sincronização em um sistema de threads, ampliando o entendimento dos problemas de sincronização em sistemas concorrentes.

## 📂 Estrutura do Repositório 

O repositório está organizado da seguinte maneira:

- **threads/**: Diretório principal onde a maior parte do desenvolvimento será feita.
- **devices/**: Diretório onde alguns ajustes adicionais podem ser necessários.

## 📚 Pré-requisitos 

- `CodingStandards.pdf`
- `Threads.pdf`
- `TestingDebugging.pdf`
- `ThreadSwitching.pdf`
- Seções A.1, A.3 e A.5 de `A.ReferenceGuide.pdf`
- `B.4.4BSDScheduler.pdf`

## 🔄 Sincronização 

Para resolver problemas de sincronização, utilize semáforos, bloqueios e variáveis de condição em vez de desativar interrupções. Desativar interrupções só deve ser usado para coordenação de dados compartilhados entre um thread do kernel e um manipulador de interrupções.

Nos projetos Pint-OS, a única classe de problema resolvida pela desativação de interrupções é a coordenação de dados compartilhados entre um thread do kernel e um manipulador de interrupções. Como os manipuladores de interrupção não podem dormir, eles não podem adquirir bloqueios. Isso significa que os dados compartilhados entre os threads do kernel e um manipulador de interrupção devem ser protegidos dentro de um thread do kernel, desativando as interrupções.

## ⏰ Alarm Clock 

### Exercício 1: Implementação de `timer_sleep()`

A função `timer_sleep()`, definida em `devices/timer.c`, atualmente causa busy wait. O objetivo é apresentar uma nova implementação que evite o busy wait.

**Função:**

```c
void timer_sleep(int64_t ticks)
```

Suspende a execução da thread chamada até que o tempo tenha avançado em pelo menos x ticks do temporizador. A menos que o sistema esteja ocioso, a thread não precisa acordar após exatamente x ticks. Basta colocá-la na fila `ready` e esperar. `timer_sleep()` é útil para threads que operam em tempo real, por exemplo, para piscar o cursor uma vez por segundo.

## 👨‍👩‍👧‍👦 Contribuintes
  
<a href="https://github.com/Thomazrlima/README.md-Templates/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Thomazrlima/README.md-Templates" />
</a>

## ⚖️ License

[MIT](https://github.com/Thomazrlima/Udemy_Courses/blob/master/LICENSE.md)
