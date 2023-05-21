# Robozinho

Este é um projeto desenvolvido em 2023 para a aula de Objetos Inteligentes Conectados, oferecida pela Universidade Presbiteriana Mackenzie e ministrada pelo professor Marcelo T. de Azevedo, no último semestre do curso de Análise e Desenvolvimento de Sistemas.

Hardware necessário para o projeto:

  Protoboard
  ESP8266 (ou dispositívos que permitam conexão wifi)
  Sensor ultrassônico
  LED
  Resistor 220 Ohm
  Jumpers
  
Softwares necessários para rodar este projeto:
  
  Arduino IDE (ou a IDE de sua preferência)
  ThingSpeak (versão WEB)

Descrição do funcionamento:
  Ao enviar o código para a placa, o programa já fará sua primeira leitura, então recomenda-se que já esteja posicionado ou que o primeiro dado seja ignorado. O programa deve fazer a leitura da distância e, de acordo com o resultado, deverá piscar o LED referente aquela distância. É importante salientar que neste código, por estarmos utilizando o ESP8266, as portas são identificadas não pelo número escrito na placa, mas pelo seu GPIO, ou seja, caso selecione uma das portas e a mesma não retornar, verifique se está utilizando o padrão correto.
   No código estou utilizando as seguintes portas:
   
   D0 - 16 - LED vermelho
   D0 - 16 - LED vermelho
   D1 - 5 - Trig do sensor
   D2 - 4 - Echo do sensor
   D5 - 14 - LED verde
   D6 - 12 - LED verde
   D7 - 13 - LED azul
   D8 - 15 - LED azul
