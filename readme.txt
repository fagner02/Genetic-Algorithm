Obs: Caso não queira compilar, siga apenas as instruções para execução.

Instruções para compilação:
Para compilar o código, é preciso baixar o msys(https://www.msys2.org/)
após baixar, abra o terminal msys2 msys e rode os seguintes comandos:
pacman -S mingw-w64-i686-gcc
pacman -S mingw-w64-i686-sfml
digite Y para instalar quando for perguntado pelo terminal, 
depois que tiver instalado as bibliotecas adicione a pasta C:\msys64\mingw32\bin nas variaveis de ambiente
depois execute o run.cmd, se a compilação for bem-sucedida, um main.exe será criado 

Instruções para execução:
Abra o main.exe
Para executar uma busca é só clicar em uma das opções na tela e escolher se quer usar
entradas aleatórias ou carregadas de um arquivo txt

Para executar os experimentos é necessário fornecer a quantidade correta de entradas pedida em cada experimento
Quando as buscas são executadas com entradas aleatórias, um arquivo txt é criado com as entradas que foram geradas

Obs: Na pasta include temos os arquivo .h que está sendo usado para declarar as funções, já na
pasta src temos os arquivos .cpp com a implementação das funções declaradas no .h. Na
main.cpp só tem a implementação da interface
