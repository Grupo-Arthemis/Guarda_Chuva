![Logo (1)](https://github.com/Grupo-Arthemis/Sprint_3_Entrega_2_ECCS/assets/84590776/53732870-e1d1-4142-92f1-b8d91198a28c)

# Projeto Pé d'Água - Prevenção e Alerta de Alagamentos em São Paulo

## Descrição do Projeto:

O projeto "Pé d'Água" adota uma abordagem integrada na obtenção e análise de dados de chuva, visando monitorar padrões de precipitação em São Paulo. A implementação abrange a coleta de informações provenientes do sensor Guarda_Chuva e sua integração a um banco de dados centralizado, permitindo o registro e a análise de padrões de chuva em diversas localizações da cidade. A avaliação dos dados se baseia na consideração da quantidade de chuva em milímetros e sua duração, o que contribui para a avaliação do potencial de alagamento.

## Arquitetura do Projeto:

### Guarda_Chuva

O código é um sistema de contagem de milímetros de chuva, onde cada pêndulo realizado pelo pluviômetro tem um valor X que é adicionado a uma variável que armazena o total de chuva acumulada em um período definido pelo usuário.

O código também conecta o ESP32 à internet e envia todas as informações necessárias para o Tago.io, uma plataforma que permite visualizar e analisar os dados coletados pelo sensor.

*O código está comentado e pronto para ser modificado de acordo com a preferência do usuário*

### Frontend

**Web e Mobile:** Permite que os usuários visualizem mapas de risco de enchente, cadastrem-se para receber alertas e acessem informações detalhadas sobre os dados coletados, além de enviarem reports para o site sobre locais com enchentes.
- *O site:* [https://grupo-arthemis.github.io/Site_peDagua_React/](https://grupo-arthemis.github.io/Pe_Dagua_App/#/)

## Recursos Necessários:
Para executar este código, você vai precisar dos seguintes componentes:

- 1 sensor de temperatura e umidade DHT11
- 1 sensor magnético Reed Switch
- 1 placa de desenvolvimento ESP32
- 1 pluviômetro de báscula, que é um dispositivo que mede a precipitação pluviométrica por meio de um pêndulo que se inclina a cada volume de água acumulado.
- ![image](http://www.c2o.pro.br/proj/pluviometro/figuras/animacao_pluviometro_bascula.gif).
- 1 imã, que é usado para acionar o Reed Switch a cada movimento do pêndulo.

## Dependências:

O sucesso e eficácia do projeto "Pé d'Água" repousa sobre uma série de dependências que convergem para garantir a integridade das informações, a confiabilidade dos alertas e a satisfação dos usuários. A precisão das APIs de chuva é impactada pelas variáveis já que essas fontes primárias de dados viabilizam a avaliação dos riscos de alagamento. A qualidade e calibração do pluviômetro automatizado influenciam diretamente na confiabilidade das medições. A proteção contra vandalismo é essencial para preservar a funcionalidade dos dispositivos de medição. A manutenção contínua desses dispositivos e da plataforma online assegura informações atualizadas. A integridade das informações disponibilizadas, bem como o reconhecimento das limitações inerentes ao sistema, são cruciais para sustentar a confiança dos usuários e a credibilidade do projeto. Em resumo, a interdependência entre a qualidade dos dados, a funcionalidade dos dispositivos e a manutenção adequada é fundamental para a eficácia do projeto na prevenção e alerta de alagamentos em São Paulo.

## Conclusão:

Em síntese, o projeto "Pé d'Água" abraça uma abordagem integral para a obtenção e análise de dados de chuva, através da utilização de APIs, e sistemas IoT com dados em tempo real visando monitorar os padrões de precipitação em São Paulo, e nossa plataforma oferece uma interface interativa com mapas e notificações SMS, acessíveis após o cadastro dos usuários trabalhando Backend e Frontend.
