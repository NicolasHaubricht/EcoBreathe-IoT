#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Configurações Wi-Fi e MQTT
const char* SSID = "Wokwi-GUEST"; // Nome da rede Wi-Fi
const char* PASSWORD = ""; // Senha do Wi-Fi
const char* BROKER_MQTT = "SEU IP"; // IP do Broker MQTT
const int BROKER_PORT = 1883; // Porta do Broker MQTT
const char* TOPICO_TEMP = "/TEF/id/attrs/t"; // Tópico MQTT para temperatura
const char* TOPICO_UMID = "/TEF/id/attrs/h"; // Tópico MQTT para umidade
const char* ID_MQTT = "id"; // ID do cliente MQTT

// Configurações do sensor DHT
#define DHTPIN 15 // Pino do DHT22
#define DHTTYPE DHT22 // Tipo do sensor DHT
DHT dht(DHTPIN, DHTTYPE); // Inicializa o sensor DHT

WiFiClient espClient; // Cliente Wi-Fi
PubSubClient MQTT(espClient); // Cliente MQTT

void setup() {
    Serial.begin(115200); // Inicializa o console serial
    dht.begin(); // Inicializa o sensor DHT
    connectWiFi(); // Conecta ao Wi-Fi
    MQTT.setServer(BROKER_MQTT, BROKER_PORT); // Configura o broker MQTT
}

void loop() {
    if (!MQTT.connected()) {
        reconnectMQTT(); // Reconecta ao MQTT se necessário
    }
    MQTT.loop(); // Mantém a conexão MQTT ativa

    float humidity = dht.readHumidity(); // Lê a umidade
    float temperature = dht.readTemperature(); // Lê a temperatura em Celsius

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Falha na leitura do DHT!");
    } else {
        Serial.print("Temperatura: ");
        Serial.print(temperature);
        Serial.print("°C, Umidade: ");
        Serial.print(humidity);
        Serial.println("%");

        // Publica os dados no broker MQTT
        MQTT.publish(TOPICO_TEMP, String(temperature).c_str());
        MQTT.publish(TOPICO_UMID, String(humidity).c_str());
    }
    delay(5000); // Aguarda 5 segundos antes da próxima leitura
}

void connectWiFi() {
    Serial.print("Conectando-se ao Wi-Fi ");
    Serial.println(SSID);
    WiFi.begin(SSID, PASSWORD); // Inicia a conexão Wi-Fi
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void reconnectMQTT() {
    while (!MQTT.connected()) {
        Serial.print("Conectando ao Broker MQTT...");
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado!");
        } else {
            Serial.print("Falha ao conectar. Código: ");
            Serial.println(MQTT.state());
            delay(2000); // Aguarda antes de tentar novamente
        }
    }
}

// Desenvolvido por Nicolas Haubricht Hainfellner