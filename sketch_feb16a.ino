const int A = 5;
const int B = 2;
const int C = 3;
const int D = 4;
const int AA = 6;
const int BB = 8;
const int CC = 9;
const int DD = 10;

const byte TRIGGER_PIN = 11; // Broche TRIGGER
const byte ECHO_PIN = 12;    // Broche ECHO
const int buzzer = 7;
const int distanceMax = 70;
int chiffre = 0;
int dix = 0;
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 50000UL; // 25ms = ~8m à 340m/s
/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;



void setup() {
  /* Initialise le port série */
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(DD, OUTPUT);
}

void loop() {

  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);

  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  /* Affiche les résultats en mm, cm et m */
  Serial.println(distance_mm);

  /* Détection de la balle */
  if (distance_mm > distanceMax) {
  }
  else if (distance_mm == 0) {
  }
  else {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    chiffre += 2;
    editNumber(chiffre);
    editNumber1(dix);

    delay(500);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
  }
  delay(1);

}

/* afficher le score partie 1 */
void editNumber(int x) {
  switch (x) {
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:

      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;

  }
  if (chiffre > 9) {
    dix += 1;
    chiffre = 0;
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }

}

/* afficher le score partie 2 */
void editNumber1(int x) {
  switch (x) {
    case 1:
      digitalWrite(AA, HIGH);
      digitalWrite(BB, LOW);
      digitalWrite(CC, LOW);
      digitalWrite(DD, LOW);
      break;
    case 2:
      digitalWrite(AA, LOW);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, LOW);
      digitalWrite(DD, LOW);
      break;
    case 3:
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, LOW);
      digitalWrite(DD, LOW);
      break;
    case 4:
      digitalWrite(AA, LOW);
      digitalWrite(BB, LOW);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, LOW);
      break;
    case 5:
      digitalWrite(AA, HIGH);
      digitalWrite(BB, LOW);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, LOW);
      break;
    case 6:
      digitalWrite(AA, LOW);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, LOW);
      break;
    case 7:
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, LOW);
      break;
    case 8:

      digitalWrite(AA, LOW);
      digitalWrite(BB, LOW);
      digitalWrite(CC, LOW);
      digitalWrite(DD, HIGH);
      break;
    case 9:
      digitalWrite(AA, HIGH);
      digitalWrite(BB, LOW);
      digitalWrite(CC, LOW);
      digitalWrite(DD, HIGH);
      break;

  }
  if (dix > 9) {
    dix = 0;
    digitalWrite(AA, LOW);
    digitalWrite(BB, LOW);
    digitalWrite(CC, LOW);
    digitalWrite(DD, LOW);
  }

}