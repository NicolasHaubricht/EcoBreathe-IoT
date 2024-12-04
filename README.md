# Projeto EcoBreathe | IoT

O projeto **EcoBreathe** utiliza o ESP32 como dispositivo IoT para monitorar e analisar condições ambientais, como temperatura e umidade. Os dados coletados são transmitidos via protocolo MQTT para um broker, permitindo o acesso e a análise em tempo real. Máquina Virtual utilizada AWS.

## 🚀 Funcionalidades

- Monitoramento de temperatura e umidade utilizando o sensor **DHT22**.
- Envio de dados via **MQTT** para um **broker**.
- Simulação de partículas PM10 e PM2.5 para fins visuais e analíticos.
- Comunicação com o servidor através de tópicos MQTT definidos.

## 🛠️ Tecnologias Utilizadas

- **ESP32**: Microcontrolador usado para leitura e envio de dados.
- **DHT22**: Sensor utilizado para medir temperatura e umidade.
- **MQTT**: Protocolo para comunicação eficiente entre dispositivos IoT.
- **Arduino IDE**: Ambiente de desenvolvimento utilizado para programar o ESP32.

## 🛜 Visualização Dados Históricos
- A visualização dos dados históricos é feita por dashboards. Para entender melhor acesse o link abaixo.
- Link: <a href='https://github.com/NicolasHaubricht/EcoBreathe-Dashboard'>Repositório Dashboards</a>

## 🖥️ Estrutura do Código

### 1. Configuração Wi-Fi e MQTT
O ESP32 conecta-se a uma rede Wi-Fi e configura o broker MQTT para transmitir os dados. As variáveis configuráveis incluem:
- `SSID`: Nome da rede Wi-Fi.
- `PASSWORD`: Senha da rede Wi-Fi.
- `BROKER_MQTT`: Endereço IP do broker MQTT.
- `BROKER_PORT`: Porta do broker MQTT.

### 2. Sensor DHT22
O sensor coleta dados de temperatura e umidade, processando os valores antes de enviá-los via MQTT.

### 3. Tópicos MQTT
Os tópicos definidos para o envio de dados são:
- **`/TEF/id/attrs/t`**: Para envio da temperatura.
- **`/TEF/id/attrs/h`**: Para envio da umidade.

### 4. Funções Principais
- **`connectWiFi()`**: Estabelece a conexão com a rede Wi-Fi.
- **`reconnectMQTT()`**: Garante a conexão com o broker MQTT.
- **`loop()`**: Realiza leituras do sensor e publica os dados no broker.

### 5. Arquitetura do Projeto
![Diagrama-Projeto](https://github.com/user-attachments/assets/87bab1fe-1961-4818-8e7b-e1605c5eb29f)


## 🖥️ Configuração do Ambiente

### 1. Pré-requisitos
- Instale a **Arduino IDE**.
- Instale as bibliotecas:
  - **WiFi** para conexão à rede.
  - **PubSubClient** para comunicação MQTT.
  - **DHT** para integração com o sensor DHT22.

### 2. Montagem
- Conecte o sensor **DHT22** ao pino **15** e as entradas VCC e GND ao ESP32.

![image](https://github.com/user-attachments/assets/7668bb35-1026-4fc6-b89e-6a24acc2655a)

- Configure o código com os valores da sua rede Wi-Fi e do broker MQTT.

## 🌐 Broker MQTT

O projeto utiliza um broker MQTT local. Substitua `SEU IP` no código pelo endereço IP do seu broker (IP público de sua máquina virtual).

## 🖥️ Mais Sobre o Projeto
- Fiware Descomplicado foi utilizado nesse projeto.
- Link: <a href='https://github.com/fabiocabrini/fiware'>Fiware Descomplicado</a>

### Desenvolvido por Nicolas Haubricht Hainfellner  
