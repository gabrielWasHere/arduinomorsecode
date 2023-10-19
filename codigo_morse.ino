int botaoCodigo = 12; // Botão para digitar
int botaoPausa = 13; // Botão para marcar pausas
int estadoBC = LOW;
int ultimoestadoBC = LOW;
int estadoBP = LOW;
int ultimoestadoBP = LOW;

char morseMap[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

String morseCode[] = {
  "01eee" /*A*/, "1000e" /*B*/, "1010e" /*C*/, "100ee" /*D*/, "0eeee" /*E*/, "0010e" /*F*/, "110ee" /*G*/, "0000e" /*H*/, "00eee" /*I*/, "0111e" /*J*/, "101ee" /*K*/, "0100e" /*L*/, "11eee" /*M*/,
  "10eee" /*N*/, "111ee" /*O*/, "0110e" /*P*/, "1101e" /*Q*/, "010ee" /*R*/, "000ee" /*S*/, "1eeee" /*T*/, "001ee" /*U*/, "0001e" /*V*/, "011ee" /*W*/, "1001e" /*X*/, "1011e" /*Y*/, "1100e" /*Z*/,
  "11111" /*0*/, "01111" /*1*/, "00111" /*2*/, "00011" /*3*/, "00001" /*4*/, "00000" /*5*/, "10000" /*6*/, "11000" /*7*/, "11100" /*8*/, "11110" /*9*/
};

void setup() {
  pinMode(botaoCodigo, INPUT_PULLUP);
  pinMode(botaoPausa, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  estadoBP = digitalRead(botaoPausa);
  Serial.println(estadoBP);
  String resultado = "";

  if (estadoBP == HIGH){
    Serial.println("Entrando no Loop");
    delay(500);
    while(true){
      Serial.println("Aguardando letra");
      char array_lido[5] = {'e', 'e', 'e', 'e', 'e'};
      bool fim = false;
      bool espaco = false;
      for (int i = 0; i < 5; i++){
        unsigned long botaopressionado, botaosolto;
        while(true){
          estadoBC = digitalRead(botaoCodigo);
          estadoBP = digitalRead(botaoPausa);
          // Serial.println(estadoBC);
          if(estadoBP == HIGH){
            String array_atual = "";
            for (int i = 0; i < 5; i++){
              array_atual += array_lido[i];
            }
            if(array_atual == "eeeee"){
              Serial.println("Adicionando espaço");
              resultado += " ";
              espaco = true;
            }
            fim = true;
            break;
          }
          if(estadoBC == HIGH){
            break;
          }
        }
          if(fim == true){
            break;
          }
            Serial.println("Botão apertado!");
            botaopressionado = millis();

        while(true){
          estadoBC = digitalRead(botaoCodigo);
          //Serial.println(estadoBC);
          if(estadoBC == LOW){
            break;
          }
        }
            Serial.println("Botão solto!");
            botaosolto = millis();

        unsigned long duracao = botaosolto - botaopressionado;
        //Serial.println(duracao);
        if (duracao >= 500){
          array_lido[i] = '1';
          Serial.println("Dah");
        }else{
          array_lido[i] = '0';
          Serial.println("Dit");
        }
        //Serial.println(array_lido);
        /*for(int i = 0; i < 5; i++){
          Serial.println(array_lido[i]);
        }*/
        delay(250);
      }
        if(espaco == true){
          delay(250);
          continue;
        }
        String letra_atual = "";
        for (int i = 0; i < 5; i++){
          letra_atual += array_lido[i];
        }
        Serial.println("A string ficou:");
        Serial.println(letra_atual);
        //Serial.println("Parte do dicionario");
        for(int i = 0; i < 36; i++){
          if(morseCode[i] == letra_atual){
            Serial.println(morseMap[i]);
            resultado += morseMap[i];
            Serial.println("A string final esta:");
            Serial.println(resultado);
            delay(500);
            break;
          }
        }
    }
  }

  
}
