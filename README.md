# Pedaleira Eletrônica para Processamento de Áudio

## Descrição
Este projeto consiste em uma pedaleira eletrônica experimental para processamento de sinais de áudio de instrumentos musicais com captação elétrica. O sistema realiza a amplificação, conversão analógico-digital e manipulação de sinais em tempo real, utilizando um microcontrolador ESP32.

## Funcionalidades
- Captura de sinal de áudio de instrumentos musicais
- Amplificação do sinal analógico
- Conversão analógico-digital
- Processamento digital do sinal
- Transmissão de dados via interface serial
- Reprodução do áudio processado em um programa Python

## Componentes Utilizados
- **Microcontrolador:** ESP32
- **Conversor ADC:** MCP3008
- **Amplificador:** MCP6024
- **Linguagem para reprodução:** Python

## Como Executar
1. **Montagem do Circuito:**
   - Conecte o ESP32 ao conversor ADC MCP3008
   - Utilize o amplificador MCP6024 para ajustar o sinal
   - Certifique-se de que os sinais de entrada e saída estejam corretamente conectados

2. **Programação do ESP32:**
   - Envie o firmware para o ESP32 usando a IDE Arduino ou o ESP-IDF
   - Configure a comunicação serial para transmissão do sinal digitalizado

3. **Execução no Computador:**
   - Execute o script Python para recepção e reprodução do áudio processado
   - Certifique-se de que a porta serial está configurada corretamente

## Possibilidades de Expansão
- Implementação de efeitos sonoros
- Melhoria na fidelidade do sinal processado
- Integração com pedais adicionais
- Otimização da transmissão para menor latência

## Autores
Projeto desenvolvido para aplicação dos conceitos de Arquitetura de Computadores e Sistemas Digitais.

## Licença
Este projeto é de caráter acadêmico e pode ser utilizado para fins educacionais e experimentais.
