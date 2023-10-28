![Logo (1)](https://github.com/Grupo-Arthemis/Sprint_3_Entrega_2_ECCS/assets/84590776/53732870-e1d1-4142-92f1-b8d91198a28c)

# Projeto Pé d'Água - Prevenção e Alerta de Alagamentos em São Paulo

## Descrição do Projeto:

O projeto "Pé d'Água" adota uma abordagem integrada na obtenção e análise de dados de chuva, visando monitorar padrões de precipitação em São Paulo. A implementação abrange a coleta de informações provenientes do sensor Guarda_Chuva e sua integração a um banco de dados centralizado, permitindo o registro e a análise de padrões de chuva em diversas localizações da cidade. A avaliação dos dados se baseia na consideração da quantidade de chuva em milímetros e sua duração, o que contribui para a avaliação do potencial de alagamento.

Além disso, o projeto incorpora a utilização do sensor de enchentes localizado em pontos estratégicos da cidade. Esse sensor, inspirado por um pluviômetro automatizado, opera em conjunto com a conectividade WiFi para transmitir informações em tempo real para o banco de dados central. Dentro desse repositório, as informações são submetidas a um processo de tratamento e análise, envolvendo o cruzamento de dados para a identificação de áreas de risco de alagamento.

Para proporcionar uma interface acessível aos usuários, o projeto oferece a visualização dos dados coletados por meio de um mapa interativo. Além disso, a plataforma emprega notificações via SMS para comunicar informações cruciais aos usuários. A participação na utilização do serviço é viabilizada por meio do cadastramento dos usuários, garantindo a disponibilidade em tempo real das funcionalidades oferecidas. Adicionalmente, a interação dos usuários é incentivada por meio da possibilidade de enviar relatórios pessoais, contribuindo para a identificação de novas localizações estratégicas para a instalação de sensores de enchentes.

## Arquitetura do Projeto:

### Dispositivos IoT:

- **Pluviômetro Automatizado:**  Ele consiste em um funil ou uma superfície coletora que direciona a água da chuva para um Pluviômetro de Báscula projetado especificamente para medir a quantidade de chuva que cai em uma área utilizando, e um imã que junto de um reed switch para captar a oscilação do pluviômetro assim calculando sua frequência relativa a chuva.

### Backend:

- **Integração:** Coleta dados do sensor IoT, e dos reports de usuário e realiza a análise dos dados para determinar o risco de enchentes.

- **Alertas:** Gera e envia alertas aos usuários cadastrados em caso de risco iminente de enchente via SMS.

- **Dados:** Armazena dados históricos de chuva e informações de sensores IoT para análises futuras e dados do usuário utilizando IA e Machine learning.

### Frontend:

- **Web e Mobile:** Permite que os usuários visualizem mapas de risco de enchente, cadastrem-se para receber alertas e acessem informações detalhadas sobre os dados coletados, além de enviarem reports para o site sobre locais com enchentes.

## Recursos Necessários:

### Dispositivos IoT:

- **Conexão de Dados:** Internet e conectividade via chip para transmitir os dados coletados para o backend.

- **Sistema de Sensor de Enchentes:** Pluviômetro de Báscula, localização disponível e Reed Switch .

### Backend:

- **Servidores:** Para hospedar os microsserviços de integração, alertas e dados.

- **Framework de Desenvolvimento:** Em uma linguagem adequada para desenvolver os microsserviços.

- **Banco de Dados:** Armazenamento dos dados históricos de chuva e informações dos sensores IoT.

### Frontend:

- **Interface de Mapa:** Integração com API de mapas para exibir dados de risco de enchente em um mapa interativo.

- **Autenticação:** Mecanismo de autenticação seguro para os usuários se cadastrarem e receberem alertas.

## Dependências:

O sucesso e eficácia do projeto "Pé d'Água" repousa sobre uma série de dependências que convergem para garantir a integridade das informações, a confiabilidade dos alertas e a satisfação dos usuários. A precisão das APIs de chuva é impactada pelas variáveis já que essas fontes primárias de dados viabilizam a avaliação dos riscos de alagamento. A qualidade e calibração do pluviômetro automatizado influenciam diretamente na confiabilidade das medições. A proteção contra vandalismo é essencial para preservar a funcionalidade dos dispositivos de medição. A manutenção contínua desses dispositivos e da plataforma online assegura informações atualizadas. A integridade das informações disponibilizadas, bem como o reconhecimento das limitações inerentes ao sistema, são cruciais para sustentar a confiança dos usuários e a credibilidade do projeto. Em resumo, a interdependência entre a qualidade dos dados, a funcionalidade dos dispositivos e a manutenção adequada é fundamental para a eficácia do projeto na prevenção e alerta de alagamentos em São Paulo.

## Conclusão:

Em síntese, o projeto "Pé d'Água" abraça uma abordagem integral para a obtenção e análise de dados de chuva, através da utilização de APIs, e sistemas IoT com dados em tempo real visando monitorar os padrões de precipitação em São Paulo, e nossa plataforma oferece uma interface interativa com mapas e notificações SMS, acessíveis após o cadastro dos usuários trabalhando Backend e Frontend.

## Vídeo Pitch:
https://youtu.be/Tf3k8Cagf3Y
